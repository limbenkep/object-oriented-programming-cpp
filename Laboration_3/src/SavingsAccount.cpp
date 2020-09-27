//
// Created by limbe on 2020-09-27.
//

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const string &accountNr, int n) : Account(accountNr), interestRate(n),
nrOfWithdrawals(0)
{
}

bool SavingsAccount::withdraw(int amount)
{
    if(amount > getUseableAmount() || nrOfWithdrawals == maxWithdrawals)
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
    return "savings";
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
