#include <bits/stdc++.h>

using namespace std;

class Fraction{
    private:
        int first, second;
    public:
    friend istream&operator>>(istream&is, Fraction &source){
            cout << "Enter denominator: ";
            is >> source.first;
            cout << "Enter numerator: ";
            is >> source.second;
    }
    friend ostream&operator<<(ostream&os, Fraction source){
            os << source.first << "/" << source.second << endl;
            return os;
    }
    void showInfo(){
            cout << first << "/" << second << endl;
        }
    friend Fraction operator-(Fraction a, Fraction b);
    friend Fraction operator+(Fraction a, Fraction b);
    friend Fraction operator*(Fraction a, Fraction b);
    friend Fraction operator/(Fraction a, Fraction b);
    friend Fraction operator++(int);
    bool operator>(Fraction b);
    bool operator==(Fraction b);
};   
Fraction operator++(int){
    first = first + second;
    second = second;
    return *this;
}
Fraction operator-(Fraction a, Fraction b){
    Fraction s;
    s.first = a.first * b.second - a.second*b.first;
    s.second = a.second * b.second;
    return s;
}
Fraction operator+(Fraction a, Fraction b){
    Fraction s;
    s.first = a.first * b.second  + a.second*b.first;
    s.second = a.second * b.second;
    return s;
}
Fraction operator*(Fraction a, Fraction b){
    Fraction s;
    s.first = a.first*b.first;
    s.second = a.second * b.second;
    return s;
}
Fraction operator/(Fraction a, Fraction b){
    Fraction s;
    s.first = a.first*b.second;
    s.second = a.second * b.first;
    return s;
}
bool Fraction::operator>(Fraction b){
    if(first*b.second > b.first*second){
        return true;
    } else {
        return false;
    }
}
bool Fraction::operator==(Fraction b){
    if(first*b.second == b.first*second){
        return true;
    } else {
        return false;
    }
}
int main(){
    Fraction a,b;
    cout << "Enter fraction 1: "<< endl;
    cin >> a;
    cout << a;
    cout << "Enter fraction 2: "<< endl;
    cin >> b;
    cout << b;
    Fraction sum = a+b;
    Fraction minus = a-b;
    Fraction dive = a/b;
    Fraction multiply = a*b;
    sum.showInfo();
    minus.showInfo();
    dive.showInfo();
    multiply.showInfo();
    if(a>b){
        cout << "a greater than b";
    } else if (a==b) {
        cout << "a equal b";
    } else {
        cout << "a less than b";
    }
    cou << a++;
    cout << ++a;
    return 0;
}