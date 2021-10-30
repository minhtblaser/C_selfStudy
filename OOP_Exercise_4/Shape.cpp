#pragma once
#include <iostream>

using namespace std;

class Shape{
    public:
        virtual double getPerimeter() = 0;
        virtual double getArea() = 0;
};