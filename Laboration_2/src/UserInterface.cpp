//
// Created by limbe on 2020-09-19.
//

#include "UserInterface.h"

UserInterface::UserInterface()
{
    bank = unique_ptr<Bank>(new Bank());
}

UserInterface::~UserInterface()
{

}

char UserInterface::getChoice()
{
    cout << "\nmake your choice: ";
    char choice;
    cin >> choice;
    return choice;
}

void UserInterface::run()
{
    cout << "\n1. Load customer from file. \n2. create a new customer. \n3. Quit." << endl;

    char options[] = {'1', '2', '3'};//valid menu choices
    char choice{'a'};//initialise choice to an unexpected value
    bool valid = false;
    while (!valid)
    {
        choice = getChoice();
        for (auto &option : options) // using range-base for loop. same as for(int i=0; i<8; i++)...if(options[i]==choice)
        {
            if (option == choice)
            {
                valid = true;
            }
        }
        if (!valid)
        {
            cout << "Invalid choice." << endl;
        }
    }

    bool again = true;
    while (again)
    {
        switch (choice)
        {
            case '1':
                readCustomerFromFile();
                break;
            case '2':
                createNewClient();
                break;
            case '3':
                again = false;
            default:
                cout << "\nInvalid choice." << endl;
                break;
        }
    }
}

void UserInterface::createNewClient()
{
    string name;

    cout << "\nEnter customer's first name and last name: ";
    getline(cin, name);
    while (name.empty())
    {
        cout << "\nEmpty entries are not allowed.\nEnter customer's first name and last name: ";
        getline(cin, name);
    }
    cout << "\nEnter customer's personnummer: ";
    string personNr;
    getline(cin, personNr);
    cout << "read persnr " << personNr;
    while (personNr.empty())
    {
        cout << "\nEmpty entries are not allowed.\nEnter customer's personnummer: ";
        getline(cin, personNr);
    }
    bank->createCustumer(name, personNr);
    cout << "The client " << bank->getClientName() << " has been created" << endl;
}

void UserInterface::saveCustomerToFile()
{
    bank->saveClientToFile();
    cout << "\nCustomer saved to file" << endl;
}

void UserInterface::readCustomerFromFile()
{
    if (bank->readClientFromFile())
    {
        cout << "Customer successfully read from file" << endl;
    } else
    {
        cout << "Reading customer from file was unsuccessful." << endl;
    }
}

void UserInterface::printCustomerName()
{
    cout << "Customer's name is " << bank->getClientName() << endl;
}

void UserInterface::printPersNr()
{
    cout << "Customer's personal number is " << bank->getClientID() << endl;
}

void UserInterface::printNrofAccounts()
{
    cout << "You have " << bank->NrofAccounts() << " account(s)." << endl;
}

void UserInterface::printTotalAsset()
{
    cout << "Your total asset is " << bank->totalAsset() << "kr." << endl;
}

void UserInterface::printAccountInfo()
{
    vector<string> accNrs;
    if (bank->getAccountNrs(accNrs))
    {
        cout << "\nYour account(s):" << endl;
        for (const auto &idx: accNrs)
        {
            cout << idx << endl;
        }
        cout << "\nEnter the account number of the account you want a summary for:" << endl;
    } else
    {
        cout << "No accounts Found." << endl;
    }
}

void UserInterface::withdrawfromAccount()
{
    string message1 = "From which account do you want to withdraw: ";
    string accountNr = chooseAccountNr(message1);
    string message2 = "Amount to withdraw: ";
    double amount = getADouble(message2);

    bank->withdraw(accountNr, amount);
}

void UserInterface::depositToAccount()
{
    string message1 = "To which account do you want to deposit: ";
    string accountNr = chooseAccountNr(message1);
    string message2 = "Amount to deposit: ";
    double amount = getADouble(message2);

    if(bank->deposit(accountNr, amount))
    {
        cout << amount << "Has been deposited in account " << accountNr << endl;
    } else{
        cout << "Account not found" << endl;
    }
}

void UserInterface::setCredit()
{
    string message1 = "To which account do you want to set credit: ";
    string accountNr = chooseAccountNr(message1);
    string message2 = "How much do you want on the account: ";
    double amount = getADouble(message2);
    if(bank->changeAccCredit(accountNr, amount))
    {
        cout << amount << "Credit has been set to account " << accountNr << endl;
    } else{
        cout << "Account not found" << endl;
    }
}

string UserInterface::chooseAccountNr(string &message)
{
    string accNumber;
    vector<string> accNrs;
    if (bank->getAccountNrs(accNrs))
    {
        cout << "\nYour account(s):" << endl;
        for (const auto &idx: accNrs)
        {
            cout << idx << endl;
        }
        cout << message;
        getline(cin, accNumber);
        vector<string>::iterator it;
        it = find(accNrs.begin(), accNrs.end(), accNumber);
        while (it == accNrs.end())
        {
            cout << "\nInvalid account Number.\n" << message;
            getline(cin, accNumber);
            it = find(accNrs.begin(), accNrs.end(), accNumber);
        }
    } else
    {
        cout << "No accounts Found." << endl;
    }
    return accNumber;
}

double UserInterface::getADouble(string &message)
{
    cout << message;
    double value;
    cin >> value;
    while(!cin || value<0)
    {
        cout <<"Invalid amount. Amount must be a positive number" <<endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cout << message;
        cin >> value;
    }
    cin.ignore(10000,'\n');
    return value;
}

void UserInterface::createAccount()
{
    if(bank->createNewAccount())
    {
        cout << "\nA new account has been created." << endl;
    }
    else{
        cout << "\nYou already have the maximum number of accounts." << endl;
    }
}






