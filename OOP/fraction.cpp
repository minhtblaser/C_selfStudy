#include <bits/stdc++.h>

using namespace std;

class Fraction {
    private:
        float first;
        float second;
    public: 
        void getData();
        void sum(Fraction a, Fraction b);
        void minus(Fraction a, Fraction b);
        void multiply(Fraction a, Fraction b);
        void divide(Fraction a, Fraction b);
};
void Fraction::getData(){
    cout << "Denominator: ";
    cin >> first;
    cout << "Numerator: ";
    cin >> second;
}
void Fraction::sum(Fraction a, Fraction b){
    Fraction s;
    s.first = a.first*b.second + a.second*b.first;
    s.second = a.second * b.second;
    cout << s.first << "/" << s.second << endl;
}
void Fraction::minus(Fraction a, Fraction b){
    Fraction s;
    s.first = a.first*b.second - a.second*b.first;
    s.second = a.second * b.second;
    cout << s.first << "/" << s.second << endl;
}
void Fraction::multiply(Fraction a, Fraction b){
    Fraction s;
    s.first = a.first*b.first;
    s.second = a.second * b.second;
    cout << s.first << "/" << s.second << endl;
}
void Fraction::divide(Fraction a, Fraction b){
    Fraction s;
    s.first = a.first*b.second;
    s.second = a.second * b.first;
    cout << s.first << "/" << s.second << endl;
}
int main(){
    Fraction a;
    Fraction b;
    Fraction c;
    a.getData();
    b.getData();
    c.sum(a,b);
    c.minus(a,b);
    c.multiply(a,b);
    c.divide(a,b);
    return 0;
}