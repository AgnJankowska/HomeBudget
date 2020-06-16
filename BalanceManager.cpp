#include "BalanceManager.h"

void BalanceManager::displayBalance(string beginingDateOfRange, string endingDateOfRange)
{
    int beginingDateOfRangeInt = SubsidiaryMethods::switchDateInFullFormatToInteger(beginingDateOfRange);
    int endingDateOfRangeInt = SubsidiaryMethods::switchDateInFullFormatToInteger(endingDateOfRange);
    float sumOfIncomes = 0.00;
    float sumOfExpenses = 0.00;

    sortedIncomes = sortVectorOfIncomes();
    sortedExpenses = sortVectorOfExpenses();
    system("cls");

    cout << "-----WPLYWY-----" << endl;
    for (int i=0; i<sortedIncomes.size(); i++){
        if(isIncomeWithinRange(sortedIncomes[i], beginingDateOfRangeInt, endingDateOfRangeInt)){
            cout << "Data: " << sortedIncomes[i].getDate() << ", kwota: " << sortedIncomes[i].getAmount() << ", opis: " << sortedIncomes[i].getCategory() <<endl;
            sumOfIncomes += sortedIncomes[i].getAmount();
        }
    }
    cout << endl << "-----WYDATKI-----" << endl;
    for (int i=0; i<sortedExpenses.size(); i++){
        if(isExpenseWithinRange(sortedExpenses[i], beginingDateOfRangeInt, endingDateOfRangeInt)){
            cout << "Data: " << sortedExpenses[i].getDate() << ", kwota: " << sortedExpenses[i].getAmount() << ", opis: " << sortedExpenses[i].getCategory() <<endl;
            sumOfExpenses += sortedExpenses[i].getAmount();
        }
    }

    cout << endl << "-----SALDO-----" << endl;
    cout << "Suma wplywow: " << sumOfIncomes << " zl." << endl;
    cout << "Suma wydatkow: " << sumOfExpenses << " zl." << endl ;;
    cout << "Bilans ze wskazanego okresu: " << sumOfIncomes - sumOfExpenses << " zl." << endl;
    getchar();
}

void BalanceManager::displayBalanceFromCurrentMonth(){
    string beginingDateOfRange = dateManager.getBeginningOfCurrentMonthDate();
    string endingDateOfRange = dateManager.getEndOfCurrentMonthDate();

    displayBalance(beginingDateOfRange, endingDateOfRange);
}

void BalanceManager::displayBalanceFromPreviousMonth(){
    string beginingDateOfRange = dateManager.getBeginningOfPreviousMonthDate();
    string endingDateOfRange = dateManager.getEndOfPreviousMonthDate();

    displayBalance(beginingDateOfRange, endingDateOfRange);
}

void BalanceManager::displayBalanceFromDesignedTime(){
    cout << "Wskaz poczatek zakresu: ";
    string beginingDateOfRange = dateManager.selectDate();
    cout << endl << "Wskaz koniec zakresu: ";
    string endingDateOfRange = dateManager.selectDate();
    if(dateManager.isEndingAfterBegining(beginingDateOfRange, endingDateOfRange)) {
        displayBalance(beginingDateOfRange, endingDateOfRange);
    }
    else {
        cout << "Wskazany zakres jest niepoprawny!" << endl << endl;
        displayBalanceFromDesignedTime();
    }
}

struct BalanceManager::sortIncomeDate {
    inline bool operator () (Income& income1, Income& income2 )
    {
        return (income1.getDateInt() < income2.getDateInt());
    }
};

struct BalanceManager::sortExpenseDate {
    inline bool operator () (Expense& expense1, Expense& expense2 )
    {
        return (expense1.getDateInt() < expense2.getDateInt());
    }
};

vector <Income> BalanceManager::sortVectorOfIncomes (){

    sortedIncomes = incomesFile.loadIncomesFromFile(ID_OF_SIGNED_IN_USER);

    sort(sortedIncomes.begin(), sortedIncomes.end(), sortIncomeDate ());
    return sortedIncomes;
}

vector <Expense> BalanceManager::sortVectorOfExpenses (){

    sortedExpenses = expensesFile.loadExpensesFromFile(ID_OF_SIGNED_IN_USER);

    sort(sortedExpenses.begin(), sortedExpenses.end(), sortExpenseDate ());
    return sortedExpenses;
}

bool BalanceManager::isIncomeWithinRange(Income income, int beginingDateOfRangeInt, int endingDateOfRangeInt){
    if((income.getDateInt() <= endingDateOfRangeInt)&&(income.getDateInt() >= beginingDateOfRangeInt))
        return true;
    else
        return false;
}

bool BalanceManager::isExpenseWithinRange(Expense expense, int beginingDateOfRangeInt, int endingDateOfRangeInt){
    if((expense.getDateInt() <= endingDateOfRangeInt)&&(expense.getDateInt() >= beginingDateOfRangeInt))
        return true;
    else
        return false;
}
