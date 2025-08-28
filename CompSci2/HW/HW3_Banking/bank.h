#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>

struct Account {
    std::string accountHolder;
    int accountNumber;
    double balance;

    // Default constructor (needed for dynamic allocation without parameters)
    Account() : accountHolder(""), accountNumber(0), balance(0.0) {}

    // Parameterized constructor
    Account(std::string holder, int number, double bal) 
        : accountHolder(holder), accountNumber(number), balance(bal) {}
};

// Function declarations
void menu();
void createAccount(std::vector<Account*>& accounts, int& nextAccountNumber);
void depositMoney(std::vector<Account*>& accounts, int accountNumber, double amount);
void withdrawMoney(std::vector<Account*>& accounts, int accountNumber, double amount);
void checkBalance(const std::vector<Account*>& accounts, int accountNumber);
void closeAccount(std::vector<Account*>& accounts, int accountNumber);
void listAllAccounts(const std::vector<Account*>& accounts);


#endif // BANK_H