#include <iostream>
#include <string>
#include <algorithm>
#include "header.h"
using namespace std;

string genName()
{
    string name;
    for (int i = 0; i < rand() % 7 + 4; i++)
    {
        name.push_back(rand() % 26 + 65);
    }
    name.push_back(" ");
    for (int i = 0; i < rand() % 7 + 4; i++)
    {
        name.push_back(rand() % 26 + 65);
    }
    return name;
}

string genAddress()
{
    string name;
    for (int i = 0; i < rand() % 7 + 4; i++)
    {
        name.push_back(rand() % 26 + 65);
    }
    name.push_back(" ");
    for (int i = 0; i < rand() % 7 + 4; i++)
    {
        name.push_back(rand() % 26 + 65);
    }
    name.push_back(" ");
    for (int i = 0; i < rand() % 7 + 4; i++)
    {
        name.push_back(rand() % 26 + 65);
    }
    name.push_back(" ");
    for (int i = 0; i < rand() % 7 + 4; i++)
    {
        name.push_back(rand() % 26 + 65);
    }
    name.push_back(" ");
    for (int i = 0; i < rand() % 7 + 4; i++)
    {
        name.push_back(rand() % 26 + 65);
    }
    return name;
}

double genInterest()
{
    return (rand() % 4 + 2);
}

double genBalance()
{
    return (rand() % (50000 - 1000 + 1) + 1000);
}

double genAmount()
{
    return (rand() % 1500 + 1000);
}

int genTime()
{
    return (rand() % 36 + 12);
}

string genYN()
{
    return ((rand() % 2) ? "YES" : "NO");
}

void ShowInterestAll(SavingsAccount (&acc)[100])
{
    for (int i = 0; i < 100; i++)
    {
        cout << "Enter time of interest: ";
        cout << genTime() << endl;
        cout << "Interest collected: " << acc[i].calculateInterest(genTime()) << endl;
        cout << "Do you want to disburse the interest?" << endl;
        cout << genYN() << endl;
        if (genYN() == "YES")
        {
            acc[i].disburseInterest(genTime());
        }
    }
}

void ShowAllAlphabetically(SavingsAccount (&acc)[100])
{
    sort(acc, acc + 100);
    for (int i = 0; i < 100; i++)
    {
        cout << "Account Name: " << acc[i].getAccName() << endl;
        cout << "Current Balance: " << acc[i].getBalance() << endl;
    }
}

int main()
{
    SavingsAccount account[100];
    for (int i = 0; i < 100; i++)
    {
        account[i].setAccName(genName());
        account[i].setAccHolderName(genName());
        account[i].setAddress(genAddress());
        account[i].setIR(genInterest());
        account[i].setBalance(genBalance());
    }
    ShowInterestAll(account);
    cout << endl;
    ShowAllAlphabetically(account);
    cout << endl;
}