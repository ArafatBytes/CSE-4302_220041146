#include <iostream>
#include "celsius.h"
#include "farenhait.h"
#include "kelvin.h"
using namespace std;

Farenhait::Farenhait(double value = 0)
{
    val = value;
}

void Farenhait::assign(double value)
{
    if (value < -459.60)
    {
        cout << "Temperature is lower than absolute zero temperature" << endl;
    }
    else
    {
        val = value;
    }
    return;
}

void Farenhait::display()
{
    cout << "The temperature is " << val << " Farenhait" << endl;
    return;
}

Farenhait::operator Celsius() const
{
    return Celsius((val - 32.0) * (5.0 / 9.0));
}

Farenhait::operator Kelvin() const
{
    return Kelvin(((val - 32.0) * (5.0 / 9.0)) + 273.15);
}