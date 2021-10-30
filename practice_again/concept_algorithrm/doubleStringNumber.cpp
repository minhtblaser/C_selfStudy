#include <bits/stdc++.h>

using namespace std;

long long pow2(int n){
    if (n == 0) return 1;
    if (n == 1) return 2;
    return 2*pow2(n-1);
}
int main(){
    int n;
    long long k;
    cin >> n >> k;
    int length = pow2(n) / 2;
    while(1){
        if(n == 1){
            return 1;
            break;
        }
        if (k == length){
            return n;
            break;
        }
        if (k > length){
            k = length - (k-length);
        }
        n--;
        length /= 2;
    }
    return 0;
}