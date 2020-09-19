//
// Created by limbe on 2020-09-19.
//

#include "userInterface.h"

userInterface::userInterface()
{
}

userInterface::~userInterface()
{

}

char userInterface::getChoice()
{
    cout <<"\nmake your choice: ";
    char choice;
    cin >> choice;
    return choice;
}
void userInterface::run()
{
    cout << "\n1. Load customer from file. \n2. create a new customer. \n3. Quit."<<endl;

    char options[] = {'1', '2', '3'};//valid menu choices
    char choice{'a'};//initialise choice to an unexpected value
    bool valid = false;
    while(!valid)
    {
        choice = getChoice();
        for(auto & option : options) // using range-base for loop. same as for(int i=0; i<8; i++)...if(options[i]==choice)
        {
            if(option==choice)
            {
                valid =true;
            }
        }
        if(!valid)
        {
            cout << "Invalid choice." << endl;
        }
    }

    bool again = true;
    while(again)
    {
        switch(choice)
        {
            case '1':
                readCustomerFromFile();
                break;
            case '2':
                createNewClient();
                break;
            case'3':
                again =false;
            default:
                cout << "\nInvalid choice." << endl;
                break;
        }
    }
}

void userInterface::createNewClient()
{
    string name, persNr;
    cout <<"\nEnter customer's first name and last name: ";
    getline(cin, name);
    while(name.empty())
    {
        cout <<"\nEmpty entries are not allowed.\nEnter customer's first name and last name: ";
        getline(cin, name);
    }
    cout <<"\nEnter customer's personnummer: ";
    getline(cin, persNr);
    while(persNr.empty())
    {
        cout <<"\nEmpty entries are not allowed.\nEnter customer's personnummer: ";
        getline(cin, persNr);
    }
    bank->createCustumer(name, persNr);
}

void userInterface::saveCustomerToFile()
{
    bank->saveClientToFile();
    cout << "\nCustomer saved to file"<<endl;
}

void userInterface::readCustomerFromFile()
{
    if(bank->readClientFromFile())
    {
        cout << "Customer successfully read from file" << endl;
    }
    else{
        cout << "Reading customer from file was unsuccessful." <<endl;
    }
}


