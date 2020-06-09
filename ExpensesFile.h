#ifndef IncomesFile_H
#define IncomesFile_H
#include <iostream>
#include <vector>

#include "Markup.h"
#include "CashFlowFile.h"
#include "Income.h"
#include "SubsidiaryMethods.h"

using namespace std;

class IncomesFile : public CashFlowFile
    {
    vector <Income> incomes;
    const string NAME_OF_INCOME_FILE;

public:
    IncomesFile (string nameOfIncomesFile) : NAME_OF_INCOME_FILE(nameOfIncomesFile) {};

    int getIdOfLastIncome();
    void saveIncomeToFile (Income income);
    void saveAllIncomesToFile ();
    void loadIncomesFromFile ();

    };
#endif

