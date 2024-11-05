#include <iostream>
#include "celsius.h"
#include "farenhait.h"
#include "kelvin.h"
using namespace std;

int main()
{
    Celsius c(50);
    c.assign(80);
    c.display();
    Farenhait f = c;
    f.display();
    Kelvin k = f;
    k.display();
}