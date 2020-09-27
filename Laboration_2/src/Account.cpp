/*Account.cpp
* Honorine Lima
* Holi1900
* DT060G_Laboration_2
* 2020-09-07.
*/
#include "Account.h"

Account::Account(const string &accountNr) : accountNr(accountNr)
{
}

Account::Account(const string &accountNr, double balance, double credit) : accountNr(accountNr), balance(balance),
                                                                           credit(credit)
{
}

Account::~Account()
{

}

const string &Account::getAccountNr() const
{
    return accountNr;
}

double Account::getBalance() const
{
    return balance;
}


double Account::getCredit() const
{
    return credit;
}

void Account::setCredit(double pCredit)
{
    Account::credit = pCredit;
}

void Account::deposit(double amount)
{
    balance += amount;
}

bool Account::withdraw(double amount)
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

double Account::getUseableAmount() const
{
    return balance + credit;
}



