//===============================================
// Attached: Extra Credit
// File: Extra Credit
// =============================================================================
// Programmer: Hanqiu Luo && Matteo Steves && Ramtin Ghanevati
// Class: CS 1B
// Instructor: Med Mogasemi
// =============================================================================
// HW_11b - Array-based SortedList
// =============================================================================
/* Description:
Create 10 accounts in an array with id 0, 1, . . . , 9, and initial balance $100.
 The system prompts the user to enter an id. If the id is entered incorrectly,
 ask the user to enter a correct one. Once an id is accepted, the main menu is
 displayed, as shown in the sample run. You can enter a choice of 1 for viewing
 the current balance, 2 for withdrawing money, 3 for depositing money, and 4 for
 exiting the main menu. Once you exit, the system will prompt for an id again.
 So, once the system starts, it will not stop.      */
// =============================================================================
#include "Accounts.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
using namespace std;

int main()
{
    // Welcome menu
    cout << "\nWelcome to HQBC Bank! " << endl;
    cout << "A. Login " << endl << "B. Sign Up" << endl << "X. Exit" << endl << endl;
    cout << "Please enter your choice: ";
    char input;
    cin >> input;
    cin.ignore(10000, '\n');

    input = toupper(input);

    while (input != 'X')
    {
        switch (input) {
            case 'A': {

                cout << "\nPlease input the user name and password:" << endl;
                cout << "User Name: ";
                string name;
                getline(cin, name);
                cout << "Password: ";
                string pswd;
                getline(cin, pswd);

                if (userAuthentication(name, pswd))
                {
                    int choice;

                    do {
                        choice = accountChoice(); // Checking or Saving selection
                        if (choice == 1) // Checking accounts selected
                        {
                            // Create checkingAccount class obj
                            // Load checking balance from TransactionRecord file
                            CheckingAccount myAccount = loadCheckingAccount(name);

                            // Account service menu display and operations
                            accountServiceOperations(myAccount);

                            // Record the updated checking balance
                            double newBalance = myAccount.getBalance();

                            // Updated the checking balance in TransactionRecord file
                            updateCheckingBalance(name, newBalance);

                        } else if (choice == 2) // Saving accounts selected
                        {
                            // Create savingAccount class obj
                            // Load saving balance from TransactionRecord file
                            SavingsAccount myAccount = loadSavingAccount(name);

                            // Account service menu display and operations
                            accountServiceOperations(myAccount);


                            // Record the updated saving balance
                            double newBalance = myAccount.getBalance();

                            // Updated the saving balance in TransactionRecord file
                            updateSavingBalance(name, newBalance);
                        }
                    }while (choice != 0);
                    // loop until user chooses exit in accountChoice()
                }
                else
                    cout << "\nYour information is not found in the system!\n\n";

                break;
            }
            case 'B': { // Select to sign up a new account
                string nm, psd;
                cout << "\nInput your user name and password to create your account"
                    << endl;

                cout << "User Name: ";
                cin >> nm;
                cout << "Password (numbers only): ";
                cin >> psd;

                // Add a new user to the UserFile
                addUser(nm, psd);

                break;
            }
        }

        // Welcome menu
        cout << "\nWelcome to HQBC Bank! " << endl;
        cout << "A. Login " << endl << "B. Sign Up" << endl << "X. Exit" << endl << endl;
        cout << "Please enter your choice: ";
        cin >> input;
        cin.ignore(10000, '\n');
        input = toupper(input);
    }

    cout << "\nSee you next time!" << endl;


    return 0;
}
