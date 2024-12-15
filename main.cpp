#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "BankAccount.h"
using namespace std;

vector<BankAccount> accounts;

BankAccount *findAccount(string id)
{
    for (auto &account : accounts)
    {
        if (account.getBankHolderID() == id)
        {
            return &account;
        }
    }
    return nullptr;
}

int main()
{
    int choice;
    string accHolder, accNumber;
    double amount;

    while (true)
    {
        cout << "\n=== Bank Account Management System ===\n";
        cout << "1. Create a New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. View Account Details\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        if (cin.fail())
        {                                                        // Invalid input detected
            cin.clear();                                         // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Account ID : ";
            cin >> accNumber;
            if (findAccount(accNumber) != nullptr)
            {
                cout << "This Account ID Is Duplicate, renter ID ";
                break;
            }
            cout << "Enter Account Holder : ";
            cin.ignore();
            getline(cin, accHolder);
            cout << "Enter initial Amount : ";
            cin >> amount;

            // create account
            accounts.emplace_back(accHolder, accNumber, amount);
            cout << "The Bank Account Created For : " << accHolder << endl;
            break;
        }
        case 2:
        {
            cout << "Enter Account ID : ";
            cin >> accNumber;
            BankAccount *account = findAccount(accNumber);
            if (account == nullptr)
            {
                cout << "Account Number Is Not Valid" << endl;
            }
            else
            {
                cout << "Enter Amount You Want Deposite : ";
                cin >> amount;
                account->deposite(amount);
            }
            break;
        }
        case 3:
        {
            cout << "Enter Account ID : ";
            cin >> accNumber;
            BankAccount *account = findAccount(accNumber);
            if (account == nullptr)
            {
                cout << "Account Number Is Not Valid" << endl;
            }
            else
            {
                cout << "Enter Amount You Want Withdraw : ";
                cin >> amount;
                account->withdraw(amount);
            }
            break;
        }
        case 4:
        {
            cout << "Enter Account ID : ";
            cin >> accNumber;
            BankAccount *account = findAccount(accNumber);
            if (account == nullptr)
            {
                cout << "Account Number Is Not Valid" << endl;
            }
            else
            {
                account->getAccountInfo();
            }
            break;
        }
        case 5:
        {
            cout << "Thank you for using the Bank Account Management System. Goodbye! \U0001F44B \U0001F4B3\n";
            return 0;
        }
        default:
            cout << "Invaild Choice " << endl;
        }
    }
}