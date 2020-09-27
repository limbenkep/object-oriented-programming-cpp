
/*Account.h
* Honorine Lima
* Holi1900
* DT060G_Laboration_3
* 2020-09-27.
*/
/**
 * The account class has data members
 */


#ifndef LABORATION_3_ACCOUNT_H
#define LABORATION_3_ACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Account
{
private:
    string accountNr; // bank account number
    int balance{}; // current balance
public:
    //default construction
    Account() = default;
    /**
     *overload constructor taking single parameter
     * @param accountNr
     */
    explicit Account(const string &accountNr);


/**
 * destructor
 */
    virtual ~Account() {};

/*
 * receives a double as a parameter and adds the double to balance to give new balance
 */
    void deposit(int amount);

/*
 * receives a double as a parameter and subtract the double from balance to give new balance
 */
    virtual bool withdraw(int amount);

//=================Getters==============================================================================================
/*
* returns account number
*/
    const string &getAccountNr() const;
/*
* returns current balance
*/
    int getBalance() const;
/*
* returns current credit
*/
    virtual int getCredit() const {return 0;};

/**
 * gets the type of account
 * @return different names depending on the account number
 */
    virtual int getAccountType() const=0;
/*
 * returns the sum of credit and balance
 */
    virtual int getUseableAmount() const{return balance;};

/**
 *
 * @return number of withdrawals
 */
    virtual int getNrOfWithdrawals() const {return 0;};

/**
 *
 * @return the number of withdrawals that can be made for an account
 */
    virtual int getMaxWithdrawals() const {return 0;};

/**
 *
 * @return account interest
 */
    virtual int getInterest() const {return 0;};

//===========Setters====================================================================================================
/*
 * receives a double and set the value as credit
 */
    void setCredit(int pCredit) {};

/**
 * setInterest
 */
    virtual void setInterest(int pInterest){};

//================Testers================================================================================================
/**
 * test if account type has credit
 * @return true if it has else false
 */
    virtual bool hasCredit() const {return false;};

/**
  * test if account type has interest
 * @return true if it has else false
 */
    virtual bool hasInterest() const {return false;};

/**
  * test if account type has a maximum number of withdrawals
 * @return true if it has else false
 */
    virtual bool hasMaxWithdrawals() const {return false;};
};
#endif //LABORATION_3_ACCOUNT_H
