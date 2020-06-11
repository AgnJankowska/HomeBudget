#include "CashFlow.h"

void CashFlow::setUserId (int newUserId){
    userId = newUserId;
}

void CashFlow::setDate (string newDate){
    date = newDate;
}

void CashFlow::setCategory (string newCategory){
    category = newCategory;
}

void CashFlow::setAmount (float newAmount){
    amount = newAmount;
}

int CashFlow::getUserId (){
    return userId;
}

string CashFlow::getDate (){
    return date;
}

string CashFlow::getCategory (){
    return category;
}

float CashFlow::getAmount (){
    return amount;
}
