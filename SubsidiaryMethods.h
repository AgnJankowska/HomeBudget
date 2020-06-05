#ifndef SubsidiaryMethods_H
#define SubsidiaryMethods_H
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class SubsidiaryMethods
{
public:
    //static string konwerjsaIntNaString(int liczba);
    static string getLine();
    //static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int conversionStrintToInteger(string number);
    static char getCharacter();
    static string switchFirstLetterToCapital(string text);
    //static int wczytajLiczbeCalkowita();
};
#endif
