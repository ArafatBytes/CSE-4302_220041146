#include<iostream>
#include "header.h"
using namespace std;

void SavingsAccount::setAccName(string s){
    acc_name=s;
}
void SavingsAccount::setAccHolderName(string s){
    acc_holder_name=s;
}
void SavingsAccount::setAddress(string s){
    address=s;
}
void SavingsAccount::setIR(double r){
    interest_rate=r;
}
void SavingsAccount::setBalance(double b){
    curr_balance=b;
}
string SavingsAccount::getAccName(){
    return acc_name;
}
string SavingsAccount::getAccHolderName(){
    return acc_holder_name;
}
string SavingsAccount::getAddress(){
    return address;
}
double SavingsAccount::getIR(){
    return interest_rate;
}
double SavingsAccount::getBalance(){
    return curr_balance;
}
void SavingsAccount::deposit(double amount){
    curr_balance+=amount;
}
void SavingsAccount::withdrawal(double amount){
    if(amount<curr_balance){
        curr_balance-=amount;
    }
    else{
        cout<<"Insufficient balance!"<<endl;
    }
}
double SavingsAccount::calculateInterest(int periodInMonths){
    return (curr_balance>=minBalanceInterest)?curr_balance*interest_rate*periodInMonths/12:0;
}

void SavingsAccount::disburseInterest(int periodInMonths){
    curr_balance+=calculateInterest(periodInMonths);
}