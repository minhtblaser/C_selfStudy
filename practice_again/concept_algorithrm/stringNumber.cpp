#include <bits/stdc++.h>

using namespace std;
long long const  mod = 123456789;

long long pow2(long long n){
    if(n == 0) return 1;
    if(n == 1) return 2;
    return (2*pow2(n-1)) % mod;
}
int main(){
    long long n;
    cin >> n;
    n -= 1;
    cout << pow2(n) << endl;
    return 0;
}