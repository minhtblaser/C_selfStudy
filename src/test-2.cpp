#include <iostream>

using namespace std;

class A{
    public:
        A(){
            cout << "A" << endl;

        }
        ~A(){
            cout << "B" << endl;
        }
};
 
A a;

int main(){
    cout << "Hello world" << endl;
    return 0;
}