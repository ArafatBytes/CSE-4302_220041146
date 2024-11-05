#include <bits/stdc++.h>
using namespace std;

class Rational_Number
{
    int up, down;

public:
    void setNumber(int a, int b)
    {
        up = a;
        if (b == 0)
        {
            cout << "denominator can't be 0. The value is set to 1" << endl;
            down = 1;
        }
        else
        {
            down = b;
        }
    };
    Rational_Number operator+(Rational_Number c)
    {
        Rational_Number temp;
        temp.up = (up * c.down) + (down * c.up);
        temp.down = down * c.down;
        return temp;
    };
    Rational_Number operator-(Rational_Number c)
    {
        Rational_Number temp;
        temp.up = (up * c.down) - (down * c.up);
        temp.down = down * c.down;
        return temp;
    };
    Rational_Number operator*(Rational_Number c)
    {
        Rational_Number temp;
        temp.up = up * c.up;
        temp.down = down * c.down;
        return temp;
    };
    Rational_Number operator/(Rational_Number c)
    {
        Rational_Number temp;
        temp.up = up * c.down;
        temp.down = down * c.up;
        return temp;
    };
    void getResult()
    {
        cout << up << "/" << down << endl;
    }
};

int main()
{
    Rational_Number a, b, c;
    a.setNumber(1, 2);
    b.setNumber(3, 4);
    c = a + b;
    c.getResult();
};