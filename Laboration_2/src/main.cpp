
/*main.cpp
* Honorine Lima
* Holi1900
* DT060G_Laboration_2
* 2020-09-07.
*/


#include "memstat.hpp"
#include "Bank.h"
#include "UserInterface.h"
#include "Customer.h"


int main() {
    /*Test program for account class
     * Account account("1111");
    cout<<"\n Account nr: " << account.getAccountNr() <<"\n Account balance: " << account.getBalance()
            <<"\n Account credit: "<< account.getCredit()<<"\n Account useable: " << account.getUseableAmount()
            << endl;
    account.withdraw(1000);
    account.setCredit(200000.00);
    account.deposit(1000);
    account.withdraw(10000);
    account.withdraw(3000000);

    cout<<"\n Account nr: " << account.getAccountNr() <<"\n Account balance: " << account.getBalance()
        <<"\n Account credit: "<< account.getCredit()<<"\n Account useable: " << account.getUseableAmount()
        << endl;*/
    unique_ptr<Bank> bank = unique_ptr<Bank>(new Bank);
    //Bank bank;
   /* string me ="me";
    string you ="me";
    bank->createCustumer(me, you);
    cout << "\nName " <<bank->getClientName();*/

    /*Customer cus("Honorine Lima", "11223344");
    cus.createAccount();
    cout << "Number of accounts: " << cus.getNrofAccounts() << endl;
    cout << "Assets: " <<cus.getTotalAsset() <<endl;
    string acc = "11223344_0";
    cus.depositToAccount(acc, 2000);
    cout << "Assets: " <<cus.getTotalAsset()<<endl;
    cus.withdrawFromAccount(acc, 1000);
    cus.changeCredit(acc, 10000);
    cout << "Assets: " <<cus.getTotalAsset() <<endl;
    //cus.deleteAccount(acc);
    cout << "Number of accounts: " << cus.getNrofAccounts() << endl;
   /*Account data = cus.getAccountInfo(acc);
    cout <<"acc nr: "<< data.getAccountNr() << endl;
    cout <<"acc useables: "<<data.getUseableAmount()<<endl;
    cout <<"acc nr: "<<data.getCredit() << endl;
    cout << "acc balance: "<<data.getBalance()<<endl;*/
   /* cus.createAccount();
    string acc1 = "11223344_1";
    cus.depositToAccount(acc1, 20);
    cout << "Assets: " <<cus.getTotalAsset()<<endl;
    cout << "Number of accounts: " << cus.getNrofAccounts() << endl;*/

    /*UserInterface test;
    test.createNewClient();
    test.printNrofAccounts();
    test.createAccount();
    test.printNrofAccounts();
    test.depositToAccount();
    test.printTotalAsset();
    test.setCredit();
    test.printTotalAsset();
    test.withdrawfromAccount();
    test.printTotalAsset();
    test.createAccount();
    test.depositToAccount();
    test.printTotalAsset();
    test.setCredit();
    test.printAccountNrs();
    test.printAccountInfo();
    test.printAccountsSummary();


    test.saveCustomerToFile();
    test.readCustomerFromFile();*/

    UserInterface test;
    test.run();

    return 0;
}
