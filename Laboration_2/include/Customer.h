
/*Customer.h
* Honorine Lima
* Holi1900
* DT060G_Laboration_2
* 2020-09-07.
*/

#ifndef BANK_SYSTEM1_CUSTOMER_H
#define BANK_SYSTEM1_CUSTOMER_H
#include "Account.h"
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
/**
 * gets the account balance of a given account
 * @param accountnr, an account number
 * @return account balance as a double
 */
    double getAccountBalance(const string &accountnr);

    /**
     * gets balance, credit and useables for a given account
     * @param accountnr, account number
     * @param accountData; vector passed by reference to which balance, credit and useables is stored
     * @return true if account with given account number is found else false
     */
    bool getAccountInfo(string &accountnr, vector<double>&accountData);

    /**
     * gets balance, credit and useables for all accounts
     * @param accountNrs, vector passed by ref to which all account numbers are stored
     * @param accountData; vector passed by reference to which balance, credit and useables is stored
     * @return false if customer has no accounts else true
     */
    bool getSummary(vector<string> &accountNrs, vector<vector<double>>&summary);

    /**
     * gets useables for all accounts
     * @param accountNrs, vector passed by ref to which all account numbers are assigned
     * @param summary, vector passed by ref to which useables for all counts are stored
     * @return false if customer has no accounts else true
     */
    bool useableSummary(vector<string> &accountNrs, vector<double>&summary);

    /**
     * gets the to total balance and credit for all the customer's account
     * @return total asset
     */
    double getTotalAsset();

    /**
     * creates a new account for current customer
     * @return false if the customer already have max number of account else true
     */
    bool createAccount();

    /**
     * receives an account nuber and returns the index of the corresponding account in the vector bankAccounts
     */
    int getAccountIndex(const string &accountnr);

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
    bool withdrawFromAccount(string &accountnr, double amount);

    /**
     * deposit a given amount to a given account
     * @param accountnr
     * @param amount
     * @return true if account with given account number is found else false
     */
    bool depositToAccount(string &accountnr, double amount);

    /**
     * set credit to a given amount for a given account
     * @param accountnr
     * @param amount
     * @return true if account with given account number is found else false
     */
    bool changeCredit(string &accountnr, double amount);

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



};

#endif //BANK_SYSTEM1_CUSTOMER_H
