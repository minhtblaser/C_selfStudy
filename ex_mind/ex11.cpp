#include <iostream>

using namespace std;

long long numberZeroDigits(long long n){
    int k = 5;
    int d = 0;
    while(k <= n){
        d += n/k;
        k *=5;
    }
    return d;
}
int main(){
    long long n;
    cin >> n;
    cout << numberZeroDigits(n);
    return 0;
}