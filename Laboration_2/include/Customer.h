//
// Created by limbe on 2020-09-07.
//

#ifndef BANK_SYSTEM1_CUSTOMER_H
#define BANK_SYSTEM1_CUSTOMER_H
#include "Account.h"
#include <memory>
#include <vector>
#include <algorithm>
/**
 * This is a dummy prototype used only to enforce proper file structure,
 * as Git doesn't allow empty folders to be pushed to remote origin.
 * Remove this dummy function before submission.
 */
struct accountInfo {
    string sAccNr;
    double sBalance;
    double sCredit;
    double sUseable;
};


class Customer
{
private:
    vector<unique_ptr<Account>>bankAccounts; //Vector with pointer to customer's accounts
    string name;
    string customerId;

    const int maxSize = 3;

public:
    Customer();
    Customer(const string &name, const string &customerId);

    virtual ~Customer();

    const string &getName() const;

    void setName(const string &pName);

    const string &getCustomerId() const;

    void setCustomerId(const string &customerId);

    const vector<unique_ptr<Account>> &getBankAccounts() const;


    double getAccountBalance(const string &accountnr);
    Account getAccountInfo(string &accountnr);
    const double getAccountcredit(const string accountnr);
    const double getAccountuseable(const string accountnr);
    double getTotalAsset();
    void createAccount();
    int getAccountIndex(const string &accountnr);
    void deleteAccount(string &accountnr);
    void withdrawFromAccount(string &accountnr, double amount);
    void depositToAccount(string &accountnr, double amount);
    void changeCredit(string &accountnr, double amount);
    int getNrofAccounts();
    void saveToFile();
    bool readFromFile();


};

#endif //BANK_SYSTEM1_CUSTOMER_H
