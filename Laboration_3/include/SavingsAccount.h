/*SavingsAccount.h
* Honorine Lima
* Holi1900
* DT060G_Laboration_3
* 2020-09-27.
 *
 * ===========short description================
 * The savings account have no credit, max 4 withdrawal and a current interest rate of 2%.
 * The account keeps track of balance, interest and the number of withdrawals per year(years not implemented
 * in this project) has class specific implementations of account functions.
*/

#ifndef BANK_SYSTEM2_SAVINGSACCOUNT_H
#define BANK_SYSTEM2_SAVINGSACCOUNT_H
#include "Account.h"


class SavingsAccount : public Account
{
private:
    int nrOfWithdrawals; // number of withdrawals done from account
    int interestRate; // interest rate is deposited amount in percentage
    int maxWithdrawals; // maximum number of withdrawals that can be done
    const string accType = "Savings Account";

public:
    explicit SavingsAccount(const string &accountNr, int rate=2, int n=4 );

    virtual ~SavingsAccount() {};


/*
 * receives a double as a parameter and subtract the double from balance to give new balance
 */
    virtual bool withdraw(int amount);

    void saveToFile(ofstream &outFile) override;


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
/**
 * returns the account summary in a vector of strings passed by reference
 * @param vec
 */
    virtual void getAccountSummary(vector<string> &vec);

//===========Setters====================================================================================================
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
    virtual bool hasCredit() const override {return false;};

/**
  * test if account type has interest
 * @return true if it has else false
 */
    virtual bool hasInterest()  const override {return true;};

/**
  * test if account type has a maximum number of withdrawals
 * @return true if it has else false
 */
    virtual bool hasMaxWithdrawals() const override {return true;};
};


#endif //BANK_SYSTEM2_SAVINGSACCOUNT_H
