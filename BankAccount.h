#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <iostream>
using namespace std;

class BankAccount {
    // member data
    private:
        string holderName;
        string holderID;
         double balance;

    public:
    //constructor
    //default
        BankAccount();
    //Parameterized
        BankAccount(string name, string id, double initialBalance);

    //destructor
        ~BankAccount();

       // function members
        //setters mutators
        void setBankHolderName(string name);
        void setBankHolderID(string ID);

        void deposite(double amount);
        void withdraw(double amount);

        // getters || accessors
        string getBankHolderName() const;
        double getBankBalance() const;
        string getBankHolderID() const;
        void getAccountInfo() const;
};

#endif