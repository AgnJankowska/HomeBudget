#include "HomeBudget.h"

char HomeBudget::selectOptionFromMainMenu() {
    char choice;
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SubsidiaryMethods::getCharacter();

    return choice;
}

char HomeBudget::selectOptionFromMenuForSignedInUsers() {
    char choice;
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SubsidiaryMethods::getCharacter();

    return choice;
}

bool HomeBudget::isUserSignedIn() {
    return userManager.isUserSignedIn();
}

void HomeBudget::registration() {
    userManager.registration();
}

void HomeBudget::singIn() {
    userManager.singIn();
    if (userManager.isUserSignedIn()) {
    incomeManager = new IncomeManager(NAME_OF_INCOMES_FILE, userManager.getIdOfSignedInUser());
    expenseManager = new ExpenseManager(NAME_OF_EXPENSES_FILE, userManager.getIdOfSignedInUser());
    balanceManager = new BalanceManager(NAME_OF_INCOMES_FILE, NAME_OF_EXPENSES_FILE, userManager.getIdOfSignedInUser());
    }
}

void HomeBudget::changePassword() {
    userManager.changePassword();
}

void HomeBudget::logOut() {
    userManager.logOut();
}

void HomeBudget::addIncome(){
    incomeManager -> addIncome();
}

void HomeBudget::addExpense(){
    expenseManager -> addExpense();
}

void HomeBudget::displayBalanceFromCurrentMonth(){
     balanceManager -> displayBalanceFromCurrentMonth();
}

void HomeBudget::displayBalanceFromPreviousMonth(){
     balanceManager -> displayBalanceFromPreviousMonth();
}

void HomeBudget::displayBalanceFromDesignedTime(){
     balanceManager -> displayBalanceFromDesignedTime();
}
