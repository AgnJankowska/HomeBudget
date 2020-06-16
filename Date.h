#ifndef Date_H
#define Date_H
#include <iostream>
# include "SubsidiaryMethods.h"
using namespace std;

class Date
{
    int year;
    int month;
    int day;

public:
    Date (int year = 0, int month = 0, int day = 0)
    {
        this -> year = year;
        this -> month = month;
        this -> day = day;
    }

    void setYear (string date);
    void setMonth (string date);
    void setDay (string date);

    int getYear ();
    int getMonth ();
    int getDay ();
};
#endif
