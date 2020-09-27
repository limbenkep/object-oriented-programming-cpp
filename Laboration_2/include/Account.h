/*Account.h
* Honorine Lima
* Holi1900
* DT060G_Laboration_2
* 2020-09-07.
*/
/**
 * The account class has data members
 */

#ifndef BANK_SYSTEM1_ACCOUNT_H
#define BANK_SYSTEM1_ACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Account
{
private:
    string accountNr; // bank account number
    double balance{}; // current balance
    double credit{}; //approved credit
public:
    //default construction
    Account() = default;
    /**
     *overload constructor taking single parameter
     * @param accountNr
     */
    explicit Account(const string &accountNr);

    /**
     *overload constructor taking three parameter
     * @param accountNr
     * @param balance
     * @param credit
     */
    Account(const string &accountNr, double balance, double credit);
/**
 * destructor
 */
    virtual ~Account();

/*
* returns account number
*/
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
    bool withdraw(double amount);

/*
 * returns the sum of credit and balance
 */
    double getUseableAmount() const;

};


#endif //BANK_SYSTEM1_ACCOUNT_H
