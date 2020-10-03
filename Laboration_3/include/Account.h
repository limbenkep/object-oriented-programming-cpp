
/*Account.h
* Honorine Lima
* Holi1900
* DT060G_Laboration_3
* 2020-09-27.
*/
/**
 * The account class has data members
 */
/**==========short description
 * This class is an abstract class which will serve as a base for creating different account types.
 * This class has data members account number and balance and have functions for managing the account
 * class Account has a counstructor that take the account number abd a destructor and functions to;
 * - get the account number, interest, type of account, credit, number of withdrawals, max number of withdrawals,
 * - set credit and interest
 * - deposit and withdraw from account
 * The functions marked virtual will be implemented in the different account types
 */
/*Account.h
* Honorine Lima
* Holi1900
* DT060G_Laboration_2
* 2020-09-27.
*/
/**
 * The account class is an abstract class that serves as a bas for the classes of the different account types
 */
#ifndef LABORATION_3_ACCOUNT_H
#define LABORATION_3_ACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Account
{
private:
    string accountNr; // bank account number
    int balance{}; // current balance
public:
    /**
     *overload constructor taking single parameter
     * @param accountNr
     */
    Account(const string &accountNr);


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

    virtual void saveToFile(ofstream &outFile) = 0;

    //virtual void readFromFile(ostream &inFile) = 0;
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
    virtual string getAccountType() const=0;
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
    virtual void getAccountSummary(vector<string> &vec) {};

//===========Setters====================================================================================================
/*
 * receives a double and set the value as credit
 */
    virtual void setCredit(int pCredit) {};

/**
 * setInterest
 */
    virtual void setInterest(int pInterest){};

    void setBalance(int amount);

    /*
 * receives a an  int and set the value as number of withdrawals
 */
    virtual void setNrOfWithdrawals(int pNrOfWithdrawals){};

//================Testers================================================================================================
/**
 * test if account type has credit
 * @return true if it has else false
 */
    virtual bool hasCredit() const =0;

/**
  * test if account type has interest
 * @return true if it has else false
 */
    virtual bool hasInterest() const =0;

/**
  * test if account type has a maximum number of withdrawals
 * @return true if it has else false
 */
    virtual bool hasMaxWithdrawals() const =0;
};
#endif //LABORATION_3_ACCOUNT_H
