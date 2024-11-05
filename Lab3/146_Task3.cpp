#include<bits/stdc++.h>
using namespace std;

class Time {
    int hour,minute,second;
    int hours(){
        return hour;
    }
    int minutes(){
        return minute;
    }
    int seconds(){
        return second;
    }
    public:
        Time(){
            hour=0;
            minute=0;
            second=0;
        }
        void reset(int h, int m, int s){
            hour=h;
            minute=m;
            second=s;
        }
        void advance(int h, int m, int s){
            int tot_sec=second+s;
            int extra_min=tot_sec/60;
            second=(tot_sec-(extra_min*60));
            int tot_min=minute+m+extra_min;
            int extra_hour=tot_min/60;
            minute=(tot_min-(extra_hour*60));
            hour+=h+extra_hour;
            if(hour>=24){
                hour-=24;
            }
        }
        void print(){
            cout<<hours()<<":"<<minutes()<<":"<<seconds()<<endl;
        }
};

int main(){
    Time t1;
    t1.reset(10,25,28);
    t1.print();
    t1.advance(13,45,34);
    t1.print();
}