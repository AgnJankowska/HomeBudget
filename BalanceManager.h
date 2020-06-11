#ifndef BalanceManager_H
#define BalanceManager_H
#include <iostream>
//#include <windows.h>
//#include <winbase.h>

//#include "Date.h"
//#include "SubsidiaryMethods.h"

//#include "DateManager.h"
//#include "IncomeManager.h"
//#include "ExpenseManager.h"

using namespace std;

class BalanceManager
    {
    //DateManager dateManager;
    //IncomeManager incomeManager;
    //ExpenseManager expenseManager;

    const int ID_OF_SIGNED_IN_USER;
    //vector <Expense> expenses;

public:
    BalanceManager (int userId) : ID_OF_SIGNED_IN_USER (userId) {};

public:
    void displayBalanceFromCurrentMonth();
    void displayBalanceFromPreviousMonth();
    void displayBalanceFromDesignedTime();

private:


    };
#endif
