//
// Created by limbe on 2020-09-28.
//

#include "Bank.h"

Bank::Bank()
{
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
    return client ->getNrofAccounts();
}

bool Bank::accountInfo(string &accountnr, vector<int> &accountData)
{
    return client->getAccountInfo(accountnr, accountData);
}

bool Bank::clientSummery(vector<string> &accountNrs, vector<vector<int>> &summary)
{
    return client->getSummary(accountNrs,summary);
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
    return client ->withdrawFromAccount(accountnr, amount);
}

bool Bank::deposit(string &accountnr, int amount)
{
    return client->depositToAccount(accountnr, amount);

}

bool Bank::changeAccCredit(string &accountnr, int amount)
{
    return client->changeCredit(accountnr, amount);

}

void Bank::saveClientToFile()
{
    client ->saveToFile();

}

bool Bank::readClientFromFile()
{
    return client->readFromFile();
}

bool Bank::accountsUseables(vector<string> &accountNrs, vector<int> &summary)
{
    return client->useableSummary(accountNrs, summary);
}

string Bank::getAccType(string &accountNr)
{
    return client->getAccountType(accountNr);
}

