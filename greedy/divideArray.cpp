#include <bits/stdc++.h>

using namespace std;

int main(){
    long long sum1 = 0, sum2 = 0, res = 0;
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int i = 0;
    while(i<n){
        if(i<k){
            sum1 += a[i];
        } else {
            sum2 += a[i];
        }
        i++;
    }
    res = abs(sum1 - sum2);
    i = 0;
    while(i<n){
        if(i<n-k){
            sum1 += a[i];
        } else {
            sum2 += a[i];
        }
        i++;
    }
    res = max(res,abs(sum1 - sum2));
    cout << res;
    return 0;
}