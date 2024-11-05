#include <iostream>
#include "celsius.h"
#include "farenhait.h"
#include "kelvin.h"
using namespace std;

Celsius::Celsius(double value = 0)
{
    val = value;
}

void Celsius::assign(double value)
{
    if (value < -273.15)
    {
        cout << "Temperature is lower than absolute zero temperature" << endl;
    }
    else
    {
        val = value;
    }
    return;
}

void Celsius::display()
{
    cout << "The temperature is " << val << " Celsius" << endl;
    return;
}

Celsius::operator Farenhait() const
{
    return Farenhait(val * (9.0 / 5.0) + 32.0);
}

Celsius::operator Kelvin() const
{
    return Kelvin(val + 273.15);
}