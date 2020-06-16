#include "ExpensesFile.h"

int ExpensesFile::getIdOfLastExpense(){
    int idOfLastExpense = 0;

    CMarkup xml;
    xml.Load (NAME_OF_EXPENSES_FILE);

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") ){
        xml.IntoElem();
        xml.FindElem("ExpenseID");
        idOfLastExpense = SubsidiaryMethods::conversionStrintToInteger(xml.GetData());
        xml.OutOfElem();
    }

    return idOfLastExpense;
}

void ExpensesFile::saveExpenseToFile (Expense expense){
    CMarkup xml;

    bool IsFileExist=xml.Load (NAME_OF_EXPENSES_FILE);
    if (!IsFileExist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem ("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem ("Expense");
    xml.IntoElem();
    xml.AddElem ("ExpenseID", expense.getExpenseId());
    xml.AddElem ("UserID", expense.getUserId());
    xml.AddElem ("Date", expense.getDate());
    xml.AddElem ("DateInt", expense.getDateInt());
    xml.AddElem ("Category", expense.getCategory());
    xml.AddElem ("Amount", SubsidiaryMethods::conversionFloatToString(expense.getAmount()));

    xml.Save(NAME_OF_EXPENSES_FILE);
}

vector <Expense> ExpensesFile::loadExpensesFromFile (int ID_ZALOGOWANEGO_UZYTKOWNIKA){

    vector <Expense> expenses;
    Expense expense;
    CMarkup xml;

    xml.Load (NAME_OF_EXPENSES_FILE);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Expense") )
    {
        xml.IntoElem();
        xml.FindElem("UserID");
        if (SubsidiaryMethods::conversionStrintToInteger(xml.GetData()) == ID_ZALOGOWANEGO_UZYTKOWNIKA)
        {
            xml.ResetMainPos();
            xml.FindElem("ExpenseID");
            expense.setExpenseId(SubsidiaryMethods::conversionStrintToInteger(xml.GetData()));
            xml.FindElem("UserID");
            expense.setUserId(SubsidiaryMethods::conversionStrintToInteger(xml.GetData()));
            xml.FindElem("Date");
            expense.setDate(xml.GetData());
            expense.setDateInt(expense.getDate());
            xml.FindElem("Category");
            expense.setCategory(xml.GetData());
            xml.FindElem("Amount");
            expense.setAmount(SubsidiaryMethods::conversionStrintToFloat(xml.GetData()));

            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;
}
