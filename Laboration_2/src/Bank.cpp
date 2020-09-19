//
// Created by limbe on 2020-09-19.
//

#include "Bank.h"

Bank::Bank()
{
}

Bank::~Bank()
{

}

void Bank::createCustumer(const string &name, const string &persNr)
{
    client = unique_ptr<Customer>(new Customer(name, persNr));
}

bool Bank::getAccountNrs(vector<string> &accountNrs) const
{
    return client->getAccountNrs(accountNrs);
}

bool Bank::createNewAccount()
{
    return client->createAccount();;
}

bool Bank::deleteAnAccount(string &accountnr)
{
    return client->deleteAccount(accountnr);

}

double Bank::totalAsset()
{
    return client->getTotalAsset();
}

int Bank::NrofAccounts()
{
    return client ->getNrofAccounts();
}

bool Bank::accountInfo(string &accountnr, vector<double> &accountData)
{
    return client->getAccountInfo(accountnr, accountData);
}

bool Bank::clientSummery(vector<string> &accountNrs, vector<vector<double>> &summary)
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

bool Bank::withdraw(string &accountnr, double amount)
{
    return client ->withdrawFromAccount(accountnr, amount);
}

bool Bank::deposit(string &accountnr, double amount)
{
    return client->depositToAccount(accountnr, amount);

}

bool Bank::changeAccCredit(string &accountnr, double amount)
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

bool Bank::accountsUseables(vector<string> &accountNrs, vector<double> &summary)
{
    return client->useableSummary(accountNrs, summary);
}


