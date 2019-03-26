// Kenny Kwon's Banking Program Project
// RUID: 174000345
// main file

#include "function_file.h"

using namespace std;

int main(){
    int select;

    vector <Account> bankAccounts;

    while (select !=9){
        menu ();
        cin >> select;

        if (select == 1) {
            makeAccount(bankAccounts);
            sortAccounts(bankAccounts);
        }
        else if (select == 2)
            depositAccount(bankAccounts);

        else if (select == 3)
            withdrawAccount(bankAccounts);

        else if (select == 4)
            transfer(bankAccounts);

        else if (select == 5)
            printAccount(bankAccounts);

        else if (select == 6)
            activateDeactivate(bankAccounts);

        else if (select == 7)
            deleteAccounts(bankAccounts); //accounts must be active to delete

        else if (select == 8)
            printAllAccounts(bankAccounts);

        else if
            (select == 9)
            cout << endl << "Bank is now closed!" << endl;

        else
            cout << endl << "You have entered an invalid selection. Please try again." << endl;
    }
    return 0;

}

