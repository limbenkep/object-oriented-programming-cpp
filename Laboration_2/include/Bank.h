//
// Created by limbe on 2020-09-19.
//

#ifndef BANK_SYSTEM1_BANK_H
#define BANK_SYSTEM1_BANK_H
#include "Customer.h"

class Bank
{
private:
    unique_ptr<Customer>client;

public:
    Bank();

    virtual ~Bank();
    void createCustumer(string &name, string &persNr);
    bool createNewAccount();
    bool getAccountNrs(vector<string>&vec)const ;
    bool deleteAnAccount(string &accountnr);
    double totalAsset();
    int NrofAccounts();
    bool accountInfo(string &accountnr, vector<double>&accountData);
    bool clientSummery(vector<string> &accountNrs, vector<vector<double>>&summary);
    bool accountsUseables(vector<string> &accountNrs, vector<double> &summary);
    string getClientName();
    string getClientID();
    bool withdraw(string &accountnr, double amount);
    bool deposit(string &accountnr, double amount);
    bool changeAccCredit(string &accountnr, double amount);
    void saveClientToFile();
    bool readClientFromFile();


    /*double accountBalance(const string &accountnr);
    accountInfo accountInfo(string &accountnr);
    const double accountcredit(const string accountnr);
    const double getAccountuseable(const string accountnr);
    double totalAsset();
    void createNewAccount();
    int getAccountIndex(const string &accountnr);

    void withdraw(string &accountnr, double amount);
    void deposit(string &accountnr, double amount);
    void changeAccCredit(string &accountnr, double amount);
    int NrofAccounts();
    void printAccountSummary();
    void saveClientToFile();
    bool readClientFromFile();
    void createCustumer();
    void showMenu();*/


};


#endif //BANK_SYSTEM1_BANK_H
