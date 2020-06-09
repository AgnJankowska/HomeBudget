#include "DateManager.h"

string DateManager::selectDateOfIncomeOrExpense() {

    string dateInFullFormat = "";
    char choice = {0};
    cout << endl;
    cout << "Podaj date (1.Dzien dzisiejszy / 2.Inny dzien). Wybor: ";

    do
    {
        choice = SubsidiaryMethods::getCharacter();
        switch (choice) {
            case '1': {
                dateInFullFormat = getCurrentDate();
                }
            break;
            case '2': {
                cout << "Podaj date (format rrrr-mm-dd): ";
                cin >> dateInFullFormat;
                while (!isTheGivenDateCorrect(dateInFullFormat))
                {
                    cout << endl;
                    cout << "Podana data jest niepoprawna." << endl;
                    cout << "Podaj date (format rrrr-mm-dd): ";
                    cin >> dateInFullFormat;
                }
                }
            break;
            default: {
                cout << "Podaj poprawna wartosc: ";
                }
            break;
        }
    }
    while ((choice != '1') && (choice != '2'));
    return dateInFullFormat;
}

string DateManager::getCurrentDate()
{
    SYSTEMTIME st;
    GetLocalTime(&st);

    int yearInt = st.wYear;
    int monthInt = st.wMonth;
    int dayInt = st.wDay;

    string year = SubsidiaryMethods::conversionIntegerToString(yearInt);
    string month = SubsidiaryMethods::conversionIntegerToString(monthInt);
    string day = SubsidiaryMethods::conversionIntegerToString(dayInt);

    if (monthInt < 10)
        month = "0" + month;

    if (dayInt < 10)
        day = "0" + day;

    return (year+"-"+month+"-"+day);
}

bool DateManager::isThisYearLeap(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    return true;
  else
    return false;
}

int DateManager::checkNumberOfDays (int year, int month)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        return 31;
    }

    case 4:
    case 6:
    case 9:
    case 11:
    {
        return 30;
    }

    case 2:
    {
        if (isThisYearLeap(year))   return 29;
        else                        return 28;
    }
    }
    return 0;
}

int DateManager::getYear (string date)
{
    char sign = '-';
    size_t position = date.find(sign);
    string year = date.substr(0,position+1);

    return SubsidiaryMethods::conversionStrintToInteger(year);
}

int DateManager::getMonth (string date)
{
    char sign = '-';
    size_t position = date.find(sign);
    size_t position2 = date.find(sign, position+1);

    string month = date.substr(position+1,position2+1);

    return SubsidiaryMethods::conversionStrintToInteger(month);
}

int DateManager::getDay (string date)
{
    char sign = '-';
    size_t position = date.find(sign);
    size_t position2 = date.find(sign, position+1);

    string day = date.substr(position2+1, 2);

    return SubsidiaryMethods::conversionStrintToInteger(day);
}

bool DateManager::isTheGivenDateCorrect (string date) {

    int year = getYear (date);
    int month = getMonth (date);
    int day = getDay (date);

    if (year >= 1900)
    {
        if (month >= 1 && month <=12)
        {
            int numberOfDaysInMonth = checkNumberOfDays(year, month);
            if (day >= 1 && day <= numberOfDaysInMonth)
                return true;
        }
    }
    return false;
}
