#include<bits/stdc++.h>
using namespace std;

class Temperature {
    double tempValue;
    char unit;
    bool flag;
    bool Convert;
    public:
        void assign(double val, char u){
            if((u=='C' && val<-273.15) || (u=='F' && val<-459.67) || (u=='K' && val<0)){
                cout<<"Lower than absolute zero temperature"<<endl;
                flag=0;
            }
            else{
                tempValue=val;
                unit=u;
                flag=1;
            }
        }
        double convert(char u){
            Convert=1;
            switch(unit){
                case 'C':
                    if(u=='F'){
                        tempValue=(tempValue*(9.0/5.0))+32.0;
                        unit=u;
                    }
                    else if(u=='K'){
                        tempValue=tempValue+273.15;
                        unit=u;
                    }
                    break;
                case 'F':
                    if(u=='C'){
                        tempValue=(tempValue-32.0)*(5.0/9.0);
                        unit=u;
                    }
                    else if(u=='K'){
                        tempValue=(tempValue-32.0)*(5.0/9.0)+273.15;
                        unit=u;
                    }
                    break;
                case 'K':
                    if(u=='C'){
                        tempValue=tempValue-273.15;
                        unit=u;
                    }
                    else if(u=='F'){
                       tempValue=(tempValue-273.15)*(9.0/5.0)+32.0; 
                       unit=u;
                    }
                    break;
            }
            return tempValue;
        }
        void print(){
            if(flag){
                cout<<"The temperature is "<<tempValue<<" "<<unit<<endl;
                return;
            }
            if(Convert){
                cout<<"The temperature is "<<convert(unit)<<" "<<unit<<endl;
                return;
            }
        }
};

int main(){
    Temperature t1;
    t1.assign(56.7,'C');
    t1.print();
    t1.convert('K');
    t1.print();
}