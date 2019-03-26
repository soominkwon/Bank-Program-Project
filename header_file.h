// Kenny Kwon's Banking Program Project
// RUID: 174000345
// header file

#ifndef BANKINGPROJECT_HEADER_H
#define BANKINGPROJECT_HEADER_H

#endif //BANKINGPROJECT_HEADER_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

struct Account {
    int accountNumber;
    string lastName;
    string firstName;
    double accountBalance;
    bool active;
};

void menu();
void makeAccount(vector <Account> &bankAccounts);
void printAccount(vector <Account> &bankAccounts);
void printAllAccounts(vector <Account> &bankAccounts);
void transfer(vector <Account> &bankAccounts);
void depositAccount(vector <Account> &bankAccounts);
void activateDeactivate(vector <Account> &bankAccounts);
void withdrawAccount(vector <Account> &bankAccounts);
void deleteAccounts(vector <Account> &bankAccounts); //accounts must be active to delete
void sortAccounts(vector <Account> &bankAccounts);
void validInput (vector <Account> &bankAccounts);


