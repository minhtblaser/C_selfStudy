#include <bits/stdc++.h>

using namespace std;

int maxFraction(int a[], int b[], int n){
    int ans = 0, temp = 100000;
    for(int i = 0; i < n; i++){
        if(a[0] * b[i] < b[0] * a[i] && temp > a[0]*b[i]){
            ans = i;
            temp = a[0]*b[i];
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    int a[100], b[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    cout << maxFraction(a,b,n);
    return 0;
}