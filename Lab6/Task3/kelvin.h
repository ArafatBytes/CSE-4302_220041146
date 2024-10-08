#ifndef KelvinHeader_H
#define KelvinHeader_H
#include <iostream>
using namespace std;

class Celsius;
class Farenhait;

class Kelvin
{
    double val;

public:
    Kelvin(double value);
    void assign(double value);
    void display();
    operator Celsius() const;
    operator Farenhait() const;
};

#endif