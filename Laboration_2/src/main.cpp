#include "Prototypes.h"
#include "memstat.hpp"
#include "Account.h"
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
    Customer cus("Honorine", "Lima", "11223344");
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
    accountInfo data = cus.getAccountInfo(acc);
    cout <<"acc nr: "<< data.sAccNr << endl;
    cout <<"acc useables: "<<data.sUseable <<endl;
    cout <<"acc nr: "<<data.sCredit << endl;
    cout << "acc balance: "<<data.sBalance<<endl;
    cus.createAccount();
    string acc1 = "11223344_1";
    cus.depositToAccount(acc1, 20);
    cout << "Assets: " <<cus.getTotalAsset()<<endl;
    cout << "Number of accounts: " << cus.getNrofAccounts() << endl;




    return 0;
}
