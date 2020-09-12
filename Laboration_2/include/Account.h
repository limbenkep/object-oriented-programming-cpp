//
// Created by limbe on 2020-09-07.
//

#ifndef BANK_SYSTEM1_ACCOUNT_H
#define BANK_SYSTEM1_ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;


class Account
{
private:
    string accountNr; // bank account number
    double balance; // current balance
    double credit; //approved credit
public:
    Account(const string &accountNr);

    virtual ~Account();

    const string &getAccountNr() const;
/*
* returns current balance
*/
    double getBalance() const;
/*
* returns current credit
*/
    double getCredit() const;

/*
 * receives a double and set the value as credit
 */
    void setCredit(double pCredit);
/*
 * receives a double as a parameter and adds the double to balance to give new balance
 */
    void deposit(double amount);

/*
 * receives a double as a parameter and subtract the double from balance to give new balance
 */
    void withdraw(double amount);

/*
 * returns the sum of credit and balance
 */
    double getUseableAmount() const;

};


#endif //BANK_SYSTEM1_ACCOUNT_H
