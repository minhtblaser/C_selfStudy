#include <iostream>

using namespace std;

void move(int n, char a, char b, char c);

int main(){
    int n;
    char a = 'A',b = 'B',c = 'C';
    cout << "Enter N: ";
    cin >> n;
    move(n,a,b,c);
    return 0;
}

void move(int n, char a, char b, char c){
    if(n == 1){
        cout << a << "==>" << c << endl;
    } else {
        move (n-1, a, c, b);
        cout << a << "==>" << c << endl;
        move(n-1, b, a, c);
    }
}