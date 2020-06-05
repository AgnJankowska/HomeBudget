#include "UserManager.h"

int UserManager::getIdOfSignedInUser() {
    return IdOfSignedIndUser;
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
    firstName = SubsidiaryMethods::switchFirstLetterToCapital(firstName);

    cout << "Podaj nazwisko: ";
    cin >> secondName;
    secondName = SubsidiaryMethods::switchFirstLetterToCapital(secondName);

    cout << "Podaj haslo: ";
    cin >> password;

    user.setFirstName(firstName);
    user.setSecondName(secondName);
    user.setPassword(password);

    return user;
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

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

void UserManager::registration() {
    User user = enterNewUserData();

    users.push_back(user);
    usersFile.saveUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

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

void UserManager::saveAllUsersToFile() {
    usersFile.saveAllUsersToFile(users);
}

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
    usersFile.saveAllUsersToFile(users);
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


