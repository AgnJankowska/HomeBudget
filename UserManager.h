#ifndef UserManager_H
#define UserManager_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UsersFile.h"
#include "SubsidiaryMethods.h"
using namespace std;

class UserManager
{
    int IdOfSignedIndUser;
    vector <User> users;

    User enterNewUserData();
    bool isLoginExist(string login);
    UsersFile usersFile;

public:
    UserManager (string nameOfFileWithUsers) : usersFile (nameOfFileWithUsers)
    {
        IdOfSignedIndUser = 0;
    //    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku ();
    };

    int getNewUserId();
    //int pobierzIdZalogowanegoUzytkownika();

    void registration();
    int singIn();
    //void wypiszWszystkichUzytkownikow();
    //void wczytajUzytkownikowZPliku();
    //void zapiszWszystkichUzytkownikowDoPliku();

    void changePassword();
    void logOut();
    bool isUserSignedIn();
};
#endif
