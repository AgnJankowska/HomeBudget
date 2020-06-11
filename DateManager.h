#ifndef DateManager_H
#define DateManager_H
#include <iostream>
#include <windows.h>
#include <winbase.h>

#include "Date.h"
#include "SubsidiaryMethods.h"

using namespace std;

class DateManager
    {
public:
    string selectDateOfIncomeOrExpense();

private:
    string getCurrentDate();

    bool isTheGivenDateCorrect(string dateInFullFormat);
    bool isThisYearLeap(Date date);
    int checkNumberOfDays (Date date);


    };
#endif
