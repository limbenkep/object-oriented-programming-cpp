/*main.cpp
* Honorine Lima
* Holi1900
* DT060G_Laboration_5
* 2020-11-27.
*/
/**==================Short description====================================================================
 * This program generates and manages random numbers between 1000 and 2000.
 * The generated numbers are stored on a list. At the user chooses if the numbers will be of type double or int, after which
 * a menu is presented with the following options to choose from; Fill list with random numbers, Summerize the values in
 * the list, Average of the numbers, Find first number between 1500 and 1900, Divide by two, Swap places,
 * Find largest and smallest number, Sort, Clear list, write to file,  Read from file, Print numbers, Quit.
 */

#include "Prototypes.h"
#include "memstat.hpp"
#include "UserInterface.h"

typedef double Type;
void mainTestFunction();
int getChoice();


int main() {
    mainTestFunction();
    return 0;
}

void mainTestFunction()
{
    cout << "Choose the type of list. \n1. Int, \n2. Double." << endl;
    int choice = getChoice();
    while(choice<1||choice>2)
    {
        cout << "\nInvalid choice. Choice must be 1 0r 2." << endl;
        cout << "Choose the type of list. \n1. Int, \n2. Double." << endl;
        choice = getChoice();
    }
    if (choice==1)
    {
        list<int> intList;
        UserInterface<int> user(&intList);
        user.run();

    }
    if (choice==2)
    {
        list<double> intList;
        UserInterface<double> user(&intList);
        user.run();

    }
}

int getChoice()
{
    cout << "Make your choice:";
    int choice = 0;
    cin>>choice;
    if (!cin||choice<1)// this control ensures that number of albums, number of songs, song length for which is function is used to get can not be 0
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return -1;
    }
    cin.ignore(1000, '\n');
    return choice;
}