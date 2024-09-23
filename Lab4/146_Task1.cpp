#include<bits/stdc++.h>
using namespace std;

class Calculator {
    int current;
    int getCurrent(){
        return current;
    }
    void setCurrent(int val){
        current=val;
    }
    public:
        Calculator(){
            current=0;
        }
        Calculator(int val):current(val){};
        void add(int value){
            current+=value;
        }
        void subtract(int value){
            current-=value;
        }
        void multiply(int value){
            current*=value;
        }
        int divideBy(int value){
            int remainder;
            if(value==0){
                cout<<"Invalid arithmetic operation."<<endl;
            }
            else{
                remainder=current%value;
                current/=value;
            }
            return remainder;
        }
        void clear(){
            current=0;
        }
        void display(){
            cout<<"Calculator display: "<<current<<endl;
        }
        ~Calculator(){
            display();
            cout<<"Destructor of the Calculator object is called"<<endl;
        }
};

int main(){
    Calculator c1;
    c1.add(10);
    c1.display();
    c1.add(7);
    c1.display();
    c1.multiply(31);
    c1.display();
    c1.subtract(42);
    c1.display();
    c1.divideBy(7);
    c1.display();
    c1.divideBy(0);
    c1.display();
    c1.add(3);
    c1.display();
    c1.clear();
    c1.display();
}