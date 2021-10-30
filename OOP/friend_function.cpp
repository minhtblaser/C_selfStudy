#include <iostream>
using namespace std;
class A;
class B {
    public:
        void showA(A);
};
class A {
    int data; //
    friend void setData(A&);
    public:
        A(){
            data = 100;
        }
        void show();
        // friend void setData(A&);
        friend void B::showA(A);
};
void A::show(){
    cout << data << endl;
}
void setData(A &a){
    a.data = 255;
}
void B::showA(A a){
    cout << a.data << endl;
}
int main(){
    A a;
    B b;
    setData(a);
    b.showA(a);
    return 0;
}