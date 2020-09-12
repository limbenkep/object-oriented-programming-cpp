//
// Created by limbe on 2020-09-07.
//

#ifndef BANK_SYSTEM1_CUSTOMER_H
#define BANK_SYSTEM1_CUSTOMER_H
#include "Account.h"
#include "Prototypes.h"
#include <memory>
#include <vector>
#include <algorithm>



class Customer
{
private:
    vector<unique_ptr<Account>>bankAccounts; //Vector with pointer to customer's accounts
    string lastName;
    string firstName;
    string customerId;

    const int maxSize = 3;

public:
    Customer();

public:
    Customer(const string &lastName, const string &firstName, const string &customerId);

    const string &getLastName() const;

    void setLastName(const string &lastName);

    const string &getFirstName() const;

    void setFirstName(const string &firstName);

    const string &getCustomerId() const;

    void setCustomerId(const string &customerId);

    const vector<unique_ptr<Account>> &getBankAccounts() const;

    double getAccountBalance(const string &accountnr);
    accountInfo getAccountInfo(string &accountnr);
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


};

#endif //BANK_SYSTEM1_CUSTOMER_H
