#ifndef IncomeManager_H
#define IncomeManager_h
#include <iostream>
#include <vector>

#include "IncomesFile.h"
#include "Income.h"
//#include "SubsidiaryMethods.h"

using namespace std;

class IncomeManager
    {
private:
    IncomesFile incomesFile;
    vector <Income> incomes;
    int IdOfSignedIndUser;

public:
    void addIncome();

    };
#endif
