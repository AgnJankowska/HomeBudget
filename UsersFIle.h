#ifndef UsersFile_H
#define UsersFile_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "SubsidiaryMethods.h"

using namespace std;

class UsersFile
{
    //string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

public:
    const string NAME_OF_FILE_WITH_USERS;

public:
    UsersFile(string nameOfFileWithUsers) : NAME_OF_FILE_WITH_USERS(nameOfFileWithUsers) {}

   //void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    //vector <Uzytkownik> wczytajUzytkownikowZPliku();
    //Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    //void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
};
#endif
