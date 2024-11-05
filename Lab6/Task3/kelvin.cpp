#include <iostream>
#include "celsius.h"
#include "farenhait.h"
#include "kelvin.h"
using namespace std;

Kelvin::Kelvin(double value = 0)
{
    val = value;
}

void Kelvin::assign(double value)
{
    if (value < 0.0)
    {
        cout << "Temperature is lower than absolute zero temperature" << endl;
    }
    else
    {
        val = value;
    }
    return;
}

void Kelvin::display()
{
    cout << "The temperature is " << val << " Kelvin" << endl;
    return;
}

Kelvin::operator Celsius() const
{
    return Celsius(val - 273.15);
}

Kelvin::operator Farenhait() const
{
    return Farenhait(((val - 273.15)) * (9.0 / 5.0) + 32.0);
}