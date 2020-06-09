#ifndef Income_H
#define Income_H
#include <iostream>
#include "CashFlow.h"

using namespace std;

class Income : public CashFlow
    {
    int incomeId;

public:
    Income (int incomeId=0)
    {
        this -> incomeId = incomeId;
    }

    void setIncomeId (int newIncomeId);
    int getIncomeId ();

    };
#endif
