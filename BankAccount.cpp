#include "BankAccount.h"
#include <string>
#include <iostream>
using namespace std;

// constructor
// default
BankAccount::BankAccount() : holderName(""),holderID(""),balance(0.0){
    cout << "BankAccount Created By Default Contructor" << endl;
}

//parameterized
BankAccount::BankAccount(string name, string id, double amount): holderName(name) , holderID(id) , balance(amount){
  cout << "\U0001F4B3  BankAccount Created By Parameterized : " << holderName << endl;
}

//destructor
BankAccount::~BankAccount(){
    cout << "BankAccount Destory : " << holderName << endl;
}

string BankAccount::getBankHolderID() const {
    cout << "Bank Account ID : " << holderID << endl;
    return holderID;
}

string BankAccount::getBankHolderName() const{
    cout << "Bank Account Name : " << holderName << endl;
    return holderName;
}

void BankAccount::getAccountInfo() const{
    cout << "\U0001F194  Account ID         : " << holderID << endl;    // 🆔
    cout << "\U0001F464  Account Holder     : " << holderName << endl;  // 👤
    cout << "\U0001F4B0  Current Balance    : " << balance << " \u00A3" << endl;
}

void BankAccount::setBankHolderID(string id){
    holderID = id;
    cout << "Bank Account ID Changed To : " << holderID << endl;
}

void BankAccount::setBankHolderName(string name){
    holderName = name;
    cout << "Bank Account Name Changed To : " << holderName << endl;
}

void BankAccount::deposite(double amount) {
    if (amount > 0) {
        balance += amount; // إضافة المبلغ إلى الرصيد
        cout << "\U0001F4B0  Amount deposited successfully! New balance: " << balance << endl; // 💰
    } else {
        cout << "\U000026A0  Error: Deposit amount must be greater than zero.\n"; // ⚠️
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0) {
        if (amount <= balance) {
            balance -= amount; // خصم المبلغ من الرصيد
            cout << "\U0001F4B0  Withdrawal successful! New balance: " << balance << endl; // 💰
        } else {
            cout << "\U000026A0  Error: Insufficient balance. Current balance: " << balance << endl; // ⚠️
        }
    } else {
        cout << "\U000026A0  Error: Withdrawal amount must be greater than zero.\n"; // ⚠️
    }
}