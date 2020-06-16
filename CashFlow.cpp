#include "CashFlow.h"

void CashFlow::setUserId (int newUserId){
    userId = newUserId;
}

void CashFlow::setDateInt (string date){
    dateInt = SubsidiaryMethods::switchDateInFullFormatToInteger(date);
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

int CashFlow::getDateInt (){
    return dateInt;
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
