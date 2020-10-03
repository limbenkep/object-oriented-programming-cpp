/*Customer.cpp
* Honorine Lima
* Holi1900
* DT060G_Laboration_3
* 2020-09-27.

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
    int index = getAccountIndex(accountnr);
    return bankAccounts[index]->getBalance();
}


bool Customer::getAccountInfo(string &accountnr, vector<string> &accountData)
{
    int index = getAccountIndex(accountnr);
    if (index > -1)
    {
        bankAccounts[index]->getAccountSummary(accountData);
        return true;
    }
    return false;
}

int Customer::getTotalAsset()
{
    int asset = 0;
    //get the sum of the useables of all the accounts
    for (auto &idx: bankAccounts)
    {
        asset += idx->getUseableAmount();
    }
    return asset;
}

bool Customer::createAccount(int accType)
{
    if (accType == 1)
    {
        return createTransactionAccount();
    } else if (accType == 2)
    {
        return createSavingsAccount();
    } else if (accType == 3)
    {
        return createLongSavingsAccount();
    } else
    {
        return false;
    }

}


bool Customer::createSavingsAccount()
{
    int n = bankAccounts.size();
    if (n < maxSize)
    {
        string accNr = customerId + "_" + to_string(n);
        bankAccounts.push_back(unique_ptr<Account>(new SavingsAccount(accNr)));
        return true;
    }
    return false;
}

bool Customer::createLongSavingsAccount()
{
    int n = bankAccounts.size();
    if (n < maxSize)
    {
        string accNr = customerId + "_" + to_string(n);
        bankAccounts.push_back(unique_ptr<Account>(new LongTermSavingsAccount(accNr)));
        return true;
    }
    return false;
}

bool Customer::createTransactionAccount()
{
    int n = bankAccounts.size();
    if (n < maxSize)
    {
        string accNr = customerId + "_" + to_string(n);
        bankAccounts.push_back(unique_ptr<Account>(new TransactionAccount(accNr)));
        return true;
    }
    return false;
}

bool Customer::deleteAccount(string &accountnr)
{
    //search through vector and if the an account with the given account number is found its iterator is returned.
    //If not found the iterator of the end of the vector is returned
    auto it = find_if(bankAccounts.begin(), bankAccounts.end(),
                      [&accountnr](const unique_ptr<Account> &acc) { return acc->getAccountNr() == accountnr; });
    auto index = -1;
    if (it != bankAccounts.end())//found element
    {
        bankAccounts.erase(it);
        return true;
    }
    return false;
}

int Customer::getAccountIndex(const string &accountnr) const
{
    auto it = find_if(bankAccounts.begin(), bankAccounts.end(),
                      [&accountnr](const unique_ptr<Account> &acc) { return acc->getAccountNr() == accountnr; });
    auto index = -1;
    if (it != bankAccounts.end())
    {
        index = std::distance(bankAccounts.begin(), it);

    }
    return index;
}

bool Customer::withdrawFromAccount(string &accountnr, int amount)
{
    int index = getAccountIndex(accountnr);
    return bankAccounts[index]->withdraw(amount);
}

void Customer::depositToAccount(string &accountnr, int amount)
{
    int index = getAccountIndex(accountnr);
    bankAccounts[index]->deposit(amount);
}

bool Customer::changeCredit(string &accountnr, int amount)
{
    int index = getAccountIndex(accountnr);
    cout << "account index: " << index << endl;
    if (hasCredit(accountnr))
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
    outFile << name << endl << customerId << endl;
    for (auto &account: bankAccounts)
    {
        account->saveToFile(outFile);
    }
    outFile.close();
}

bool Customer::readFromFile(const std::string &personalNumber)
{
    string tmpAccType;
    string tmpAccNr;
    int tmpBalance;
    int tmpCredit;
    int tmpInterest;
    int tmpWithdrawals;
    string filename = personalNumber + ".knt";
    ifstream inFile(filename.c_str());
    if (inFile.is_open())
    {
        getline(inFile, name);
        getline(inFile, customerId);
        while (getline(inFile, tmpAccType))
        {
            if (tmpAccType == "Transaction Account")
            {
                inFile >> tmpAccNr;
                inFile >> tmpBalance;
                inFile >> tmpCredit;
                inFile.get();
                unique_ptr<Account> acc(new TransactionAccount(tmpAccNr));
                acc->setCredit(tmpCredit);
                acc->setBalance(tmpBalance);
                bankAccounts.push_back(std::move(acc));
            } else if (tmpAccType == "Savings Account")
            {
                inFile >> tmpAccNr;
                inFile >> tmpBalance;
                inFile >> tmpInterest;
                inFile >> tmpWithdrawals;
                inFile.get();
                unique_ptr<Account> acc(new SavingsAccount(tmpAccNr, tmpCredit));
                acc->setBalance(tmpBalance);
                acc->setNrOfWithdrawals(tmpWithdrawals);
                bankAccounts.push_back(std::move(acc));
            } else if (tmpAccType == "Long term savings Account")
            {
                inFile >> tmpAccNr;
                inFile >> tmpBalance;
                inFile >> tmpInterest;
                inFile >> tmpWithdrawals;
                inFile.get();
                unique_ptr<Account> acc(new LongTermSavingsAccount(tmpAccNr, tmpCredit));
                acc->setBalance(tmpBalance);
                acc->setNrOfWithdrawals(tmpWithdrawals);
                bankAccounts.push_back(std::move(acc));
            } else
            {
                return false;
            }
        }
        inFile.close();
        return true;

    } else
    {
        return false;
    }
}

bool Customer::getAccountNrs(vector<string> &accNrs) const
{
    if (bankAccounts.empty())
    {
        return false;
    } else
    {
        for (const auto &idx:bankAccounts)
        {
            accNrs.push_back(idx->getAccountNr());
        }
        return true;
    }
}


bool Customer::getSummary(vector<string> &accountNrs, vector<vector<int>> &summary)
{
    if (bankAccounts.empty())
    {
        return false;
    } else
    {
        for (const auto &idx:bankAccounts)
        {
            accountNrs.push_back(idx->getAccountNr());
            vector<int> accountData;
            double temp;
            temp = idx->getBalance();
            accountData.push_back(temp);
            temp = idx->getCredit();
            accountData.push_back(temp);
            temp = idx->getUseableAmount();
            accountData.push_back(temp);
            summary.push_back(accountData);
        }
        return true;
    }
}

bool Customer::useableSummary(vector<string> &accountNrs, vector<int> &summary)
{
    if (bankAccounts.empty())
    {
        return false;
    } else
    {
        for (const auto &idx:bankAccounts)
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
    return bankAccounts[index]->getAccountType();
}

bool Customer::hasCredit(string &accountNr) const
{
    int index = getAccountIndex(accountNr);
    return bankAccounts[index]->hasCredit();
}

bool Customer::hasInterest(string &accountNr) const
{
    int index = getAccountIndex(accountNr);
    return bankAccounts[index]->hasInterest();
}

bool Customer::hasMaxWithdrawals(string &accountNr)
{
    int index = getAccountIndex(accountNr);
    return bankAccounts[index]->hasMaxWithdrawals();
}

bool Customer::accountExist(string &accountNr) const
{
    int index = getAccountIndex(accountNr);
    return index > -1;
}

int Customer::getInterest(string &accountNr) const
{
    int index = getAccountIndex(accountNr);
    if (bankAccounts[index]->hasInterest())
    {
        return bankAccounts[index]->getInterest();
    }
    return 0;
}

int Customer::getNrOfWithdrawals(string &accountNr) const
{
    int index = getAccountIndex(accountNr);
    return bankAccounts[index]->getNrOfWithdrawals();
}

int Customer::getMaxWithdrawals(string &accountNr) const
{
    int index = getAccountIndex(accountNr);
    return bankAccounts[index]->getMaxWithdrawals();
}

bool Customer::getSummaryToPrint(vector<vector<string>> &summary)
{
    if (bankAccounts.empty())
    {
        return false;
    } else
    {
        for (const auto &idx:bankAccounts)
        {
            vector<string> accountData;
            idx->getAccountSummary(accountData);
            summary.push_back(accountData);
        }
        return true;
    }
}

