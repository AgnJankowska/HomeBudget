#ifndef CashFlow_H
#define CashFlow_H
#include <iostream>
# include "SubsidiaryMethods.h"
using namespace std;

class CashFlow
{
    int userId;
    int dateInt;
    string date;
    string category;
    float amount;

public:
    CashFlow (int userId=0, int dateInt=0 ,string date="", string category="", float amount=0)
    {
        this -> userId = userId;
        this -> dateInt = dateInt;
        this -> date = date;
        this -> category = category;
        this -> amount = amount;
    }

    void setUserId (int newUserId);
    void setDateInt (string date);
    void setDate (string newDate);
    void setCategory (string newCategory);
    void setAmount (float newAmount);

    int getUserId ();
    int getDateInt ();
    string getDate ();
    string getCategory ();
    float getAmount ();

    };
#endif
