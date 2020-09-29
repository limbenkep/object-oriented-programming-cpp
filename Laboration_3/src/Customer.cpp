//
// Created by limbe on 2020-09-27.
//

#include "Customer.h"

Customer::Customer(const string &pName, const string &pCustomerId) : name(pName), customerId(pCustomerId)
{

}

Customer::~Customer()
= default;


const string &Customer::getName() const
{
    return name;
}

const string &Customer::getCustomerId() const
{
    return customerId;
}

int Customer::getAccountBalance(const string &accountnr)
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



bool Customer::getAccountInfo(string &accountnr, vector<int>&accountData)
{
    auto it = find_if(bankAccounts.begin(), bankAccounts.end(), [&accountnr]( const unique_ptr<Account>& acc){return acc->getAccountNr() == accountnr;});

    if (it != bankAccounts.end())
    {
        // found element. it is an iterator to the first matching element.
        // if you really need the index, you can also get it:
        auto index = std::distance(bankAccounts.begin(), it);
        accountData.push_back(bankAccounts[index] ->getBalance());
        accountData.push_back(bankAccounts[index] ->getCredit());
        accountData.push_back(bankAccounts[index] ->getUseableAmount());
        return true;
    }
    return false;
}

int Customer::getTotalAsset()
{
    int asset = 0;
    //get the sum of the useables of all the accounts
    for(auto &idx: bankAccounts)
    {
        asset+=idx->getUseableAmount();
    }
    return asset;
}
bool Customer::createAccount(int accType)
{
    if(accType==1)
    {
        return createTransactionAccount();
    }
    else if(accType==2)
    {
        return createSavingsAccount();
    }
    else if(accType==3)
    {
        return createLongSavingsAccount();
    }
    else
    {
        return false;
    }

}


bool Customer::createSavingsAccount()
{
    int n = bankAccounts.size();
    if(n<maxSize)
    {
        string accNr = customerId + "_" + to_string(n);
        bankAccounts.push_back(unique_ptr<Account>(new SavingsAccount(accNr) ));
        cout << "my accnr: " << bankAccounts[0]->getAccountNr() << endl;
        cout << "Account number: " << accNr <<endl;
        return true;
    }
    return false;
}

bool Customer::createLongSavingsAccount()
{
    int n = bankAccounts.size();
    if(n<maxSize)
    {
        string accNr = customerId + "_" + to_string(n);
        bankAccounts.push_back(unique_ptr<Account>(new LongTermSavingsAccount(accNr)));
        cout << "my accnr: " << bankAccounts[0]->getAccountNr() << endl;
        cout << "Account number: " << accNr <<endl;
        return true;
    }
    return false;
}

bool Customer::createTransactionAccount()
{
    int n = bankAccounts.size();
    if(n<maxSize)
    {
        string accNr = customerId + "_" + to_string(n);
        bankAccounts.push_back(unique_ptr<Account>(new TransactionAccount(accNr) ));
        cout << "my accnr: " << bankAccounts[0]->getAccountNr() << endl;
        cout << "Account number: " << accNr <<endl;
        return true;
    }
    return false;
}
bool Customer::deleteAccount(string &accountnr)
{
    //search through vector and if the an account with the given account number is found its iterator is returned.
    //If not found the iterator of the end of the vector is returned
    auto it = find_if(bankAccounts.begin(), bankAccounts.end(), [&accountnr](const unique_ptr<Account>& acc){return acc->getAccountNr() == accountnr;});
    auto index  = -1;
    if (it != bankAccounts.end())//found element
    {
        bankAccounts.erase(it);
        return true;
    }
    return false;
}

int Customer::getAccountIndex(const string &accountnr) const
{
    auto it = find_if(bankAccounts.begin(), bankAccounts.end(), [&accountnr](const unique_ptr<Account>& acc){return acc->getAccountNr() == accountnr;});
    auto index  = -1;
    if (it != bankAccounts.end())
    {
        index = std::distance(bankAccounts.begin(), it);

    }
    return index;
}

bool Customer::withdrawFromAccount(string &accountnr, int amount)
{
    int index = getAccountIndex(accountnr);
    if(index>-1)
    {
        return bankAccounts[index]->withdraw(amount);
    }
    return false;
}

bool Customer::depositToAccount(string &accountnr, int amount)
{
    int index = getAccountIndex(accountnr);
    if(index>-1)
    {
        bankAccounts[index]->deposit(amount);
        return true;
    }
    else {

        return false;
    }

}

bool Customer::changeCredit(string &accountnr, int amount)
{
    int index = getAccountIndex(accountnr);
    cout<< "account index: "<<index<<endl;
    if(index>-1)
    {
        bankAccounts[index]->setCredit(amount);
        return true;
    }
    return false;
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
   /* string tmpAccNr;
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
    }*/
    return false;
}

bool Customer::getAccountNrs(vector<string> &accNrs) const
{
    if(bankAccounts.empty())
    {
        return false;
    }
    else{
        for(const auto &idx:bankAccounts)
        {
            accNrs.push_back(idx->getAccountNr());
        }
        return true;
    }

}


bool Customer::getSummary(vector<string> &accountNrs, vector<vector<int>> &summary)
{
    if(bankAccounts.empty())
    {
        return false;
    }
    else{
        for(const auto &idx:bankAccounts)
        {
            accountNrs.push_back(idx->getAccountNr());
            vector<int>accountData;
            double temp;
            temp = idx ->getBalance();
            accountData.push_back(temp);
            temp = idx ->getCredit();
            accountData.push_back(temp);
            temp = idx ->getUseableAmount();
            accountData.push_back(temp);
            summary.push_back(accountData);

        }
        return true;
    }
}

bool Customer::useableSummary(vector<string> &accountNrs, vector<int> &summary)
{
    if(bankAccounts.empty())
    {
        return false;
    }
    else{
        for(const auto &idx:bankAccounts)
        {
            accountNrs.push_back(idx->getAccountNr());
            summary.push_back(idx->getUseableAmount());
        }
        return true;
    }
}

string Customer::getAccountType(const string &accountnr)
{
    int index = getAccountIndex(accountnr);
    cout<< "account index: "<<index<<endl;
    if(index>-1)
    {
        return bankAccounts[index]->getAccountType();
    }
    return "error";
}

bool Customer::hasCredit(string &accountNr) const
{
    int index = getAccountIndex(accountNr);
    if(index>-1)
    {
        return bankAccounts[index]->hasCredit();
    }
    else {

        return false;
    }
}

bool Customer::hasInterest(string &accountNr) const
{
    int index = getAccountIndex(accountNr);
    if(index>-1)
    {
        return bankAccounts[index]->hasInterest();
    }
    else {

        return false;
    }
}

bool Customer::hasMaxWithdrawals(string &accountNr)
{
    int index = getAccountIndex(accountNr);
    if(index>-1)
    {
        return bankAccounts[index]->hasMaxWithdrawals();
    }
    else {

        return false;
    }
}

