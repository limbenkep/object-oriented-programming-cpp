//
// Created by limbe on 2020-09-19.
//

#ifndef BANK_SYSTEM1_USERINTERFACE_H
#define BANK_SYSTEM1_USERINTERFACE_H
#include "Bank.h"

class userInterface
{
private:
    unique_ptr<Bank>bank;

    char getChoice();
    void createNewClient();
    void saveCustomerToFile();
    void readCustomerFromFile();
public:
    userInterface();

    virtual ~userInterface();

    void run();

};


#endif //BANK_SYSTEM1_USERINTERFACE_H
