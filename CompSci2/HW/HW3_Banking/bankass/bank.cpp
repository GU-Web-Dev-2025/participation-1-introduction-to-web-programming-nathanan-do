#include "bank.h"
#include <iostream>

using namespace std;

// Function definitions

// Menu function
void menu() {

    vector<Account*> accounts; // This is declared in .h file
    int nextAccountNumber = 1000; // Starting value for special account number
    int choice;
    
    do {

        cout << "\nWelcome to Nathan's Notorious Bank. Would you like to\n"; // Basic menu printout
        cout << "1. Create an Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Close Account\n";
        cout << "6. List All Accounts\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        cin >> choice; // Inputs only accept ints
        
        int accountNumber;
        double amount;
        
        switch (choice) {

            case 1:

                createAccount(accounts, nextAccountNumber); // Fucntion to create an account
                break;

            case 2:

                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                depositMoney(accounts, accountNumber, amount); // Fucntion to deposit money after creating an account
                break;

            case 3:

                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdrawMoney(accounts, accountNumber, amount); // Fucntion to withdraw money
                break;

            case 4:

                cout << "Enter account number: ";
                cin >> accountNumber;
                checkBalance(accounts, accountNumber); // Fucntion to check balance
                break;

            case 5:

                cout << "Enter account number: ";
                cin >> accountNumber;
                closeAccount(accounts, accountNumber); // Fucntion to close account
                break;

            case 6:

                listAllAccounts(accounts); // Fucntion to list all active accounts
                break;

            case 7:

                cout << "Exiting...\n";
                cleanup(accounts);  // Ensure all memory is freed before exiting
                break;

            default:
                cout << "Invalid choice. Try again.\n"; // Inputs only accept ints

        }

    } while (choice != 7);

}

// Create account function
void createAccount(vector<Account*>& accounts, int& nextAccountNumber) {

    Account* newAccount = new Account();  // Dynamically allocate memory for a new Account

    cout << "Enter account holder name: ";
    cin >> newAccount->accountHolder; // Get the account holder's name from the user and store it

    cout << "Enter initial balance: ";
    cin >> newAccount->balance; // Get the initial balance from the user and store it

    newAccount->accountNumber = nextAccountNumber+=10; // Assigns a new account number to be incremented by 10 for the next account
    accounts.push_back(newAccount);  // Adds the newly created account (pointer) to the accounts vector

}

// Deposit money function
void depositMoney(vector<Account*>& accounts, int accountNumber, double amount) {

    // "(auto account : accounts)" Iterates over all Account pointers in the accounts vector. 
    for (auto account : accounts) { // The "auto" keyword automatically deduces that account is a pointer to an Account (aka 'new' in line 91)

        if (account->accountNumber == accountNumber && amount > 0) {

            account->balance += amount; // Add the deposit amount to the account's balance
            cout << "Deposit successful!\n";
            return;

        }

    }

    cout << "Invalid account number or amount.\n"; //If no matching account is found or the amount is invalid, this error message is displayed to the user.

}

// Withdraw money function
void withdrawMoney(vector<Account*>& accounts, int accountNumber, double amount) {

    for (auto account : accounts) {
    // "(auto account : accounts)" Iterates over all Account pointers in the accounts vector. The "auto" keyword automatically deduces that account is a pointer to an Account

        if (account->accountNumber == accountNumber && amount > 0 && account->balance >= amount) {
        /*Checks three conditions:
        If the account number matches the input
        If the withdrawal amount is positive
        If the account has enough balance to cover the withdrawal
        */

            account->balance -= amount; // Subtract the withdrawal amount from the account's balance
            cout << "Withdrawal successful!\n";
            return;

        }

    }

    cout << "Invalid account number or insufficient balance.\n"; // If the account number doesn't match or the balance is too low, an error message is displayed.

}

// Check balance function
void checkBalance(const vector<Account*>& accounts, int accountNumber) {

    for (const auto account : accounts) {
    // "(auto account : accounts)" Iterates over all Account pointers in the accounts vector. The "auto" keyword automatically deduces that account is a pointer to an Account

        if (account->accountNumber == accountNumber) { // Checks if the current account's number matches the input account number

            cout << "Balance: " << account->balance << "\n"; // Display the account balance
            return;

        }

    }

    cout << "Account not found.\n"; // If no matching account is found, an error message is shown.

}

// Removes account function
void closeAccount(vector<Account*>& accounts, int accountNumber) {

    for (auto it = accounts.begin(); it != accounts.end(); ++it) { /*Uses an iterator (it) to iterate over the accounts vector
    This allows for safe removal of an element from the vector*/
    

        if ((*it)->accountNumber == accountNumber) {
        // Dereferences the iterator (*it) to access the account pointer and checks if the account number matches the input.

            delete *it;  // Free dynamically allocated memory
            accounts.erase(it);  // Remove the pointer from the vector
            cout << "Account closed.\n";
            return;

        }

    }

    cout << "Account not found.\n"; // If no matching account is found

}

// List All active accounts function
void listAllAccounts(const vector<Account*>& accounts) {

    for (const auto account : accounts) {
    // "(auto account : accounts)" Iterates over all Account pointers in the accounts vector. The "auto" keyword automatically deduces that account is a pointer to an Account

        cout << "Account Number: " << account->accountNumber 
                  << ", Holder: " << account->accountHolder 
                  << ", Balance: " << account->balance << "\n";

    }
    
}

// Function to clean used memory allocations
void cleanup(vector<Account*>& accounts) {

    for (auto account : accounts) {
    // "(auto account : accounts)" Iterates over all Account pointers in the accounts vector. The "auto" keyword automatically deduces that account is a pointer to an Account

        delete account;  // Free all dynamically allocated memory

    }

    accounts.clear();  // Clear the vector after deallocation

}
