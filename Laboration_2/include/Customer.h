//
// Created by limbe on 2020-09-07.
//

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

    const string &getName() const;

    void setName(const string &pName);

    const string &getCustomerId() const;

    void setCustomerId(const string &customerId);

    const vector<unique_ptr<Account>> &getBankAccounts() const;


    double getAccountBalance(const string &accountnr);
    bool getAccountInfo(string &accountnr, vector<double>&accountData);
    bool getSummary(vector<string> &accountNrs, vector<vector<double>>&summary);
    bool useableSummary(vector<string> &accountNrs, vector<double>&summary);
    //const double getAccountcredit(const string accountnr);
    //const double getAccountuseable(const string accountnr);
    double getTotalAsset();
    bool createAccount();
    int getAccountIndex(const string &accountnr);
    bool deleteAccount(string &accountnr);
    bool withdrawFromAccount(string &accountnr, double amount);
    bool depositToAccount(string &accountnr, double amount);
    bool changeCredit(string &accountnr, double amount);
    int getNrofAccounts();
    bool getAccountNrs(vector<string>&vec)const;
    void saveToFile();
    bool readFromFile();



};

#endif //BANK_SYSTEM1_CUSTOMER_H
