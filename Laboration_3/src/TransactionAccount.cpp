/*TransactionAccount.cpp
* Honorine Lima
* Holi1900
* DT060G_Laboration_3
* 2020-09-27.*/

#include "TransactionAccount.h"

TransactionAccount::TransactionAccount(const string &accountNr, int pCredit) : Account(accountNr), credit(pCredit)
{
}


TransactionAccount::~TransactionAccount()
{

}

bool TransactionAccount::withdraw(int amount)
{
    if(amount > getUseableAmount())
    {
        return false;
    }
    else
    {
        int balance = getBalance();
        balance -= amount;
        setBalance(balance);
        return true;
    }
}

int TransactionAccount::getCredit() const
{

    return credit;
}

string TransactionAccount::getAccountType() const
{
    return accType;
}

int TransactionAccount::getUseableAmount() const
{
    return getBalance()+credit;
}

void TransactionAccount::setCredit(int pCredit)
{
    credit = pCredit;
}

void TransactionAccount::getAccountSummary(vector<string> &vec)
{
    //concatenates phrases and the valu to the displayed into a string and pushed to the vector ready to be printed
    string temp;

    temp = "=====Transaction account nr: " + getAccountNr() + "=====";
    vec.push_back(temp);
    string myInt= to_string(getBalance());
    temp = "balance: " + myInt;
    vec.push_back(temp);

    myInt = to_string(getUseableAmount());
    temp = "Disposable: " + myInt;
    vec.push_back(temp);

    myInt = to_string(getInterest());
    temp = "Interest Rate: " + myInt + ".0%";
    vec.push_back(temp);

    myInt = to_string(getCredit());
    temp = "Credit Limit: " + myInt;
    vec.push_back(temp);
}

void TransactionAccount::saveToFile(ofstream &outFile)
{
    outFile <<getAccountType() << endl
                <<getAccountNr() << endl
                << getBalance() << endl
                << getCredit() << endl;
}





