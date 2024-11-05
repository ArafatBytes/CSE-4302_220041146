#include<bits/stdc++.h>
using namespace std;

class BankAccount {
    int account_number;
    string account_holder_name;
    string account_type;
    double current_balance;
    const double min_balance=100.00;
    public:
        static int account;
        static int created;
        static double tax;
        BankAccount(int no, string name, string type, double cur){
            account_number=no;
            account_holder_name=name;
            account_type=type;
            current_balance=cur;
            account++;
            created++;
        };
        void show(){
            cout<<"Account number: "<<account_number<<endl;
            cout<<"Account holder name: "<<account_holder_name<<endl;
            cout<<"Account type: "<<account_type<<endl;
            cout<<"Current balance: "<<current_balance<<endl;
            cout<<"Minimum Balance: "<<min_balance<<endl;
        }
        void showBalance(){
            cout<<"Current Balance: "<<current_balance<<endl;
        }
        double getCuurentBalance() const {
            return current_balance;
        }
        void deposit(double val){
            current_balance+=val;
            showBalance();
        }
        void withdrawal(double val){
            if(current_balance>min_balance){
                current_balance-=val;
                showBalance();
            }
            else{
                cout<<"Current balance is lower than the minimum balance"<<endl;
            }
        }
        void giveInterest(float val=0.03){
            double interest=current_balance*val;
            tax+=interest*0.1;
            current_balance+=interest*0.9;
        }
        void destroy(){
            account--;
            cout<<"Account of Mr."<<account_holder_name<<" with account no "<<account_number<<" is destroyed with a balance BDT "<<current_balance<<endl;
        }
};

int BankAccount::account=0;
int BankAccount::created=0;
double BankAccount::tax=0.0;

void display_stat(){
    cout<<"Total number of account created: "<<BankAccount::created<<endl;
    cout<<"Total number of accounts present: "<<BankAccount::account<<endl;
    cout<<"Total amount of source tax collected: "<<BankAccount::tax<<endl;
}

BankAccount Larger(const BankAccount A, const BankAccount B){
    if(A.getCuurentBalance()>B.getCuurentBalance()){
        return A;
    }
    else{
        return B;
    }
}

int main(){
    BankAccount b1=BankAccount(111,"Arafat","savings",5000.00);
    BankAccount b2=BankAccount(112,"Farhan","savings",7000.00);
    BankAccount b3=BankAccount(113,"Hasan","current",3000.00);
    b1.show();
    b1.deposit(650.00);
    b1.withdrawal(2500.00);
    b1.showBalance();
    b1.giveInterest();
    b1.show();
    b1.~
    display_stat();
    b2.destroy();
    display_stat();
}