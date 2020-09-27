//
// Created by limbe on 2020-09-27.
//

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
    return "transaction";
}

int TransactionAccount::getUseableAmount() const
{
    return getBalance()+credit;
}

void TransactionAccount::setCredit(int pCredit)
{
    credit = pCredit;
}



