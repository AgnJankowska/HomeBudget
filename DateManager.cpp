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

bool DateManager::isThisYearLeap(Date date) {
  if ((date.getYear() % 4 == 0 && date.getYear() % 100 != 0) || date.getYear() % 400 == 0)
    return true;
  else
    return false;
}

int DateManager::checkNumberOfDays (Date date)
{
    switch (date.getMonth())
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
        if (isThisYearLeap(date))   return 29;
        else                                return 28;
    }
    }
    return 0;
}

bool DateManager::isTheGivenDateCorrect (string dateInFullFormat) {

    Date date;
    date.setYear (dateInFullFormat);
    date.setMonth (dateInFullFormat);
    date.setDay (dateInFullFormat);

    if (date.getYear() >= 1900)
    {
        if (date.getMonth() >= 1 && date.getMonth() <=12)
        {
            int numberOfDaysInMonth = checkNumberOfDays(date);
            if (date.getDay() >= 1 && date.getDay() <= numberOfDaysInMonth)
                return true;
        }
    }
    return false;
}
