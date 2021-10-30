#include <iostream>

using namespace std;
class Animal {
    public: 
        virtual void move (){
            cout<<"Animal is moving." << endl;
        }
};
class Cat : public Animal{
    public: 
        void move () override{
            cout<<"Cat is running." << endl;
        }
};
class Dolphin : public Animal{
    public: 
        void move () override{
            cout <<"Dolphin is swimming. " << endl;
        }
};
int main(){
    Animal *a;
    a = new Animal();
    a->move();
    //Cat    
    a = new Cat();
    a->move();
    //Dolphin
    a = new Dolphin();
    a->move();
    return 0;
}