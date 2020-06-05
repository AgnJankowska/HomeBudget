#include "UsersFile.h"

void UsersFile::saveUserToFile(User user)
{
    CMarkup xml;

    bool IsFileExist=xml.Load (NAME_OF_FILE_WITH_USERS);
    if (!IsFileExist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem ("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem ("User");
    xml.IntoElem();
    xml.AddElem ("UserID", user.getId());
    xml.AddElem ("FirstName", user.getFirstName());
    xml.AddElem ("SecondName", user.getSecondName());
    xml.AddElem ("Login", user.getLogin());
    xml.AddElem ("Password", user.getPassword());

    xml.Save("users.xml");
}

void UsersFile::saveAllUsersToFile(vector <User> users)
{
    CMarkup xml;
    bool IsFileExist=xml.Load (NAME_OF_FILE_WITH_USERS);

    xml.ResetPos();
    xml.RemoveElem();
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem ("Users");

    for (int i=0; i<users.size(); i++)
    {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem ("User");
        xml.IntoElem();
        xml.AddElem ("UserID", users[i].getId());
        xml.AddElem ("FirstName", users[i].getFirstName());
        xml.AddElem ("SecondName", users[i].getSecondName());
        xml.AddElem ("Login", users[i].getLogin());
        xml.AddElem ("Password", users[i].getPassword());
        xml.OutOfElem();
        xml.OutOfElem();
    }

    xml.Save("users.xml");
}

vector <User> UsersFile::loadUsersFromFile()
{
    User user;
    CMarkup xml;

    bool IsFileExist = xml.Load (NAME_OF_FILE_WITH_USERS);

    string zmienna;
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("User") )
    {
        xml.IntoElem();
        xml.FindElem("UserID");
        user.setId(SubsidiaryMethods::conversionStrintToInteger(xml.GetData()));
        xml.FindElem("FirstName");
        user.setFirstName(xml.GetData());
        xml.FindElem("SecondName");
        user.setSecondName(xml.GetData());
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());

        xml.OutOfElem();
        users.push_back(user);
    }
    return users;
}



