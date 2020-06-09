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
    int getYear (string date);
    int getMonth (string date);
    int getDay (string date);

    bool isTheGivenDateCorrect(string dateInFullFormat);
    bool isThisYearLeap(int year);
    int checkNumberOfDays (int year, int month);


    };
#endif
