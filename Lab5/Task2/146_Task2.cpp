#include<iostream>
#include "header.h"
using namespace std;

int main(){
    Employee e,f,greater;
    e.setInfo();
    e.getInfo();
    greater=e.compareAge(f);
    cout<<"Greater is: "<<greater.getName()<<endl;
}