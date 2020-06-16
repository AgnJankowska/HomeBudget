#ifndef IncomesFile_H
#define IncomesFile_H
#include <iostream>
#include <vector>
#include "Markup.h"
#include "Income.h"
#include "SubsidiaryMethods.h"

using namespace std;

class IncomesFile
    {
    const string NAME_OF_INCOMES_FILE;

public:
    IncomesFile (string nameOfIncomesFile) : NAME_OF_INCOMES_FILE(nameOfIncomesFile) {};

    int getIdOfLastIncome();
    void saveIncomeToFile (Income income);
    vector <Income> loadIncomesFromFile (int ID_ZALOGOWANEGO_UZYTKOWNIKA);

    };
#endif

