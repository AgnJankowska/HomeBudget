#ifndef BalanceManager_H
#define BalanceManager_H
#include <iostream>
#include <vector>
#include <cstdlib>

#include "DateManager.h"
#include "Income.h"
#include "Expense.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"

using namespace std;

class BalanceManager
    {
    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    DateManager dateManager;
    vector <Income> sortedIncomes;
    vector <Expense> sortedExpenses;

    const int ID_OF_SIGNED_IN_USER;

public:
    BalanceManager (string nameOfIncomesFile, string nameOfExpensesFile, int userId)
    : incomesFile (nameOfIncomesFile), expensesFile (nameOfExpensesFile), ID_OF_SIGNED_IN_USER (userId)  {};

public:

    void displayBalanceFromCurrentMonth();
    void displayBalanceFromPreviousMonth();
    void displayBalanceFromDesignedTime();

private:
    void displayBalance(string beginingDateOfRange, string endingDateOfRange);
    vector <Income> sortVectorOfIncomes ();
    vector <Expense> sortVectorOfExpenses ();
    struct sortIncomeDate;
    struct sortExpenseDate;
    bool isIncomeWithinRange(Income income, int beginingDateOfRangeInt, int endingDateOfRangeInt);
    bool isExpenseWithinRange(Expense expense, int beginingDateOfRangeInt, int endingDateOfRangeInt);
    };

#endif
