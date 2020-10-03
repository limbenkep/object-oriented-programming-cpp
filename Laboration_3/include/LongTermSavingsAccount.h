/*LongTermSavingsAccount.h
* Honorine Lima
* Holi1900
* DT060G_Laboration_3
* 2020-09-27.
 *
 * ===========short description================
 * The longterm savings account have no credit, max 1 withdrawal and an interest rate double that of the savings account.
 * The account keeps track of the balance, number of withdrawals per year(years not implemented in this project)
 * has class specific implementations of account functions.
*/

#ifndef BANK_SYSTEM2_LONGTERMSAVINGSACCOUNT_H
#define BANK_SYSTEM2_LONGTERMSAVINGSACCOUNT_H
#include "SavingsAccount.h"
#include <vector>
#include <algorithm>


class LongTermSavingsAccount : public SavingsAccount
{
private:
    const string accType = "Long term savings Account";

public:

    explicit LongTermSavingsAccount(const string &accountNr, int rate=2, int n=1);

    virtual ~LongTermSavingsAccount();

/*
 * receives a double as a parameter and subtract the double from balance to give new balance
 */
    virtual bool withdraw(int amount);

    void saveToFile(ofstream &outFile) override;

    bool hasMaxWithdrawals() const override;
//=================Getters==============================================================================================

/*
* returns current credit
*/
    //virtual int getCredit() const;

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
    virtual int getNrOfWithdrawals() const;

/**
 *
 * @return the number of withdrawals that can be made for an account
 */
    virtual int getMaxWithdrawals() const;

/**
 *
 * @return account interest
 */
    virtual int getInterest() const;

    virtual void getAccountSummary(vector<string> &vec);

//===========Setters====================================================================================================
/*
 * receives a double and set the value as credit
 */
    //virtual void setCredit(int pCredit);

    /*
    * receives a an  int and set the value as number of withdrawals
    */
    virtual void setNrOfWithdrawals(int pNrOfWithdrawals);


    /**
 * sets the Interest rate with the given value
 */
    virtual void setInterest(int pInterest);

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
    virtual bool hasInterest() const {return true;};

/**
  * test if account type has a maximum number of withdrawals
 * @return true if it has else false
 */
    virtual bool hasMaxWithdrawals() {return true;};
};


#endif //BANK_SYSTEM2_LONGTERMSAVINGSACCOUNT_H
