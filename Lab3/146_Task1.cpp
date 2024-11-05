#include<bits/stdc++.h>
using namespace std;

class Counter {
    int incrementStep;
    int count;
    public:
        Counter(){
            count=0;
            incrementStep=0;
        }
        void setIncrementStep(int val){
            incrementStep=val;
        }
        void increment(){
            count+=incrementStep;
        }
        int getCount(){
            return count;
        }
        void resetCount(){
            count=0;
        }
};

int main(){
    Counter c1;
    cout<<c1.getCount()<<endl;
    c1.increment();
    cout<<c1.getCount()<<endl;
    c1.setIncrementStep(4);
    c1.increment();
    cout<<c1.getCount()<<endl;
    c1.resetCount();
    cout<<c1.getCount()<<endl;
}