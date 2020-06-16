#include "IncomesFile.h"

int IncomesFile::getIdOfLastIncome(){
    int idOfLastIncome = 0;

    CMarkup xml;
    bool IsFileExist=xml.Load (NAME_OF_INCOMES_FILE);
    if (!IsFileExist){
        return idOfLastIncome;
    }

    else {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Income") ){
            xml.IntoElem();
            xml.FindElem("IncomeID");
            idOfLastIncome = SubsidiaryMethods::conversionStrintToInteger(xml.GetData());
            xml.OutOfElem();
        }
        return idOfLastIncome;
    }

}

void IncomesFile::saveIncomeToFile (Income income){
    CMarkup xml;

    bool IsFileExist=xml.Load (NAME_OF_INCOMES_FILE);
    if (!IsFileExist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem ("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem ("Income");
    xml.IntoElem();
    xml.AddElem ("IncomeID", income.getIncomeId());
    xml.AddElem ("UserID", income.getUserId());
    xml.AddElem ("Date", income.getDate());
    xml.AddElem ("DateInt", income.getDateInt());
    xml.AddElem ("Category", income.getCategory());
    xml.AddElem ("Amount", income.getAmount());

    xml.Save(NAME_OF_INCOMES_FILE);
}

vector <Income> IncomesFile::loadIncomesFromFile (int ID_ZALOGOWANEGO_UZYTKOWNIKA){
    vector <Income> incomes;
    Income income;
    CMarkup xml;

    xml.Load (NAME_OF_INCOMES_FILE);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Income") )
    {
        xml.IntoElem();
        xml.FindElem("UserID");
        if (SubsidiaryMethods::conversionStrintToInteger(xml.GetData()) == ID_ZALOGOWANEGO_UZYTKOWNIKA)
        {
            xml.ResetMainPos();
            xml.FindElem("IncomeID");
            income.setIncomeId(SubsidiaryMethods::conversionStrintToInteger(xml.GetData()));
            xml.FindElem("UserID");
            income.setUserId(SubsidiaryMethods::conversionStrintToInteger(xml.GetData()));
            xml.FindElem("Date");
            income.setDate(xml.GetData());
            income.setDateInt(income.getDate());
            xml.FindElem("Category");
            income.setCategory(xml.GetData());
            xml.FindElem("Amount");
            income.setAmount(SubsidiaryMethods::conversionStrintToFloat(xml.GetData()));

            incomes.push_back(income);
        }
        xml.OutOfElem();

    }
    return incomes;
}

