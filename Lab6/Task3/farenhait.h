#ifndef FarenhaitHeader_H
#define FarenhaitHeader_H
#include <iostream>
using namespace std;

class Celsius;
class Kelvin;

class Farenhait
{
    double val;

public:
    Farenhait(double value);
    void assign(double value);
    void display();
    operator Celsius() const;
    operator Kelvin() const;
};

#endif