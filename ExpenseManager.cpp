#include "ExpenseManager.h"

Expense ExpenseManager::enterNewExpenseData(){

    Expense expense;

    expense.setUserId(ID_OF_SIGNED_IN_USER);
    expense.setExpenseId(expensesFile.getIdOfLastExpense()+1);

    string date = dateManager.selectDateOfIncomeOrExpense();
    expense.setDate(date);

    cout << "Podaj krotki opis: ";
    expense.setCategory(SubsidiaryMethods::getLine());

    cout << "Podaj kwote: ";
    expense.setAmount(SubsidiaryMethods::getFloatingNumberWithDot());

    return expense;
}

void ExpenseManager::addExpense(){

    Expense expense = enterNewExpenseData();

    expenses.push_back(expense);
    expensesFile.saveExpenseToFile(expense);

    displayAddedExpense(expense);
    system("pause");
}

void ExpenseManager::displayAddedExpense(Expense expense){

    system("cls");
    cout << "-- Zapisana pozycja wydatku --" << endl;
    cout << endl;
    cout << "Data: " << expense.getDate() << endl;
    cout << "Opis: " << expense.getCategory() << endl;
    cout << "Kwota: " << expense.getAmount() << " zl."<< endl;

    cout  << endl;

    cout << "ID wydatku: " << expense.getExpenseId() << endl;
    cout << "ID usera: " << expense.getUserId() << endl;
}


