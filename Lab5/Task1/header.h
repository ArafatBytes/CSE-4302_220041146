#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<string>
using namespace std;

class SavingsAccount {
    string acc_name,acc_holder_name,address;
    double interest_rate,curr_balance;
    int minBalanceInterest=1500;

    public:
        SavingsAccount();
        ~SavingsAccount();

        void setAccName(string s);
        void setAccHolderName(string s);
        void setAddress(string a);
        void setIR(double r);
        void setBalance(double b);
        string getAccName();
        string getAccHolderName();
        string getAddress();
        double getIR();
        double getBalance();

        void deposit(double amount);
        void withdrawal(double amount);

        double calculateInterest(int periodInMonths);
        void disburseInterest(int periodInMonths);
};

#endif