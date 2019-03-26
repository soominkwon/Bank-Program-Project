// Kenny Kwon's Banking Program Project
// RUID: 174000345
// function file

#ifndef BANKINGPROJECT_FUNCTION_FILE_H
#define BANKINGPROJECT_FUNCTION_FILE_H
#endif //BANKINGPROJECT_FUNCTION_FILE_H
#include "header_file.h"

using namespace std;

vector <Account> bankAccounts;

void menu() {
    cout << endl << "Welcome to our bank! Select options below:\n"
            "1. Make new account.\n"
            "2. Deposit to an account.\n"
            "3. Withdraw from an account.\n"
            "4. Transfer Money from one account to another.\n"
            "5. Print account.\n"
            "6. Activate/Deactivate an account.\n"
            "7. Delete an account.\n"
            "8. Display all accounts.\n"
            "9. Quit.\n"
            "Selection: ";
}

void makeAccount(vector <Account> &bankAccounts) {
    Account temp;

    srand((unsigned) time(0));
    temp.accountNumber = (1000 + rand() % 8999);

    cout << endl << "Creating bank account " << temp.accountNumber;

    cout << endl << "Enter first name: ";
    cin >> temp.firstName;

    cout << "Enter last name: ";
    cin >> temp.lastName;

    cout << "Enter starting balance: ";
    cin >>temp.accountBalance;

    temp.active = true;

    bankAccounts.push_back(temp);

    cout << endl << "Your account has successfully been made. Thank you for choosing our bank!" << endl;

}

void printAccount(vector <Account> &bankAccounts) {
    int accountNum;

    cout << endl << "Enter account number to print: ";
    cin >> accountNum;

    for (int i = 0; i < bankAccounts.size(); ++i) {

        if (accountNum == bankAccounts[i].accountNumber)
            accountNum = i;
    }

        if (bankAccounts[accountNum].active == false) {
            cout << endl << "The entered bank account is either deactivated or does not exist. Please try again." << endl;
        }

        if (bankAccounts[accountNum].active == true)
            cout << "Account: " << bankAccounts[accountNum].accountNumber << endl
                 << "Balance: " << bankAccounts[accountNum].accountBalance << endl
                 << "First Name: " << bankAccounts[accountNum].firstName << endl
                 << "Last Name: " << bankAccounts[accountNum].lastName << endl;

}

void printAllAccounts(vector <Account> &bankAccounts) {
    for (int i = 0; i < bankAccounts.size(); i++) {
        if (bankAccounts[i].active == true) {
            cout << "Account Number: " << bankAccounts[i].accountNumber
                 << setw(8)
                 << " " << "Balance: " << bankAccounts[i].accountBalance
                 << endl
                 << "Last Name: " << bankAccounts[i].lastName
                 << setw(12)
                 << " " << "First Name: " << bankAccounts[i].firstName << endl << endl;
        }
    }
}

void transfer(vector <Account> &bankAccounts) {
    int sender;
    int receiver;
    double transferAmount;

    cout << "Enter account number for the sender: " << endl;
    cin >> sender;

    for (int i = 0; i < bankAccounts.size(); ++i) {
        if (sender == bankAccounts[i].accountNumber) {
            sender = i;
        }
    }

    if (bankAccounts[sender].active == false) {
        cout << endl << "The entered bank account is either deactivated or does not exist. Please try again." << endl;
        return;
    }

        cout << "Enter amount to transfer: " << endl;
        cin >> transferAmount;

        if (transferAmount > bankAccounts[sender].accountBalance) {
            cout << endl << "There are insufficient funds in your account. Please try again." << endl;
            return;
        }

        cout << "Enter account number for the receiver: " << endl;
        cin >> receiver;

        for (int i = 0; i < bankAccounts.size(); ++i) {
            if (receiver == bankAccounts[i].accountNumber) {
                receiver = i;
            }
        }

    if (bankAccounts[receiver].active == false) {
        cout << endl << "Thie entered bank account is either deactivated or does not exist. Please try again." << endl;
        return;
    }

    if (bankAccounts[receiver].active == true  && bankAccounts[sender].active == true) {
    bankAccounts[sender].accountBalance = bankAccounts[sender].accountBalance - transferAmount;
    bankAccounts[receiver].accountBalance = bankAccounts[receiver].accountBalance + transferAmount;
}

    cout << endl << "Your transaction has successfully been completed!" << endl;

}

