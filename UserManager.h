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
private:
    UsersFile usersFile;
    int IdOfSignedIndUser;
    vector <User> users;

public:
    UserManager (string nameOfFileWithUsers) : usersFile (nameOfFileWithUsers)
    {
        IdOfSignedIndUser = 0;
        users = usersFile.loadUsersFromFile ();
    };

    int getIdOfSignedInUser();

    void registration();
    int singIn();
    void saveAllUsersToFile();
    void changePassword();
    void logOut();
    bool isUserSignedIn();

private:
    User enterNewUserData();
    bool isLoginExist(string login);
    int getNewUserId();
};
#endif
