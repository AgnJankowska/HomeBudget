#ifndef UsersFile_H
#define UsersFile_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "SubsidiaryMethods.h"
#include "Markup.h"

using namespace std;

class UsersFile
{
private:
    vector <User> users;
    const string NAME_OF_FILE_WITH_USERS;

public:
    UsersFile(string nameOfFileWithUsers) : NAME_OF_FILE_WITH_USERS(nameOfFileWithUsers) {}

    void saveUserToFile(User user);
    void saveAllUsersToFile(vector <User> users);
    vector <User> loadUsersFromFile();
};
#endif
