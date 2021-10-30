#include <iostream>
// linear recursion 
using namespace std;

int count(int n){
    if (n==0 || n = 1) return 1;
        return n*count(n-1);
}
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Result: " << count(n) << endl;
    return 0;
}