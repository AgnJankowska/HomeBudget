#include <iostream>
#include "HomeBudget.h"
using namespace std;

int main()
{
    HomeBudget homeBudget("Users.xml", "Income.xml", "Expense.xml");
    char userChoice;
    while (true) {
        if (homeBudget.isUserSignedIn() == false) {
            userChoice = homeBudget.selectOptionFromMainMenu();

            switch (userChoice) {
            case '1':
                homeBudget.registration();
                break;
            case '2':
                homeBudget.singIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }

        else {
            userChoice = homeBudget.selectOptionFromMenuForSignedInUsers();

            switch (userChoice) {
            case '1':
                homeBudget.addIncome();
                break;
            case '2':
                homeBudget.addExpense();
                break;
            case '3':
                homeBudget.displayBalanceFromCurrentMonth();
                break;
            case '4':
                homeBudget.displayBalanceFromPreviousMonth();
                break;
            case '5':
                homeBudget.displayBalanceFromDesignedTime();
                break;
            case '6':
                homeBudget.changePassword();
                break;
            case '7':
                homeBudget.logOut();
                break;
            }
        }
    }

    return 0;
}
