#ifndef Uzytkownik_H
#define Uzytkownik_H
#include <iostream>
using namespace std;

class Uzytkownik
{
    int id;
    string login;
    string haslo;

public:
    Uzytkownik (int id=0, string login="", string haslo="")
    {
        this -> id = id;  //nie przeslaniamy danych, nie trzeba zmieniac nazw w konstruktorze
        this -> login = login;
        this -> haslo = haslo;
    }

    void ustawId (int noweId);
    void ustawLogin (string nowyLogin);
    void ustawHaslo (string noweHaslo);

    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo ();
};
#endif
