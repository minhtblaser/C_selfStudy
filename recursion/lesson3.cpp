#include <iostream>
// exponential  recursion
using namespace std;

int gcd(int m,int n){
    int r;
    if (m < n) return gcd (n,m);
    r = m % n;
    if( r == 0){
        return n;
    } else {
        return gcd(m,r);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int result = gcd(m,n);
    cout << "\nYour result: " << result << endl;
    return 0;
}