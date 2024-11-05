#include "header.h"
#include<bits/stdc++.h>
using namespace std;

Animal::Animal(string n,string h,string s,int w, int he):nameOfAnimal(n),habitat_area(h),sound(s),weight(w),height(he){};
void Animal::displayInformation(){
     cout<<"Name: "<<nameOfAnimal<<endl;
     cout<<"Habitat: "<<habitat_area<<endl;
     cout<<"Sound: "<<sound<<endl;
     cout<<"Weight: "<<weight<<endl;
     cout<<"Height: "<<height<<endl;
}
void Animal::changeWeight(int w){
     weight=w;
}
void Animal::make_sound(){
     cout<<sound<<endl;
}

Cow::Cow(string n,string h,int w, int he,double m):Animal(n,h,"moo",w,he){
     milkProductionInLitres=m;
}
void Cow::make_sound(){
     cout<<"The cow says: ";
     Animal::make_sound();
     cout<<endl;
}
double Cow::getMilkProduction(){
     return milkProductionInLitres;
}

Chicken::Chicken(string n,string h,int w, int he,int egg):Animal(n,h,"buck buck",w,he){
     dailyEggCount=egg;
}
void Chicken::make_sound(){
     cout<<"The chicken says: ";
     Animal::make_sound();
     cout<<endl;
}
int Chicken::getEggCount(){
     return dailyEggCount;
}

Cat::Cat(string n,string h,int w, int he):Animal(n,h,"meow",w,he){};
void Cat::make_sound(){
     cout<<"The cat says: ";
     Animal::make_sound();
     cout<<endl;
}

PetCat::PetCat(string n,string h,int w, int he,string pn):Cat(n,h,w,he){
     petName=pn;
};
void PetCat::make_sound(){
     cout<<petName<<"calls: ";
     Cat::make_sound();
     cout<<endl;
}
