//
// Created by limbe on 2020-09-27.
//

#include "LongTermSavingsAccount.h"

LongTermSavingsAccount::LongTermSavingsAccount(const string &accountNr, int rate, int n) : SavingsAccount(accountNr,
                                                                                                          rate, n)
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
