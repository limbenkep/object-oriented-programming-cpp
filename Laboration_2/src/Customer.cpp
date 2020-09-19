//
// Created by limbe on 2020-09-07.
//

#include "Customer.h"


Customer::Customer()
{
    name = "";
    customerId = "";
}

Customer::Customer(const string &pName, const string &pCustomerId) : name(pName), customerId(pCustomerId)
{

}

Customer::~Customer()
{

}


const string &Customer::getName() const
{
    return name;
}

void Customer::setName(const string &pName)
{
    Customer::name = pName;
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
        cout << "account found in getAccbalance" <<endl;
        auto index = std::distance(bankAccounts.begin(), it);
        return bankAccounts[index] ->getBalance();
    } else{
        cout << "account Not found in getAccbalance" <<endl;
        return -1;
    }
}



Account Customer::getAccountInfo(string &accountnr)
{
    auto it = find_if(bankAccounts.begin(), bankAccounts.end(), [&accountnr]( const unique_ptr<Account>& acc){return acc->getAccountNr() == accountnr;});
    Account data;
    if (it != bankAccounts.end())
    {

        // found element. it is an iterator to the first matching element.
        // if you really need the index, you can also get it:
        auto index = std::distance(bankAccounts.begin(), it);
        data = Account(bankAccounts[index] ->getAccountNr(),bankAccounts[index] ->getBalance(), bankAccounts[index] ->getCredit());
/*
        data.sAccNr = bankAccounts[index] ->getAccountNr();
        data.sBalance = bankAccounts[index] ->getBalance();
        data.sCredit = bankAccounts[index] ->getCredit();
        data.sUseable = bankAccounts[index] ->getUseableAmount();
*/

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
        bankAccounts.push_back(unique_ptr<Account>(new Account(accNr) ));
        cout << "my accnr: " << bankAccounts[0]->getAccountNr() << endl;
        cout << "Account number: " << accNr <<endl;
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
    if(index>-1)
    {
        bankAccounts[index]->withdraw(amount);
    }
}

void Customer::depositToAccount(string &accountnr, double amount)
{
    int index = getAccountIndex(accountnr);
    if(index>-1)
    {
        bankAccounts[index]->deposit(amount);
    }
    else {
        cout << "account not found" <<endl;
    }

}

void Customer::changeCredit(string &accountnr, double amount)
{
    int index = getAccountIndex(accountnr);
    cout<< "account index: "<<index<<endl;
    if(index>-1)
    {
        bankAccounts[index]->setCredit(amount);
    }
}

int Customer::getNrofAccounts()
{
    return bankAccounts.size();
}

void Customer::saveToFile()
{
    ofstream outFile(customerId + ".knt");
    outFile << name << endl << customerId <<endl;
    for(auto &idx: bankAccounts)
    {
        outFile<< idx->getAccountNr() << endl
        <<idx->getBalance() << endl
        <<idx->getCredit() << endl;

    }
    outFile.close();

}

bool Customer::readFromFile()
{
    string tmpAccNr;
    double tmpBalance;
    double tmpCredit;
    ifstream inFile(customerId + ".knt");
    if(inFile.is_open())
    {
        getline(inFile, name);
        getline(inFile, customerId);
        while (getline(inFile, tmpAccNr))
        {
            inFile>>tmpBalance;
            inFile>>tmpCredit;
            inFile.get();

            bankAccounts.push_back(unique_ptr<Account>(new Account(tmpAccNr, tmpBalance, tmpCredit)));
        }
        inFile.close();
        return true;

    } else{
        return false;
    }
}




