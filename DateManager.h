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
    string selectDate();
    string getCurrentDate();

    string getBeginningOfCurrentMonthDate();
    string getEndOfCurrentMonthDate();
    string getBeginningOfPreviousMonthDate();
    string getEndOfPreviousMonthDate();
    bool isEndingAfterBegining(string beginingDateOfRange, string endingDateOfRange);

private:
    int convertDateFromStringToInteger (string dateInFullFormat);
    bool isTheGivenDateCorrect(string dateInFullFormat);
    bool isThisYearLeap(Date date);
    int checkNumberOfDays (Date date);


    };
#endif
