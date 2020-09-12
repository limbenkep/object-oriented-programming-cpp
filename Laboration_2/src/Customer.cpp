//
// Created by limbe on 2020-09-07.
//

#include "Customer.h"


Customer::Customer()
{
    firstName = "";
    lastName = "";
    customerId = "";
}

Customer::Customer(const string &pLastName, const string &pFirstName, const string &pCustomerId) : lastName(pLastName),
                                                                                                firstName(pFirstName),
                                                                                                customerId(pCustomerId)
{

}

const string &Customer::getLastName() const
{
    return lastName;
}

void Customer::setLastName(const string &pLastName)
{
    Customer::lastName = pLastName;
}

const string &Customer::getFirstName() const
{
    return firstName;
}

void Customer::setFirstName(const string &pFirstName)
{
    Customer::firstName = pFirstName;
}

const string &Customer::getCustomerId() const
{
    return customerId;
}

void Customer::setCustomerId(const string &pCustomerId)
{
    Customer::customerId = pCustomerId;
}

const vector<unique_ptr<Account>> &Customer::getBankAccounts() const
{
    return bankAccounts;
}

double Customer::getAccountBalance(const string &accountnr)
{
    auto it = find_if(bankAccounts.begin(), bankAccounts.end(), [&accountnr](const unique_ptr<Account>& acc){return acc->getAccountNr() == accountnr;});
    if (it != bankAccounts.end())
    {
        // found element. it is an iterator to the first matching element.
        // if you really need the index, you can also get it:
        auto index = std::distance(bankAccounts.begin(), it);
        return bankAccounts[index] ->getBalance();
    } else{
        return -1;
    }
}



accountInfo Customer::getAccountInfo(string &accountnr)
{
    auto it = find_if(bankAccounts.begin(), bankAccounts.end(), [&accountnr](const unique_ptr<Account>& acc){return acc->getAccountNr() == accountnr;});
    accountInfo data;
    if (it != bankAccounts.end())
    {
        // found element. it is an iterator to the first matching element.
        // if you really need the index, you can also get it:
        auto index = std::distance(bankAccounts.begin(), it);
        data.sAccNr = bankAccounts[index] ->getAccountNr();
        data.sBalance = bankAccounts[index] ->getBalance();
        data.sCredit = bankAccounts[index] ->getCredit();
        data.sUseable = bankAccounts[index] ->getUseableAmount();

    }
    else{
        data.sAccNr = "";
        data.sBalance = 0;
        data.sCredit = 0;
        data.sUseable = 0;
    }
    return data;
}

double Customer::getTotalAsset()
{
    double asset = 0;
    //get the sum of the useables of all the accounts
    for(auto &idx: bankAccounts)
    {
        asset+=idx->getUseableAmount();
    }
    return asset;
}

void Customer::createAccount()
{
    int n = bankAccounts.size();
    if(n<maxSize)
    {
        string accNr = customerId + "_" + to_string(n);
        bankAccounts.push_back(unique_ptr<Account>p(new Account(accNr) ));
    }

}

void Customer::deleteAccount(string &accountnr)
{
    //search through vector and if the an account with the given account number is found its iterator is returned.
    //If not found the iterator of the end of the vector is returned
    auto it = find_if(bankAccounts.begin(), bankAccounts.end(), [&accountnr](const unique_ptr<Account>& acc){return acc->getAccountNr() == accountnr;});
    auto index  = -1;
    if (it != bankAccounts.end())//found element
    {
        bankAccounts.erase(it);
    }
}

int Customer::getAccountIndex(const string &accountnr)
{
    auto it = find_if(bankAccounts.begin(), bankAccounts.end(), [&accountnr](const unique_ptr<Account>& acc){return acc->getAccountNr() == accountnr;});
    auto index  = -1;
    if (it != bankAccounts.end())
    {
        index = std::distance(bankAccounts.begin(), it);

    }
    return index;
}

void Customer::withdrawFromAccount(string &accountnr, double amount)
{
    int index = getAccountIndex(accountnr);
    if(index>0)
    {
        bankAccounts[index]->withdraw(amount);
    }
}

void Customer::depositToAccount(string &accountnr, double amount)
{
    int index = getAccountIndex(accountnr);
    if(index>0)
    {
        bankAccounts[index]->deposit(amount);
    }

}

void Customer::changeCredit(string &accountnr, double amount)
{
    int index = getAccountIndex(accountnr);
    if(index>0)
    {
        bankAccounts[index]->setCredit(amount);
    }
}

