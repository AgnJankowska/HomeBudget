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
    xml.AddElem ("Category", expense.getCategory());
    xml.AddElem ("Amount", expense.getAmount());

    xml.Save(NAME_OF_EXPENSES_FILE);
}

vector <Expense> ExpensesFile::loadExpensesFromFile (int ID_ZALOGOWANEGO_UZYTKOWNIKA){
    Expense expense;
    CMarkup xml;

    xml.Load (NAME_OF_EXPENSES_FILE);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Expense") )
    {
        xml.IntoElem();
        xml.FindElem("ExpenseID");
        expense.setExpenseId(SubsidiaryMethods::conversionStrintToInteger(xml.GetData()));
        xml.FindElem("UserID");
        expense.setUserId(SubsidiaryMethods::conversionStrintToInteger(xml.GetData()));
        xml.FindElem("Date");
        expense.setDate(xml.GetData());
        xml.FindElem("Category");
        expense.setCategory(xml.GetData());
        xml.FindElem("Amount");
        expense.setAmount(SubsidiaryMethods::conversionStrintToFloat(xml.GetData()));

        xml.OutOfElem();
        expenses.push_back(expense);
    }
    return expenses;
}

