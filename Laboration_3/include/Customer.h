//
// Created by limbe on 2020-09-27.
//

#ifndef BANK_SYSTEM2_CUSTOMER_H
#define BANK_SYSTEM2_CUSTOMER_H
#include "Account.h"
#include "SavingsAccount.h"
#include "TransactionAccount.h"
#include "LongTermSavingsAccount.h"
#include <memory>
#include <vector>
#include <algorithm>

class Customer
{
private:
    vector<unique_ptr<Account>>bankAccounts; //Vector with pointer to customer's accounts
    string name;
    string customerId;

    const int maxSize = 3;

public:
    Customer() =default;
    Customer(const string &name, const string &customerId);

    virtual ~Customer();
/**
 *
 * @return customer name
 */
    const string &getName() const;

    /**
     *
     * @return customer id
     */
    const string &getCustomerId() const;
    string getAccountType(const string &accountnr);
/**
 * gets the account balance of a given account
 * @param accountnr, an account number
 * @return account balance as a double
 */
    int getAccountBalance(const string &accountnr);

    /**
     * gets balance, credit and useables for a given account
     * @param accountnr, account number
     * @param accountData; vector passed by reference to which balance, credit and useables is stored
     * @return true if account with given account number is found else false
     */
    bool getAccountInfo(string &accountnr, vector<int>&accountData);

    /**
     * gets balance, credit and useables for all accounts
     * @param accountNrs, vector passed by ref to which all account numbers are stored
     * @param accountData; vector passed by reference to which balance, credit and useables is stored
     * @return false if customer has no accounts else true
     */
    bool getSummary(vector<string> &accountNrs, vector<vector<int>>&summary);

    /**
     * gets useables for all accounts
     * @param accountNrs, vector passed by ref to which all account numbers are assigned
     * @param summary, vector passed by ref to which useables for all counts are stored
     * @return false if customer has no accounts else true
     */
    bool useableSummary(vector<string> &accountNrs, vector<int>&summary);

    /**
     * gets the to total balance and credit for all the customer's account
     * @return total asset
     */
    int getTotalAsset();

    /**
     * receives account type passed as an integer and creates a new account of that type for current customer
     * @param accType
     * @return false if the customer already have max number of account else true
     */
    bool createAccount(int accType);
    /*
     *creates a new transaction account for current customer
     * @return false if the customer already have max number of account else true
     */
    bool createTransactionAccount();
    /*
     *creates a new savings account for current customer
     * @return false if the customer already have max number of account else true
     */
    bool createSavingsAccount();
    /*
     *creates a new long term savings account for current customer
     * @return false if the customer already have max number of account else true
     */
    bool createLongSavingsAccount();

    /**
     * receives an account nuber and returns the index of the corresponding account in the vector bankAccounts
     */
    int getAccountIndex(const string &accountnr) const;

    /**
     * deletes a given account
     * @param accountnr , account number
     * @return true if given account is found else false
     */
    bool deleteAccount(string &accountnr);

    /**
     * withdraw a given acmount from a given account
     * @param accountnr
     * @param amount
     * @return
     */
    bool withdrawFromAccount(string &accountnr, int amount);

    /**
     * deposit a given amount to a given account
     * @param accountnr
     * @param amount
     * @return true if account with given account number is found else false
     */
    bool depositToAccount(string &accountnr, int amount);

    /**
     * set credit to a given amount for a given account
     * @param accountnr
     * @param amount
     * @return true if account with given account number is found else false
     */
    bool changeCredit(string &accountnr, int amount);

    /**
     * returns the nymbe of accounts owmned by the customer
     */
    int getNrofAccounts();

    /**
     * gets account numbers of all customer's account by assigning to a vector passed by reference
     * @param vec
     * @return false if customer has no account else true
     */
    bool getAccountNrs(vector<string>&vec)const;

    /**
     * save client to file
     */
    void saveToFile();

    /**
     * read client from file
     * @return false if file not read
     */
    bool readFromFile();
//================Testers================================================================================================
/**
 * test if account type has credit
 * @return true if it has else false
 */
   bool hasCredit(string &accountNr) const;

/**
  * test if account type has interest
 * @return true if it has else false
 */
   bool hasInterest(string &accountNr) const;

/**
  * test if account type has a maximum number of withdrawals
 * @return true if it has else false
 */
    bool hasMaxWithdrawals(string &accountNr);

};


#endif //BANK_SYSTEM2_CUSTOMER_H
