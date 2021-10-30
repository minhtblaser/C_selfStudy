#include <iostream>

using namespace std;

void H10toH2(int n){
    if(n>0){
        int sd = n%2;
        n /= 2;
        H10toH2(n);
        cout << sd;
    }
}
int main(){
    int n;
    cin >> n;
    H10toH2(n);
    return 0;
}