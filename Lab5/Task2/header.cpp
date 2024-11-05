#include<iostream>
#include "header.h"
using namespace std;

void Employee::setName(string s){
    if(s.length()>2){
        name=s;
    }
    else{
        name="John Doe";
    }
}
void Employee::setDob(string d){
    int year=stoi(d.substr(6,4));
    if(2024-year>=18){
        dob=d;
    }
    else{
        dob="01/01/2002";
    }
}
void Employee::setSalary(double s){
    if(s<10000.0 || s>100000.0){
        salary=10000.0;
    }
    else{
        salary=s;
    }
}
string Employee::getName() const{
    return name;
}
string Employee::getDob() const{
    return dob;
}
double Employee::getSalary() const{
    return salary;
}
void Employee::setInfo(){
    string n,d;
    double s;
    cout<<"Enter the name: ";
    cin>>n;
    cout<<"Enter Date of birth: ";
    cin>>d;
    cout<<"Enter salary: ";
    cin>>s;
    setName(n);
    setDob(d);
    setSalary(s);
}
void Employee::getInfo() const{
    cout<<"Employee name: "<<getName()<<endl;
    cout<<"Employee Date of birth: "<<getDob()<<endl;
    cout<<"Employee salary: "<<getSalary()<<endl;
}

Employee Employee::compareAge(const Employee e) const{
    if(stoi(dob.substr(6,4))>stoi(e.dob.substr(6,4))){
        return *this;
    }
    else{
        return e;
    }
}