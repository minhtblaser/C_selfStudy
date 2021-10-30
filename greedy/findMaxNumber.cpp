#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int main(){
    long long max = 0;
    int n;
    cin >> n;
    long long a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n; i++){
        max += a[i]*i;
        max %= mod;
    }
    cout << max << endl;
    return 0;
}