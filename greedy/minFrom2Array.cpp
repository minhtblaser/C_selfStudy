#include <bits/stdc++.h>

using namespace std;

int main(){
    long long sum = 0; 
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        sum += a[i]*b[i];
    }
    cout << sum << endl;
    return 0;
}