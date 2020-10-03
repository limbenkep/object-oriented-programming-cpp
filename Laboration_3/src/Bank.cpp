/*Bank.cpp
* Honorine Lima
* Holi1900
* DT060G_Laboration_3
* 2020-09-27.

#include "Bank.h"

Bank::Bank()
{
   // client = unique_ptr<Customer>();
}

Bank::~Bank()
{

}

void Bank::createCustumer(string &name, string &persNr)
{
    client = unique_ptr<Customer>(new Customer(name, persNr));
}

bool Bank::getAccountNrs(vector<string> &accountNrs) const
{
    return client->getAccountNrs(accountNrs);
}

bool Bank::createNewAccount(int accType)
{
    return client->createAccount(accType);;
}

bool Bank::deleteAnAccount(string &accountnr)
{
    return client->deleteAccount(accountnr);

}

int Bank::totalAsset()
{
    return client->getTotalAsset();
}

int Bank::NrofAccounts()
{
    return client->getNrofAccounts();
}

bool Bank::accountInfo(string &accountnr, vector<string> &accountData)
{
    return client->getAccountInfo(accountnr, accountData);
}

bool Bank::clientSummery(vector<string> &accountNrs, vector<vector<int>> &summary)
{
    return client->getSummary(accountNrs, summary);
}

string Bank::getClientName()
{
    return client->getName();
}

string Bank::getClientID()
{
    return client->getCustomerId();
}

bool Bank::withdraw(string &accountnr, int amount)
{
    return client->withdrawFromAccount(accountnr, amount);
}

void Bank::deposit(string &accountnr, int amount)
{
    return client->depositToAccount(accountnr, amount);

}

bool Bank::changeAccCredit(string &accountnr, int amount)
{
    return client->changeCredit(accountnr, amount);

}

void Bank::saveClientToFile()
{
    client->saveToFile();
    destroyCustomer();
}

bool Bank::readClientFromFile(const string &personalNumber)
{
    if(client== nullptr){
        client = unique_ptr<Customer>(new Customer);
    }
    return client->readFromFile(personalNumber);
}

bool Bank::accountsUseables(vector<string> &accountNrs, vector<int> &summary)
{
    return client->useableSummary(accountNrs, summary);
}

string Bank::getAccType(string &accountNr)
{
    return client->getAccountType(accountNr);
}

bool Bank::accountExist(string &accountNr) const
{
    return client->accountExist(accountNr);
}

bool Bank::hasCredit(string &accountNr) const
{
    return client->hasCredit(accountNr);
}

bool Bank::hasInterest(string &accountNr) const
{
    return client->hasInterest(accountNr);
}

bool Bank::hasMaxWithdrawals(string &accountNr)
{
    return client->hasMaxWithdrawals(accountNr);
}

int Bank::getInterest(string &accountNr) const
{
    return client->getInterest(accountNr);
}

int Bank::getNrOfWithdrawals(string &accountNr) const
{
    return client->getNrOfWithdrawals(accountNr);
}

int Bank::getMaxWithdrawals(string &accountNr) const
{
    return client->getMaxWithdrawals(accountNr);
}

bool Bank::getSummaryToPrint(vector<vector<string>> &summary)
{
    return client->getSummaryToPrint(summary);
}

void Bank::destroyCustomer()
{
    if(client != nullptr){
       client.reset();
    }
}

