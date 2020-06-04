#include "UserManager.h"

void UserManager::registration() {
    User user = enterNewUserData();

    users.push_back(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::enterNewUserData() {
    User user;
    user.setId(getNewUserId());

    string login;
    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);

    } while (isLoginExist(user.getLogin()) == true);

    string firstName;
    string secondName;
    string password;

    cout << "Podaj imie: ";
    cin >> firstName;

    cout << "Podaj nazwisko: ";
    cin >> secondName;

    cout << "Podaj haslo: ";
    cin >> password;

    user.setFirstName(firstName);
    user.setSecondName(secondName);
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExist(string login) {
    for (int i=0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

/*
void UzytkownikManager::wypiszWszystkichUzytkownikow() {
    for (int i=0; i < uzytkownicy.size(); i++) {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}
*/

int UserManager::singIn() {
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int amountOfAttemps = 3; amountOfAttemps > 0; amountOfAttemps--) {
                cout << "Podaj haslo. Pozostalo prob: " << amountOfAttemps << ": ";
                password = SubsidiaryMethods::getLine();

                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    IdOfSignedIndUser = itr -> getId();
                    return IdOfSignedIndUser;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

/*
int UzytkownikManager::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}


void UzytkownikManager::zapiszWszystkichUzytkownikowDoPliku() {
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
*/

void UserManager::changePassword() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = SubsidiaryMethods::getLine();

    for (int i=0; i<users.size(); i++) {
        if (users[i].getId() == IdOfSignedIndUser) {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    //zapiszWszystkichUzytkownikowDoPliku();
}

void UserManager::logOut() {
    IdOfSignedIndUser = 0;
}

bool UserManager::isUserSignedIn() {
    if (IdOfSignedIndUser > 0)
        return true;
    else
        return false;
}


