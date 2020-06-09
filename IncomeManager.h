#ifndef IncomeManager_H
#define IncomeManager_H
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>

#include "IncomesFile.h"
#include "Income.h"
#include "DateManager.h"
#include "UserManager.h"

using namespace std;

class IncomeManager
    {
private:
    IncomesFile incomesFile;
    DateManager dateManager;

    const int ID_OF_SIGNED_IN_USER;
    vector <Income> incomes;

public:
    IncomeManager (string nameOfIncomesFile, int userId)
    : incomesFile (nameOfIncomesFile), ID_OF_SIGNED_IN_USER (userId)
    {
        //incomes = incomesFile.loadIncomesOfSignedInUser(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void addIncome();

private:
    void addIncomeToIncomesFile(Income income);
    int getIdOfSignedInUser();
    void displayAddedIncome(Income income);
    Income enterNewIncomeData();

    };
#endif
