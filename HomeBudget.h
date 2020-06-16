#ifndef HomeBudget_H
#define HomeBudget_h
#include <iostream>

#include "UserManager.h"
#include "BalanceManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "SubsidiaryMethods.h"

using namespace std;

class HomeBudget
{
private:
    UserManager userManager;
    BalanceManager *balanceManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    const string NAME_OF_INCOMES_FILE;
    const string NAME_OF_EXPENSES_FILE;

public:
    HomeBudget (string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses) : userManager(nameOfFileWithUsers), NAME_OF_INCOMES_FILE(nameOfFileWithIncomes), NAME_OF_EXPENSES_FILE(nameOfFileWithExpenses)
    {
        incomeManager = NULL;
        expenseManager = NULL;
        balanceManager = NULL;
    };

    ~HomeBudget()
    {
        delete incomeManager;
        delete expenseManager;
        delete balanceManager;
        incomeManager = NULL;
        expenseManager = NULL;
        balanceManager = NULL;
    };

    void registration();
    void singIn();
    void changePassword();
    void logOut();

    char selectOptionFromMainMenu();
    char selectOptionFromMenuForSignedInUsers();
    bool isUserSignedIn();
    void displayBalanceFromCurrentMonth();
    void displayBalanceFromPreviousMonth();
    void displayBalanceFromDesignedTime ();

    void addIncome();
    void addExpense();
};
#endif
