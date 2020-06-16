#ifndef SubsidiaryMethods_H
#define SubsidiaryMethods_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>
using namespace std;

class SubsidiaryMethods
{
public:

    static string conversionIntegerToString(int number);
    static string getLine();
    static float getFloatingNumberWithDot();
    //static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int conversionStrintToInteger(string number);
    static int conversionStrintToFloat(string number);
    static char getCharacter();
    static string switchFirstLetterToCapital(string text);
    static int switchDateInFullFormatToInteger(string date);
    //static int wczytajLiczbeCalkowita();
};
#endif
