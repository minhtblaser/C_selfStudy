#include <iostream>

using namespace std;

class Rectangular{
    private:
        double length;
        double width;
    public: 
        Rectangular(){

        };
        Rectangular(double length, double width){
            this->length = length;
            this->width = width;
        }
        void setLength(double length){
            this->length = length;
        }
        double getLength(){
            return this->length;
        }
        void setWidth(double width){
            this->width = width;
        }
        double getWidth(){
            return this->width;
        }
        double getPerimeter(){
            return (length + width) * 2;
        }
        double getArea(){
            return length * width;
        }
};

int main(){
    Rectangular r(3,5);
    cout <<"Perimeter: " <<r.getPerimeter() << endl;
    cout <<"Area: "<<r.getArea() << endl;
    r.setLength(10);
    r.setWidth(12);
    cout <<"Perimeter: " <<r.getPerimeter() << endl;
    cout <<"Area: "<<r.getArea() << endl;
    return 0;
}