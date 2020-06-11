#ifndef Expense_H
#define Expense_H
#include <iostream>
#include "CashFlow.h"

using namespace std;

class Expense : public CashFlow
    {
    int expenseId;

public:
    Expense (int expenseId=0)
    {
        this -> expenseId = expenseId;
    }

    void setExpenseId (int newExpenseId);
    int getExpenseId ();

    };
#endif
