#include "CashFlow.h"

void CashFlow::setUserId (int newUserId){
    userId = newUserId;
}

void CashFlow::setDate (int newDate){
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

int CashFlow::getDate (){
    return date;
}

string CashFlow::getCategory (){
    return category;
}

float CashFlow::getAmount (){
    return amount;
}
