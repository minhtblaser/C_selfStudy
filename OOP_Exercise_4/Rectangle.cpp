#include <iostream>
#include "Shape.cpp"
using namespace std;

class Rectangle : public Shape{
    private:
        double length, width;
    public:
        Rectangle(double width, double length){
            this->width = width;
            this->length = length;
        }
        double getArea(){
            return width * length;
        }
        double getPerimeter(){
            return (length + width) * 2;
        }
};