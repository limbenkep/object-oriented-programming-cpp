#include "Prototypes.h"
#include "memstat.hpp"
#include "Account.h"

int main() {
    Account account("1111");
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
        << endl;

    return 0;
}
