#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<string>
using namespace std;

class Employee {
    string name,dob;
    double salary;

    public:
        void setName(string s);
        void setDob(string d);
        void setSalary(double s);

        string getName() const;
        string getDob() const;
        double getSalary() const;

        void setInfo();
        void getInfo() const;
        
        Employee compareAge(const Employee e) const;
};

#endif