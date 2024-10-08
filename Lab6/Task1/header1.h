#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;

class Counter
{
    int count, increment_step;

public:
    Counter();
    ~Counter();
    void setIncrementStep(int step_val);
    int getCount();
    void increment();
    void resetCount(int step);

    Counter operator+(const Counter &c) const;

    bool operator<(const Counter &right) const;
    bool operator>(const Counter &right) const;
    bool operator<=(const Counter &right) const;
    bool operator>=(const Counter &right) const;
    bool operator==(const Counter &right) const;
    bool operator!=(const Counter &right) const;

    Counter operator+=(const Counter &c);

    Counter operator++();
    Counter operator++(int);
    Counter operator=(const Counter &c);
};

#endif