#include <bits/stdc++.h>
using namespace std;

int func(int& par1, char& par2){
    par1++;
    return par1;
}

int main(){
    // int a,b,c,d;
    // char dummyChar;
    // cout<<"Enter first fraction: "<<endl;
    // cin>>a>>dummyChar>>b;
    // cout<<"Enter second fraction: "<<endl;
    // cin>>c>>dummyChar>>d;

    // int upSum=(a*d)+(b*c);
    // int downSum=(b*d);

    // cout<<"Sum= "<<upSum<<"/"<<downSum<<endl;

    int a=5;
    char bb='b';

    int c=func(a,bb);
    cout<<c<<endl;

}