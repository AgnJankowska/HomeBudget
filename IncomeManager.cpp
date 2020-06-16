#include "IncomeManager.h"

Income IncomeManager::enterNewIncomeData(){

    Income income;

    income.setUserId(ID_OF_SIGNED_IN_USER);
    income.setIncomeId(incomesFile.getIdOfLastIncome()+1);

    string date = dateManager.selectDateOfIncomeOrExpense();
    income.setDate(date);
    income.setDateInt(date);

    cout << "Podaj krotki opis: ";
    income.setCategory(SubsidiaryMethods::getLine());

    cout << "Podaj kwote: ";
    income.setAmount(SubsidiaryMethods::getFloatingNumberWithDot());

    return income;
}

void IncomeManager::addIncome(){

    Income income = enterNewIncomeData();

    incomes.push_back(income);
    incomesFile.saveIncomeToFile(income);

    displayAddedIncome(income);
    system("pause");
}

void IncomeManager::displayAddedIncome(Income income){

    system("cls");
    cout << "-- Zapisana pozycja przychodu --" << endl;
    cout << endl;
    cout << "Data: " << income.getDate() << endl;
    cout << "Opis: " << income.getCategory() << endl;
    cout << "Kwota: " << income.getAmount() << " zl."<< endl;

    cout  << endl;

    cout << "ID wplywu: " << income.getIncomeId() << endl;
    cout << "ID usera: " << income.getUserId() << endl;
}

