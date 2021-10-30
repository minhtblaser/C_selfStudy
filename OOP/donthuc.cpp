#include <bits/stdc++.h>
//Trinh Ngoc minh
//6151071073
using namespace std;

class Monomial{
    private:
        // data members 
        // a is coefficient
        // b is index number
        float a,b;
    public:
        void getData();
        void display();
        void printValue(int x, Monomial source);
        void compare(Monomial first, Monomial second);
        void derivate(Monomial source);
        void multiply(Monomial source);
        void minus(Monomial source);
        void sum(Monomial source);
        void divide(Monomial source);
};
void Monomial::getData(){
    cout << "Enter coefficient: ";
    cin >> a;
    cout << "Enter index number: ";
    cin >> b;
}
void Monomial::display(){
    cout << "Your monomial: " << a << "x^" << b << endl; 
}
//find value of monomial at x;
void Monomial::printValue(int x, Monomial source){
    Monomial result;
    result.a = source.a * pow(x,source.b);
    cout << "Value at x = " << x <<" is "<< result.a << endl;
}
void Monomial::compare(Monomial first, Monomial second){
    bool kt = true;
    if(first.b == second.b){
        if(first.a < second.a){
            kt = false;
        }
    } else if (first.b < second.b){
        kt = false;
    } else {
        kt = true;
    }
    if(kt == false){
        cout << "Monomial 1 less than Monomial 2" << endl;
    } else {
        cout << "Monomial 1 greater than Monomial 2" << endl;
    }
}
void Monomial::derivate(Monomial source){
    Monomial result;
    result.a = source.a * source.b;
    result.b = source.b - 1;
    cout <<"\nYour derivate: " << result.a << "x^" << result.b << endl;
}
void Monomial::multiply(Monomial source){
    cout << "\nMultiply: " << this->a * source.a << "x^" << this->b + source.b;
}
void Monomial::minus(Monomial source){
    cout << "\nMinus: " << this->a - source.a << "x^" << b;
}
void Monomial::sum(Monomial source){
    cout << "\nSum: " << this->a + source.a << "x^" << b;
}
void Monomial::divide(Monomial source){
    cout << "\nMultiply: " <<float(this->a) / source.a << "x^" << this->b + source.b;
}
int main(){
    Monomial first,second,check;
    cout << "Monomial 1: " << endl;
    first.getData();
    first.display();
    cout << "Monomial 2: " << endl;
    second.getData();
    second.display();
    first.printValue(3,first);
    check.compare(first, second);
    first.derivate(first);
    first.sum(second);
    first.minus(second);
    first.divide(second);
    first.multiply(second);
    return 0;
}