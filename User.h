#ifndef User_H
#define User_H
#include <iostream>
using namespace std;

class User
{
    int id;
    string firstName;
    string secondName;
    string login;
    string password;

public:
    User (int id=0, string firstName="", string secondName="", string login="", string password="")
    {
        this -> id = id;
        this -> firstName = firstName;
        this -> secondName = secondName;
        this -> login = login;
        this -> password = password;
    }

    void setId (int newId);
    void setFirstName (string newFirstName);
    void setSecondName (string newSecondName);
    void setLogin (string newLogin);
    void setPassword (string newPassword);

    int getId ();
    string getFirstName ();
    string getSecondName ();
    string getLogin ();
    string getPassword ();
};
#endif
