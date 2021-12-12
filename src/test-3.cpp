#include <iostream>

using namespace std;

class A {
    int x;
    public:
        A() : x(2){}
        void funcA(){
            cout << "X = " << x;
        }
};
class B : private A {
    int y;
    public:
        B() : y(3){}
        void funcA(){
            A::funcA();
            cout << "Y = " << y;
        }
};
int main(){
    B *b = new B();
    b->funcA();
}