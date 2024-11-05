#include<bits/stdc++.h>
#include "header.h"
using namespace std;

int main(){
     Cow cow("Nakib","our room",150,175,25.9);
     cow.make_sound();
     cout<<cow.getMilkProduction()<<endl;

     Chicken chick("Turjo","our room",80,170,5);
     chick.make_sound();
     cout<<chick.getEggCount()<<endl;

     Cat cat("Hasan","north",80,170);
     cat.make_sound();

     PetCat pc("Farhan","north",85,180,"roomCat");
     pc.make_sound();
}
