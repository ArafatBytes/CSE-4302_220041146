#ifndef CelsiusHeader_H
#define CelsiusHeader_H
#include <iostream>
using namespace std;

class Farenhait;
class Kelvin;

class Celsius
{
    double val;

public:
    Celsius(double value);
    void assign(double value);
    void display();
    operator Farenhait() const;
    operator Kelvin() const;
};

#endif