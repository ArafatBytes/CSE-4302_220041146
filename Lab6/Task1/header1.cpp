#include <iostream>
#include "header1.h"
using namespace std;

Counter::Counter()
{
    count = 0;
    increment_step = 0;
}

Counter::~Counter() {}

void Counter::setIncrementStep(int a = 1)
{
    if (a < 0)
    {
        return;
    }
    if (count == 0)
    {
        increment_step = a;
    }
    else
    {
        cout << "Can not set the increment step" << endl;
    }
}

int Counter::getCount()
{
    return count;
}

void Counter::increment()
{
    count += increment_step;
}

void Counter::resetCount(int step = 1)
{
    count = 0;
    setIncrementStep(step);
}

Counter Counter::operator+(const Counter &c) const
{
    if (increment_step == c.increment_step)
    {
        Counter temp;
        temp.count = count + c.count;
        temp.increment_step = increment_step;
        return temp;
    }
    else
    {
        cout << "Increment step is not the same" << endl;
    }
}

bool Counter::operator<(const Counter &right) const
{
    return count < right.count;
}
bool Counter::operator>(const Counter &right) const
{
    return count > right.count;
}
bool Counter::operator<=(const Counter &right) const
{
    return count <= right.count;
}
bool Counter::operator>=(const Counter &right) const
{
    return count >= right.count;
}
bool Counter::operator==(const Counter &right) const
{
    return count == right.count;
}
bool Counter::operator!=(const Counter &right) const
{
    return count != right.count;
}

Counter Counter::operator+=(const Counter &c)
{
    count += c.count;
    increment_step = max(increment_step, c.increment_step);
    return *this;
}

Counter Counter::operator++()
{
    ++count;
    return *this;
}

Counter Counter::operator++(int)
{
    ++count;
    return *this;
}

Counter Counter::operator=(const Counter &c)
{
    count = c.count;
    increment_step = c.increment_step;
    return *this;
}