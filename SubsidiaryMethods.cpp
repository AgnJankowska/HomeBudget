#include "SubsidiaryMethods.h"

string SubsidiaryMethods::conversionIntegerToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string SubsidiaryMethods::getLine() {
    cin.sync();
    string input = "";
    getline(cin, input);
    return input;
}
/*

string SubsidiaryMethods::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}
*/

int SubsidiaryMethods::conversionStrintToInteger(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

int SubsidiaryMethods::conversionStrintToFloat(string number) {
    float numberFloat;
    istringstream iss(number);
    iss >> numberFloat;

    return numberFloat;
}


char SubsidiaryMethods::getCharacter() {
    string input = "";
    char character  = {0};
    cin.sync();
    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string SubsidiaryMethods::switchFirstLetterToCapital(string text) {
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

/*int SubsidiaryMethods::getInteger() {
    string input = "";
    int number = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(imput);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}*/

float SubsidiaryMethods::getFloatingNumberWithDot() {
    string input;
    float floatingNumber = 0;

    while (true) {
        getline(cin, input);

        size_t position = input.find(',');
        if( position != string::npos ) {
            input = input.replace(position, 1, ".");
        }

        stringstream myStream(input);
        if (myStream >> floatingNumber) {
            break;
        }

        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }

    float precision = 0.01;
    float rounded = round(floatingNumber/precision)*precision;

    return  rounded;
}

