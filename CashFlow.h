#ifndef CashFlow_H
#define CashFlow_h
#include <iostream>
using namespace std;

class CashFlow
{
    int userId;
    int date;
    string category;
    float amount;

public:
    CashFlow (int userId=0, int date=0, string category="", float amount=0)
    {
        this -> userId = userId;
        this -> date = date;
        this -> category = category;
        this -> amount = amount;
    }

    void setUserId (int newUserId);
    void setDate (int newDate);
    void setCategory (string newCategory);
    void setAmount (float newAmount);

    int getUserId ();
    int getDate ();
    string getCategory ();
    float getAmount ();

    };
#endif