void withdrawAccount(vector <Account> &bankAccounts) {
    double withdrawAmount;
    int accNum;

    cout << "Enter account number for withdrawal: ";
    cin >> accNum;

    for (int i = 0; i < bankAccounts.size(); ++i) {
        if (accNum == bankAccounts[i].accountNumber)
            accNum = i;
    }

    if (bankAccounts[accNum].active == false) {
        cout << endl << "The entered bank account is currently inactive or does not exist. Please try again." << endl;
    return;
    }

    cout << "Enter amount to be withdrawn: ";
    cin >> withdrawAmount;

    if (withdrawAmount > bankAccounts[accNum].accountBalance) {
        cout << endl << "There are insufficient funds in this account to make withdrawl. Please try again." << endl;
        return;
    }

    bankAccounts[accNum].accountBalance = bankAccounts[accNum].accountBalance - withdrawAmount;

    cout << endl << "Your withdrawl has been successfully completed!" << endl;

}

void depositAccount(vector <Account> &bankAccounts){
    double depositAmount;
    int depositAccount;

    cout << "Enter account number for deposit: ";
    cin >> depositAccount;

    for (int i = 0; i < bankAccounts.size(); ++i) {
        if (depositAccount == bankAccounts[i].accountNumber)
            depositAccount = i;
    }

    if (bankAccounts[depositAccount].active == false) {
        cout << endl << "The entered bank account is currently inactive or does not exist. Please try again." << endl;
        return;
    }

    cout << "Enter amount to be deposited: ";
    cin >> depositAmount;

    bankAccounts[depositAccount].accountBalance = bankAccounts[depositAccount].accountBalance + depositAmount;

    cout << endl <<"Your deposit has successfully been completed." << endl;
}

//accounts must be active to delete
void deleteAccounts (vector <Account> &bankAccounts) {
    int accNum;
    int choice;

    cout << "Enter account number to be deleted: ";
    cin >> accNum;


    for (int i = 0; i < bankAccounts.size(); ++i) {
            if (accNum == bankAccounts[i].accountNumber)
                accNum = i;
        }

    if (bankAccounts[accNum].active == false) {
        cout << endl << "The entered bank account is currently inactive or does not exist. Please try again." << endl;
        return;
    }

    cout << "Are you sure you would like to delete this account?" << endl << "Press 1 for Yes or 0 for No." << endl;
    cin >> choice;

    if (choice == 0) {
        cout << endl << "You account has NOT been deleted. Returning to main menu..." << endl;
        return;
    }

    if (choice == 1) {
        bankAccounts.erase (bankAccounts.begin() + accNum);
    }

    cout << endl << "Your account has now been successfully deleted. We hope to serve as your bank again in the future." << endl;

    }

void activateDeactivate (vector <Account> &bankAccounts) {
    int accNum;
    int choice;

    cout << "Enter account number to activate/deactivate: ";
    cin >> accNum;

    for (int i = 0; i < bankAccounts.size(); ++i)
        if (accNum == bankAccounts[i].accountNumber)
            accNum = i;

    if (bankAccounts[accNum].active == true)
        cout << "This account is currently active. Please press 1 to de-activate or 0 to return to menu. ";
    else
        cout << "This account is currently NOT active or does not exist. Please press 2 to re-activate or 0 to return to menu. ";

    cin >> choice;

    if (choice == 0) {
        return;
    }
    if (choice == 1) {
        bankAccounts[accNum].active = false;
        cout << endl << "This account has now been de-activated." << endl;
        return;
    }
    if (choice == 2) {
        bankAccounts[accNum].active = true;
        cout << endl << "This account has now been re-activated." << endl;
        return;
    }
}

bool account_order(Account i, Account j) { return (i.accountNumber < j.accountNumber); }
void sortAccounts(vector <Account> &bankAccounts) {
    for (int i = 0; i < bankAccounts.size(); i++)
        sort(bankAccounts.begin(), bankAccounts.end(), account_order);

}

void validInput (vector <Account> &bankAccounts) {
    int accNum;

    cin >> accNum;

    for (int i = 0; i < bankAccounts.size(); ++i)
        if (accNum == bankAccounts[i].accountNumber)
            continue;
    else
            return;
}