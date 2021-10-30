#include <bits/stdc++.h>

using namespace std;

int main(){
    long long k;
    int res = 0;
    cin >> k;
    int a[] = {5000,10000,20000,50000,100000,200000,500000};
    while(k > 0){
        for(int i = 6; i > 0; i--){
            res += k / a[i];     
            k %= a[i];
        }   
    }
    cout << res << endl;
    return 0;
}