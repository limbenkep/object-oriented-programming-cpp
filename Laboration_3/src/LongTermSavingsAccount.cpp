/*LongTermSavingsAccount.cpp
* Honorine Lima
* Holi1900
* DT060G_Laboration_3
* 2020-09-27.

#include "LongTermSavingsAccount.h"

LongTermSavingsAccount::LongTermSavingsAccount(const string &accountNr, int rate, int n) : SavingsAccount(accountNr,
                                                                                                          rate, n)
{

}
LongTermSavingsAccount::~LongTermSavingsAccount()
{

}

bool LongTermSavingsAccount::withdraw(int amount)
{
    return SavingsAccount::withdraw(amount);
}

string LongTermSavingsAccount::getAccountType() const
{
    return accType;
}

int LongTermSavingsAccount::getUseableAmount() const
{
    return SavingsAccount::getUseableAmount();
}

int LongTermSavingsAccount::getNrOfWithdrawals() const
{
    return SavingsAccount::getNrOfWithdrawals();
}

int LongTermSavingsAccount::getMaxWithdrawals() const
{
    return SavingsAccount::getMaxWithdrawals();
}

int LongTermSavingsAccount::getInterest() const
{
    return SavingsAccount::getInterest()*2;
}

void LongTermSavingsAccount::setInterest(int pInterest)
{
    SavingsAccount::setInterest(pInterest);
}

void LongTermSavingsAccount::getAccountSummary(vector<string> &vec)
{
    //concatenates phrases and the valu to the displayed into a string and pushed to the vector ready to be printed
    string temp;

    temp = "Longterm savings account nr: " + getAccountNr();
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

    temp = "No credit.";
    vec.push_back(temp);
    myInt = to_string(getMaxWithdrawals());
    temp = "Max " + myInt + " annual withdrawal";
    vec.push_back(temp);
}

void LongTermSavingsAccount::saveToFile(ofstream &outFile)
{
    SavingsAccount::saveToFile(outFile);
}

bool LongTermSavingsAccount::hasMaxWithdrawals() const
{
    return SavingsAccount::hasMaxWithdrawals();
}

void LongTermSavingsAccount::setNrOfWithdrawals(int pNrOfWithdrawals)
{
    SavingsAccount::setNrOfWithdrawals(pNrOfWithdrawals);
}


