//
// Created by limbe on 2020-09-19.
//

#ifndef BANK_SYSTEM1_USERINTERFACE_H
#define BANK_SYSTEM1_USERINTERFACE_H
#include "Bank.h"

class UserInterface
{
private:
    unique_ptr<Bank>bank;
public:
    char getChoice();
    void createNewClient();
    void saveCustomerToFile();
    void readCustomerFromFile();
    void printCustomerName();
    void printPersNr();
    void printNrofAccounts();
    void printTotalAsset();
    void printAccountInfo();
    void withdrawfromAccount();
    void depositToAccount();
    void setCredit();
    void printAccountsSummary();
    void createAccount();
    void deleteAccount();
    void changeCustomer();
    string chooseAccountNr(string &message);
    double getADouble(string &message);

public:
    UserInterface();

    virtual ~UserInterface();

    void run();

};


#endif //BANK_SYSTEM1_USERINTERFACE_H
