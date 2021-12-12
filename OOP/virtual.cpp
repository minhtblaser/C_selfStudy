#include <bits/stdc++.h>

using namespace std;

class Shape {
    public: 
        virtual void display(){
            cout << "Shape" << endl;
        }
};
class Circle : public Shape {
    public:
        void display(){
            cout << "Circle" << endl;
        }
};
int main(){
    Shape *source = new Circle();
    source->display();
    return 0;
}