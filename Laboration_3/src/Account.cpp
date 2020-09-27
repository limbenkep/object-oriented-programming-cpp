
/*Account.cpp
* Honorine Lima
* Holi1900
* DT060G_Laboration_2
* 2020-09-27.
*/


#include "Account.h"

Account::Account(const string &accountNr) : accountNr(accountNr), balance(0)
{
}

const string &Account::getAccountNr() const
{
    return accountNr;
}

int Account::getBalance() const
{
    return balance;
}

void Account::deposit(int amount)
{
    balance += amount;
}

bool Account::withdraw(int amount)
{
    if(amount > getUseableAmount())
    {
        return false;
    }
    else
    {
        balance -= amount;
        return true;
    }
}

void Account::setBalance(int amount)
{
    balance = amount;
}

