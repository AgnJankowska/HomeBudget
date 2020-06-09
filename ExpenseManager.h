#ifndef ExpenseManager_H
#define ExpenseManager_H
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>

#include "ExpensesFile.h"
#include "Expense.h"
#include "DateManager.h"
#include "UserManager.h"

using namespace std;

class ExpenseManager
    {
private:
    ExpensesFile expensesFile;
    DateManager dateManager;

    const int ID_OF_SIGNED_IN_USER;
    vector <Expense> expenses;

public:
    ExpenseManager (string nameOfExpensesFile, int userId)
    : expensesFile (nameOfExpensesFile), ID_OF_SIGNED_IN_USER (userId)
    {
        //expenses = expensesFile.loadExpensesOfSignedInUser(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void addExpense();

private:
    void addExpenseToExpensesFile(Expense expense);
    int getIdOfSignedInUser();
    void displayAddedExpense(Expense expense);
    Expense enterNewExpenseData();
    };

#endif
