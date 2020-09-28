//
// Created by limbe on 2020-09-27.
//

#ifndef BANK_SYSTEM2_TRANSACTIONACCOUNT_H
#define BANK_SYSTEM2_TRANSACTIONACCOUNT_H
#include "Account.h"


class TransactionAccount : public Account
{
private:
    int credit;
    const string accType = "Transaction Account";

public:

    TransactionAccount(const string &accountNr, int pCredit=0);

    virtual ~TransactionAccount();


/*
 * receives a double as a parameter and subtract the double from balance to give new balance
 */
    virtual bool withdraw(int amount);

//=================Getters==============================================================================================

/*
* returns current credit
*/
    virtual int getCredit() const;

/**
 * gets the type of account
 * @return different names depending on the account number
 */
    virtual string getAccountType() const;
/*
 * returns the sum of credit and balance
 */
    virtual int getUseableAmount() const;

/**
 *
 * @return number of withdrawals
 */
    //virtual int getNrOfWithdrawals() const;

/**
 *
 * @return the number of withdrawals that can be made for an account
 */
    //virtual int getMaxWithdrawals() const;

/**
 *
 * @return account interest
 */
    //virtual int getInterest() const;

//===========Setters====================================================================================================
/*
 * receives a double and set the value as credit
 */
    virtual void setCredit(int pCredit);

/**
 * setInterest
 */
    //virtual void setInterest(int pInterest);

//================Testers================================================================================================
/**
 * test if account type has credit
 * @return true if it has else false
 */
    virtual bool hasCredit() const {return true;};

/**
  * test if account type has interest
 * @return true if it has else false
 */
    virtual bool hasInterest() const {return false;};

/**
  * test if account type has a maximum number of withdrawals
 * @return true if it has else false
 */
    virtual bool hasMaxWithdrawals() {return false;};
};


#endif //BANK_SYSTEM2_TRANSACTIONACCOUNT_H
