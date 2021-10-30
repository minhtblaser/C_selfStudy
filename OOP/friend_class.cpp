#include <iostream>
using namespace std;
class A;
class B {
    public:
        void showA(A);
        void setAData(A &);
};
class A {
    int data; //
    friend void setData(A&);
    public:
        A(){
            data = 100;
        }
        void show();
        friend class B;
};
void A::show(){
    cout << data << endl;
}
void B::setAData(A &a){
    a.data = 255;
}
void B::showA(A a){
    cout << a.data << endl;
}
int main(){
    A a;
    B b;
    b.showA(a); // show original data
    b.setAData(a); // change the data 
    b.showA(a); //show new data
    return 0;
}