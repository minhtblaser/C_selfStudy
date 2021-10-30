#include<iostream>
using namespace std;
class A{
    public:
        virtual void show(){
            cout<<"Hello A";
        }
        
        //ham thuan ao, khai bao o lop co so
        virtual void show1() = 0;
};
class B:public A{
    public:
        void show(){
            cout<<"Hello B";    
        }
        void show1(){
            cout<<"Hello B";    
        }
};
class C:public A{
    public:
        void show(){
            cout<<"Hello C";
        }
        void show1(){
            cout<<"Hello C";
        }
};
int main(){
    A *a1 = new B;
    a1->show1();
}