//
// Created by limbe on 2020-09-28.
//

#include "UserInterface.h"

UserInterface::UserInterface()
{
    bank = unique_ptr<Bank>(new Bank());
    done = false;
}

UserInterface::~UserInterface()
{

}

int UserInterface::getMenuChoice(int menu)
{
    vector<int>options;
    if(menu ==1)
    {
        printStartMenu();
        options={1,2,3};
    }
    if(menu==2)
    {
        printMenu();
        options={1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    }
    if(menu==3)
    {
        options={1,2,3};
    }
    cout << "\nmake your choice: ";
    int value;
    int n = options.size();
    cin >> value;
    while(!cin || value<0||value>n)
    {
        cout <<"Invalid choice. choice must be a number between 1 and " << n << "\nmake your choice: " << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cin >> value;
    }
    cin.ignore(10000,'\n');
    return value;
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
    executeMenuOptions();
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
        executeMenuOptions();
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
    string message = "\nEnter the account number of the account you want a summary for: ";
    string accaountNr = chooseAccountNr(message);
    vector<int>accInfo;
    if(bank->accountInfo(accaountNr, accInfo))
    {
        cout << "\nAccount balance: " << accInfo[0];
        cout << "\nAccount credit: " << accInfo[1];
        cout << "\nAccount disposable: " << accInfo[2];
    }
    else{
        cout << "Account Number not found.";
    }
}

void UserInterface::withdrawfromAccount()
{
    string message1 = "From which account do you want to withdraw: ";
    string accountNr = chooseAccountNr(message1);
    string message2 = "Amount to withdraw: ";
    int amount = getPositiveInt(message2);

    bank->withdraw(accountNr, amount);
}

void UserInterface::depositToAccount()
{
    string message1 = "To which account do you want to deposit: ";
    string accountNr = chooseAccountNr(message1);
    string message2 = "Amount to deposit: ";
    int amount = getPositiveInt(message2);

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
    int amount = getPositiveInt(message2);
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

int UserInterface::getPositiveInt(string &message)
{
    cout << message;
    int value;
    cin >> value;
    while(!cin || value<0)
    {
        cout <<"Entry must be a positive number" <<endl;
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
    cout <<"=======Account Types=================="
    <<"\n1. Transaction account.\n2. Savings account.\n3. Long term savings account."
    << "\nWhat type of account do you wish to create";
    int menuNr = 3;//3 is used to identipy the account type menu in the getMenuChoice function
    int accType = getMenuChoice(menuNr);
    if(bank->createNewAccount(accType))
    {
        cout << "\nA new account has been created." << endl;
    }
    else{
        cout << "\nYou already have the maximum number of accounts." << endl;
    }
}

void UserInterface::printAccountNrs()
{
    vector<string>accNrs;
    if(bank->getAccountNrs(accNrs))
    {
        cout << "\nYour account(s): " << endl;
        for(const auto &idx: accNrs)
        {
            cout << idx << endl;
        }
    }
    else{
        cout << "\nYou have no accounts." <<endl;
    }
}

void UserInterface::printAccountsSummary()
{
    int n = bank->NrofAccounts();
    vector<string>accNrs;
    vector<vector<int>>data;
    if(bank->clientSummery(accNrs, data))
        for(int i=0; i<n; i++)
        {
            cout << "\n====" << accNrs[i] << "====";
            cout << "\nBalance: " << data[i][0];
            cout << "\nCredit: " << data[i][1];
            cout << "\nDisposables: " << data[i][2];
        }

}

void UserInterface::deleteAccount()
{
    string message = "Enter the account number you want to delete: ";
    string accountNr = chooseAccountNr(message);
    if(bank->deleteAnAccount(accountNr))
    {
        cout << "\nThe account " << accountNr << " has been deleted." <<endl;
    }
}

void UserInterface::changeCustomer()
{
    bank->saveClientToFile();
    run();
}

void UserInterface::printStartMenu()
{
    cout << "\n1. Load customer from file.\n2. Create new customer.\n3. Quit." <<endl;
}

void UserInterface::printMenu()
{
    cout << "\n==========Menu==========\n1. Customer name.\n2. Customer persnr.\n3 Number of accounts.\n4. Account Numbers."
         <<"\n5. Total assets.\n6. Account info.\n7. Withdraw\n8. Deposit.\n9. Set credit.\n10. Accounts summary."
         <<"\n11. Create new account.\n12. Delete account.\n13. Change customer.\n14. Quit."<< endl;

}


void UserInterface::run()
{
    while (!done)
    {
        switch (getMenuChoice(1))
        {
            case 1:
                readCustomerFromFile();
                nextKey();
                break;
            case 2:
                createNewClient();
                nextKey();
                break;
            case 3:
                done = true;
            default:
                cout << "\nInvalid choice." << endl;
                break;
        }
    }
}

void UserInterface::executeMenuOptions()
{
    while (!done)
    {

        switch (getMenuChoice(2))
        {
            case 1:
                printCustomerName();
                nextKey();
                break;
            case 2:
                printPersNr();
                nextKey();
                break;
            case 3:
                printNrofAccounts();
                nextKey();
                break;
            case 4:
                printAccountNrs();
                nextKey();
                break;
            case 5:
                printTotalAsset();
                nextKey();
                break;
            case 6:
                printAccountInfo();
                nextKey();
                break;
            case 7:
                withdrawfromAccount();
                nextKey();
                break;
            case 8:
                depositToAccount();
                nextKey();
                break;
            case 9:
                setCredit();
                nextKey();
                break;
            case 10:
                printAccountsSummary();
                break;
            case 11:
                createAccount();
                nextKey();
                break;
            case 12:
                deleteAccount();
                nextKey();
                break;
            case 13:
                changeCustomer();
                nextKey();
                break;
            case 14:
                done= true;
            default:
                cout << "\nInvalid choice." << endl;
                break;
        }
    }
}

void UserInterface::nextKey()
{
    cin.get();
}
