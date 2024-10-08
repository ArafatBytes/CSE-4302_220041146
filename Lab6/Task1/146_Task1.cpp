#include <iostream>
#include "header1.h"
using namespace std;

int main()
{
    Counter c1, c2, c3;
    c2.setIncrementStep(5);
    c2.increment();
    c3.setIncrementStep(5);
    c3.increment();
    c1 = c2 + c3;
    cout << c1.getCount() << endl;
    if (c1 <= c2)
    {
        cout << "c1 is smaller than c2" << endl;
    }
    else
    {
        cout << "c1 is larger than c2" << endl;
    }
    if (c2 == c3)
    {
        cout << "c2 is equal to c3" << endl;
    }
    else
    {
        cout << "c2 is not equal to c3" << endl;
    }
    c1 += c2;
    cout << c1.getCount() << endl;
    c1 = ++c2;
    cout << c1.getCount() << endl;
    c3 = c1++;
    cout << c3.getCount() << endl;
}