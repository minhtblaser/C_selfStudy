#include <bits/stdc++.h>

using namespace std;

class A {
    private:
        int x,y;
    public:
        A(){
            this->x = 0;
            this->y = 0;
        }
        A(int x,int y){
            this->x = x;
            this->y = y;
        }
        A(const A& other){
            this->x = other.x;
            this->y = other.y;
        }
        ~A();
        friend istream& operator>>(istream&is, A &input);
        friend ostream& operator<<(istream&os, A output);
        int operator+(A a);
        bool operator>(A a);
};
istream& operator>>(istream&is, A &input){
    cout << "Enter x: ";
    is >> input.x;
    cout << "Enter y: ";
    is >> input.y;
    return is;
}
ostream& operator<<(istream&os, A output){
    os << output.x;
    cout << endl;
    os << output.y;
    return os;
}
int A::operator+(A a){
    return (this->x + a.x && this->y + a.y);
}
bool A::operator>(A a){
    return (this->x > a.x && this->y > a.y);
}
class B:public A{
	private:
		int z;
	public:
		B();
    	B(int x, int y);
    	B(const B &z);
    	~B();
    	friend &istream operator >> (istream &is, B &b);
    	friend &ostream operator << (ostream &os, B b);
    	bool operator > (B b);
    	int operator + (B b);
};
B::B(){
	this->z = 0;
}
B::B(int x, int y){
	this->z = z;
}
B::B(const B &other){
	this->z = other.z;
}
B::operator >>(istream &is, B &b){
	cout << "Nhap z: ";
	is >> z;
	return is;
}
B::operator <<(ostream &os, B b){
	os << "z = " << z<<endl;
    return os;
}
bool B::operator >(B b){
	A::operator >(b);
    return z > b.z;
}
int B::operator +(B b){
	A::operator +(b);
    z = z + other.z;
    return *this;	
}
int main (){
    A a;
    B b;
    cin >> a >> b;
    cout << a;
    cout << b << endl;
    A c;
    B d;
    cin >> c;
    cin >> d;
    if(b > d) cout << "yes" << endl;
    else cout  << "no" << endl;
    cout << (a+c);
    cout << (d+b) << endl;
}
