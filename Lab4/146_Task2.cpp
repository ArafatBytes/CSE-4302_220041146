#include<bits/stdc++.h>
using namespace std;

class Flight {
    int flight_number;
    string destination;
    double distance;
    double maxFuelCapacity;
    double CalFuel(){
        if(distance<=1000){
            return 500.00;
        }
        else if(distance<=2000){
            return 1100.00;
        }
        else {
            return 2200.00;
        }
    }
    public:
        void FeedInfo(){
            cout<<"Flight number: ";
            cin>>flight_number;
            cout<<"Destination: ";
            cin>>destination;
            cout<<"Distance: ";
            cin>>distance;
            cout<<"Max Fuel Capacity: ";
            cin>>maxFuelCapacity;
        }
        void ShowInfo(){
            cout<<"Flight number: "<<flight_number<<endl;
            cout<<"Destination: "<<destination<<endl;
            cout<<"Distance: "<<distance<<endl;
            cout<<"Max Fuel Capacity: "<<maxFuelCapacity<<endl;
            if(maxFuelCapacity>CalFuel()){
                cout<<"Fuel capacity is fit for this flight distance"<<endl;
            }
            else{
                cout<<"Not sufficient Fuel capacity for this flight."<<endl;
            }
        }
};

int main(){
    Flight f1;
    f1.FeedInfo();
    f1.ShowInfo();
}