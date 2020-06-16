#include "Date.h"

int Date::getYear (){
    return year;
}

int Date::getMonth (){
    return month;
}

int Date::getDay (){
    return day;
}

void Date::setYear (string date)
{
    char sign = '-';
    size_t position = date.find(sign);
    year = SubsidiaryMethods::conversionStrintToInteger(date.substr(0,position+1));
}

void Date::setMonth (string date)
{
    char sign = '-';
    size_t position = date.find(sign);
    size_t position2 = date.find(sign, position+1);
    month = SubsidiaryMethods::conversionStrintToInteger(date.substr(position+1,position2+1));
}

void Date::setDay (string date)
{
    char sign = '-';
    size_t position = date.find(sign);
    size_t position2 = date.find(sign, position+1);
    day = SubsidiaryMethods::conversionStrintToInteger(date.substr(position2+1, 2));
}
