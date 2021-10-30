#include <bits/stdc++.h>

using namespace std;

const long long mod  = 1e9 + 7;
int main(){
    int n;
    long long value, res = 0; 
    cin >> n; 
    priority_queue<long long, vector<long long >, greater<>> a;
    for(int i=0; i<n; i++){
        cin >> value;
        a.push(value);
    }
    while(a.size() > 1){
        long long x = a.top(); a.pop();
        long long y = a.top(); a.pop();
        long long temp = (x+y)%mod;
        a.push(temp);
        res += temp;
        res %= mod;
    }
    cout << res << endl;
    return 0;
}