//
// Created by limbe on 2020-09-28.
//

#ifndef BANK_SYSTEM2_BANK_H
#define BANK_SYSTEM2_BANK_H
#include "Customer.h"

class Bank
{
private:
    unique_ptr<Customer>client;//unique pointer to a customer that will hold current customer

public:

    /**
     * default constructor
     */
    Bank();

    /**
     * destructor
     */
    virtual ~Bank();

    /**
     * creates a new customer object held by the unique pointer client(data member)
     * @param name
     * @param persNr
     */
    void createCustumer(string &name, string &persNr);

    /**
     * Creates a new account for the current customer
     * returns a bool
     */
    bool createNewAccount(int accType);

    /**
     * recieves acc nr and returns the type of account
     * @param accountNr
     * @return account type
     */
    string getAccType(string &accountNr);

    /**
     * assign account numbers to vector passed by reference
     * @param vec
     * @return false if there are no accounts else true
     */
    bool getAccountNrs(vector<string>&vec)const ;

    /**
     * receives an account number and deletes the corresponding account
     * @param accountnr
     * @return
     */
    bool deleteAnAccount(string &accountnr);

    /**
     *
     * @return the sum of all the balance and credit of all the customer's accounts
     */
    int totalAsset();

    /**
     *
     * @return the number of accounts the customer owns
     */
    int NrofAccounts();

    /**
     * receives an account number as parameter and assign the balance, credit and disposable to a vector passed by reference
     * @param accountnr
     * @param accountData
     * @return return true if the aacount number received if found else false
     */
    bool accountInfo(string &accountnr, vector<int>&accountData);

    /**
     * This function gets the summary of all the accounts owned by the customer; account numbers, balance, disposable
     * @param accountNrs, a vector of type string passed by reference to which all account numbers are assigned
     * @param summary, a vector of vectors of tupe double passed by reference to which the balance, credit and disposable of each account
     * is assigned to a vector and the vector of
     * @return false if client has no accunts else true.
     */
    bool clientSummery(vector<string> &accountNrs, vector<vector<int>>&summary);

    /**
     * gets useables for each account for all customer's account
     * @param accountNrs, vector of tupe string passed by reference to which account numbers are assigned
     * @param summary, vector of type double passed by reference to which all useables are assigned
     * @return false if client has no accunts else true.
     */
    bool accountsUseables(vector<string> &accountNrs, vector<int> &summary);

    /**
     * gets client name
     * @return client name as a string
     */
    string getClientName();

    /**
     * gets client ID
     * @return client ID as a string
     */
    string getClientID();

    /**
     * withdrws a given amount from a given account
     * @param accountnr
     * @param amount
     * @return true id given account number is found else false
     */
    bool withdraw(string &accountnr, int amount);

    /**
     * deposits a given amount to a given account
     * @param accountnr
     * @param amount
     * @return true id given account number is found else false
     */
    void deposit(string &accountnr, int amount);

    /**
     * sets the account credit of a given account by a given amount
     * @param accountnr, given account number
     * @param amount, given amount
     * @return true if account with given account number is found else false
     */
    bool changeAccCredit(string &accountnr, int amount);

    /**
     * save client to a file
     */
    void saveClientToFile();

    /**
     * reads client from a file
     * @return true if file is successfully found and  read else false
     */
    bool readClientFromFile();
    /**
     * receives an account number and check if an account number existwith that number
     * @param accountNr
     * @return true if account is found else false
     */
    bool accountExist(string &accountNr) const;
    /**
 * returns the interest rate of an account
 */
    int getInterest(string &accountNr) const;
    /**
 *
 * @return number of withdrawals
 */
    int getNrOfWithdrawals(string &accountNr) const;

/**
 *
 * @return the number of withdrawals that can be made for an account
 */
    int getMaxWithdrawals(string &accountNr) const;
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


#endif //BANK_SYSTEM2_BANK_H
