#ifndef HEADER_H
#define HEADER_H
#include<bits/stdc++.h>
using namespace std;

class Animal {
     string nameOfAnimal,habitat_area,sound;
     int weight,height;

     public:
          Animal(string n,string h,string s,int w, int he);
          void displayInformation();
          void changeWeight(int _weight);
          void make_sound();
};

class Cow: public Animal {
     double milkProductionInLitres;
     
     public:
          Cow(string n,string h,int w, int he,double m);
          void make_sound();
          double getMilkProduction();

};

class Chicken: protected Animal {
     int dailyEggCount;

     public:
          Chicken(string n,string h,int w, int he,int egg);
          void make_sound();
          int getEggCount();
};

class Cat: private Animal {
     public:
          Cat(string n,string h,int w, int he);
          void make_sound();
};

class PetCat: public Cat {
     string petName;

     public:
          PetCat(string n,string h,int w, int he,string pName);
          void make_sound();
};

#endif