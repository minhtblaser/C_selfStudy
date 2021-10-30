#include <bits/stdc++.h>

using namespace std;

map <long long ,bool> d;
long long res;
vector<int>a;
int u[20];

void Try(int i, int n){
    for(int j = 0; j<=1; j++){
        u[i] = j;
        if(i == n-1){
            long long ans = 0;
            for(int l = 0; l < n; l++){
                if(u[l] == 1){
                    ans = ans*10 + a[l];
                } 
            }
            if(d[ans] == true && ans != 0 && res < ans){
                res = ans;
            }
        } else {
            Try(i+1,n);
        }
    }
}

int main(){
    for(long long i = 1; i<1000000; i++){
        d[i*i*i] = true;
    }
    long long n;
    cin >> n;
    while(n){
        a.push_back(n%10);
        n/=10;
    }
    reverse(a.begin(), a.end());
    res = -1;
    Try(0,a.size());
    cout << res << endl;
    return 0;
}

