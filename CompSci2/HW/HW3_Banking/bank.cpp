#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include "bank.h"

using namespace std;

// Function definitions

void menu() {
    vector<Account*> accounts;
    int nextAccountNumber = 1;
    int choice;

    
    
    do {
        cout << "\nBanking System Menu\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Close Account\n";
        cout << "6. List All Accounts\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        
        int accountNumber;
        double amount;
        
        switch (choice) {
            case 1:
                createAccount(accounts, nextAccountNumber);
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                depositMoney(accounts, accountNumber, amount);
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdrawMoney(accounts, accountNumber, amount);
                break;
            case 4:
                cout << "Enter account number: ";
                cin >> accountNumber;
                checkBalance(accounts, accountNumber);
                break;
            case 5:
                cout << "Enter account number: ";
                cin >> accountNumber;
                closeAccount(accounts, accountNumber);
                break;
            case 6:
                listAllAccounts(accounts);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);
    
    // Clean up dynamically allocated memory
    for (auto account : accounts) {
        delete account;
    }
}

void createAccount(vector<Account*>& accounts, int& nextAccountNumber) {
    Account* newAccount = new Account();
    cout << "Enter account holder name: ";
    cin >> newAccount->accountHolder;
    cout << "Enter initial balance: ";
    cin >> newAccount->balance;
    newAccount->accountNumber = nextAccountNumber++;
    accounts.push_back(newAccount);
}

void depositMoney(vector<Account*>& accounts, int accountNumber, double amount) {
    for (auto account : accounts) {
        if (account->accountNumber == accountNumber && amount > 0) {
            account->balance += amount;
            cout << "Deposit successful!\n";
            return;
        }
    }
    cout << "Invalid account number or amount.\n";
}

void withdrawMoney(vector<Account*>& accounts, int accountNumber, double amount) {
    for (auto account : accounts) {
        if (account->accountNumber == accountNumber && amount > 0 && account->balance >= amount) {
            account->balance -= amount;
            cout << "Withdrawal successful!\n";
            return;
        }
    }
    cout << "Invalid account number or insufficient balance.\n";
}

void checkBalance(const vector<Account*>& accounts, int accountNumber) {
    for (const auto account : accounts) {
        if (account->accountNumber == accountNumber) {
            cout << "Balance: " << account->balance << "\n";
            return;
        }
    }
    cout << "Account not found.\n";
}

void closeAccount(vector<Account*>& accounts, int accountNumber) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)->accountNumber == accountNumber) {
            delete *it;
            accounts.erase(it);
            cout << "Account closed.\n";
            return;
        }
    }
    cout << "Account not found.\n";
}

void listAllAccounts(const vector<Account*>& accounts) {
    for (const auto account : accounts) {
        cout << "Account Number: " << account->accountNumber 
                  << ", Holder: " << account->accountHolder 
                  << ", Balance: " << account->balance << "\n";
    }
}