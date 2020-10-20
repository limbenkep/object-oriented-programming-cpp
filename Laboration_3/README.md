# Laboration 3


## Environment & Tools
windows 10 Operating system, CLion 2019.3.3 IDE, Microsoft C++ (MSVC) compiler, CMake version: 3.15.6, Git version: 2.25.0.windows.1

## Purpose
The purpose of this lab is to practice the principles of inheritance and encapsultion by designing an interactive bankng system.

## Procedures
This program is a banking system designed to allow the user to create and manage one customer at a time. The Customer is identified 
by the customer name and personal number and can have up to three accounts with can be any of three types; transaction account, savings 
account or longterm savings account.The transaction account allows credit and has no interest rate or maximum withdrawals, 
The savings account does not accept credit and has a 4 maximum withdrawal and a current interest rate of 2.0% while the 
  long Term savings account do not accept credit, has a maximum of 1 withdraw per year and and has double the interest rate of 
  the savings account The Different classes are implemented as seperate classes using an account class as an abstract base class.
  Saving and long term savings accounts keep tract of the number of withdrawals made but there is no implementation to made for 
  annaual time frame.
  All accounts keeps track of it's balance and can tell is disposables as well as manage deposits and withdrawal in a way such 
  that disposables are never negative. When the program starts the User has three options; to create a customer, read a customer 
  from a file or quit after which the customer has access to more options to manage the customer like get information about the 
  customer and its accounts, create and delete accounts, deposit and withdraw, set credit and print summaries for particular 
  accounts or all accounts. A customer class manages a customer while a bank class holding a pointer to a customer was used 
  for encapsultion purpose.A userInterFace class was used for interaction with the user.
## Discussion
To meet the goals of this project, I used an Account base class and practiced inheritace by creating separate classes for the 
different account types which inherited from the Account class and used virtual fuctions to define the different variants 
of the inherited functions in the various. I also used the bank class for encapsulation to hide the implemntation of the 
Account and customer classes I also used test functions to controll for properties for the different account type to determine
 how each account type will be manage for example for the function for withdrawal in the userInterface class, I hasMaxWithdrawal 
 to check an account has a withdrawal limit before it is allowed to withdraw.
I think it was a good approach to split the lab to two because I had the chance to practice encapsulation and using unique 
pointers and implement the skeleton of the project before going into inheritance. It would have been overwhelming if everything 
had to be implmented in one. The Lab presentations were very useful as a guide and the notes were cexplicit enough. I had alot of prompt 
from my ide to use override instead of virtual for my inherited functions but I am really sure what the difference so I folled the 
examples from the notes and stuck with virtual. I believe I met the goals of the lab.

##Revision
This revision attains to the issues stated on the feedbacks from the submission "As stated by the requirements Bank, Customer and 
Account needs to be completely silent. No console printing may be performed from any of these classes."
The cout statement has been removed. Also to ensure that no empty customer can be created, The default constructor in the 
customer class was replaced by a constructor with one parameter, the personal number.