/*SavingsAccount.cpp
* Honorine Lima
* Holi1900
* DT060G_Laboration_3
* 2020-09-27.

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const string &accountNr, int rate, int n) : Account(accountNr), interestRate(rate),
maxWithdrawals(n), nrOfWithdrawals(0)
{
}

bool SavingsAccount::withdraw(int amount)
{
    if(amount > getUseableAmount() || nrOfWithdrawals >= maxWithdrawals)
    {
        return false;
    }
    else
    {
        int balance = getBalance();
        balance -= amount;
        setBalance(balance);
        nrOfWithdrawals++;
        return true;
    }
}

string SavingsAccount::getAccountType() const
{
    return accType;
}

int SavingsAccount::getUseableAmount() const
{
    return Account::getUseableAmount();
}

int SavingsAccount::getNrOfWithdrawals() const
{
    return nrOfWithdrawals;
}

int SavingsAccount::getMaxWithdrawals() const
{
    return maxWithdrawals;
}

int SavingsAccount::getInterest() const
{
    return interestRate;
}

void SavingsAccount::setInterest(int pInterest)
{
    interestRate = pInterest;
}

void SavingsAccount::getAccountSummary(vector<string> &vec)
{
    //concatenates phrases and the valu to the displayed into a string and pushed to the vector ready to be printed
    string temp;

    temp = "=====Savings account nr: " + getAccountNr() + "=====";
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
    myInt = to_string(maxWithdrawals);
    temp = "Max " + myInt + " annual withdrawal";
    vec.push_back(temp);
}

void SavingsAccount::saveToFile(ofstream &outFile)
{
    outFile << getAccountType() << endl
            << getAccountNr() << endl
            << getBalance() << endl
            <<getInterest()<<endl
            << getNrOfWithdrawals() << endl;
}

void SavingsAccount::setNrOfWithdrawals(int pNrOfWithdrawals)
{
    nrOfWithdrawals = pNrOfWithdrawals;
}


