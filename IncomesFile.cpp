#include "IncomesFile.h"

int IncomesFile::getIdOfLastIncome(){
    int idOfLastIncome = 0;

    CMarkup xml;
    bool IsFileExist=xml.Load (NAME_OF_INCOME_FILE);
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

    bool IsFileExist=xml.Load (NAME_OF_INCOME_FILE);
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
    xml.AddElem ("Category", income.getCategory());
    xml.AddElem ("Amount", income.getAmount());

    xml.Save(NAME_OF_INCOME_FILE);
}

void IncomesFile::loadIncomesFromFile (){
;
}

