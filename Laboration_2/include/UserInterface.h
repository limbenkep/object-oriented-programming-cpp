//
// Created by limbe on 2020-09-19.
//

#ifndef BANK_SYSTEM1_USERINTERFACE_H
#define BANK_SYSTEM1_USERINTERFACE_H
#include "Bank.h"

class UserInterface
{
private:
    unique_ptr<Bank>bank;//unique pointer to hold the bank object
    bool done; // to help move between start menu and options menu

    /**
     * gets an 1 for start me nu or 2 for option menu and prints the corresponding menu and gets users choice,
     * check that is is valid nd returns the choice as an int
     */
    int getMenuChoice(int menu);

    /**
     * creates new client
     */
    void createNewClient();

    /**
     * save customer to file
     */
    void saveCustomerToFile();

    /**
     * reads customer from file
     */
    void readCustomerFromFile();

    /**
     * prints customer's name
     */
    void printCustomerName();

    /**
     * prints customer's personal number(customer id)
     */
    void printPersNr();

    /**
     * print number of accounts
     */
    void printNrofAccounts();

    /**
     * prints account numbers for all the accounts
     */
    void printAccountNrs();

    /**
     * prints the total assets for all the customer's accounts
     */
    void printTotalAsset();

    /**
     * prompts user for an account number and prints the balance, credit and useable of that account or prints a message
     * if account not found
     */
    void printAccountInfo();

    /**
     * prompts user for account number and amount and withdraw that amount from the given account if the amount is
     * less than or equal to the accounts useable or print a message it is is greater than the useables
     */
    void withdrawfromAccount();

    /**
     * prompts user for account number and amount and deposite that amount to the given account
     */
    void depositToAccount();

    /**
     * prompts user for account number and amount and set that amount as credit for the given account
     */
    void setCredit();

    /**
     * prints summary of all customer's accounts including account number, balance, credit and useable
     */
    void printAccountsSummary();

    /**
     * create a new account or prints a message if the customer already has maximum number accounts
     */
    void createAccount();

    /**
     * prompts user to enter account number of th eaccount to be deleted
     */
    void deleteAccount();

    /**
     * saves current user to a file, prompts user to create a customer or read from file
     */
    void changeCustomer();

    /**
     * receives a message as parameter and prints a message prompting for an account number for a given purpose
     * and returns the account number
     */
    string chooseAccountNr(string &message);

    /**
     * receives message abd print prompting user for a double
     * @param message
     * @return
     */
    double getADouble(string &message);

    /**
     * prints start menu
     */
    void printStartMenu();
    /**
     * prints options menu
     */
    void printMenu();

    /**
     * executes different menu options
     */
    void executeMenuOptions();
    /**
     * allows user to press any key to continue.
     */
    void nextKey()

public:
    UserInterface();

    virtual ~UserInterface();

    void run();

};


#endif //BANK_SYSTEM1_USERINTERFACE_H
