/*UserInterface.h
* Honorine Lima
* Holi1900
* DT060G_Laboration_3
* 2020-09-27.
 *
 * incteraction class with the user that allows user to
 * execute the different menu options. Receives request from user and call functions throuh the back class to execute
 * the function.
*/

#ifndef BANK_SYSTEM2_USERINTERFACE_H
#define BANK_SYSTEM2_USERINTERFACE_H
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
    int getPositiveInt(string &message);

    /**
     * prints start menu
     */
    static void printStartMenu();
    /**
     * prints options menu
     */
    static void printMenu();

    /**
     * executes different menu options
     */
    void executeMenuOptions();
    /**
 * returns the interest rate of an account
 */
    int getInterest(string &accountNr) const;
    /**
 *
 * @return number of withdrawals
 */
    int getNrOfWithdrawals(string &accountNr) const;

/**
 *
 * @return the number of withdrawals that can be made for an account
 */
    int getMaxWithdrawals(string &accountNr) const;
    /**
     * allows user to press any key to continue.
     */
    static void nextKey();
//================Testers================================================================================================
/**
 * test if account type has credit
 * @return true if it has else false
 */
    bool hasCredit(string &accountNr) const;

/**
  * test if account type has interest
 * @return true if it has else false
 */
    bool hasInterest(string &accountNr) const;

/**
  * test if account type has a maximum number of withdrawals
 * @return true if it has else false
 */
    bool hasMaxWithdrawals(string &accountNr);


public:
    UserInterface();

    virtual ~UserInterface();

    void run();


};


#endif //BANK_SYSTEM2_USERINTERFACE_H
