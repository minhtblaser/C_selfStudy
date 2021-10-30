#include <iostream>
using namespace std;

class Fraction {
    private:
        int tu;
        int mau;
    public:
        Fraction(){
            tu = 0;
            mau = 1;
        }
        Fraction(int tu, int mau){
            this->tu = tu;
            this->mau = (mau == 0)  ? 1 : mau;
        }
        void showInfo(){
            cout << tu << "/" << mau << endl;
        }
        //way 1: 
        Fraction operator+(Fraction const&);
        //way 2:
        friend Fraction operator-(Fraction const&, Fraction const&);
};
Fraction Fraction::operator+(Fraction const &b){
    Fraction s;
    s.tu = tu*b.mau + mau*b.tu;
    s.mau = mau * b.mau;
    return s;
}

Fraction operator-(Fraction const &a, Fraction const &b){
    Fraction s;
    s.tu = a.tu * b.mau  - a.mau*b.tu;
    s.mau = a.mau * b.mau;
    return s;
}
int main(){
    Fraction a(10,3);
    Fraction b(6,9);
    Fraction sum = a + b;
    Fraction minus = a - b;
    sum.showInfo();
    minus.showInfo();
    return 0;
}