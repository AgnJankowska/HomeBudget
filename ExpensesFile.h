#ifndef ExpensesFile_H
#define ExpensesFile_H
#include <iostream>
#include <vector>

#include "Markup.h"
#include "Expense.h"
#include "SubsidiaryMethods.h"

using namespace std;

class ExpensesFile
    {
    vector <Expense> expenses;
    const string NAME_OF_EXPENSES_FILE;

public:
    ExpensesFile (string nameOfExpensesFile) : NAME_OF_EXPENSES_FILE(nameOfExpensesFile) {};

    int getIdOfLastExpense();
    void saveExpenseToFile (Expense expense);
    vector <Expense> loadExpensesFromFile (int ID_ZALOGOWANEGO_UZYTKOWNIKA);


    };
#endif

