#include <bits/stdc++.h>

using namespace std;

int main(){
    long long res7 = 1e7, res4 = 1e7;
    int d4 = 0, d7 = 0;
    int n;
    cin >> n;
    for(int i = n; i>=0; i--){
        if(n >= 4*i && (n-4*i)%7 == 0){
            d4 = i;
            d7 = (n-4*i)/7;
            if(res7 + res4 > d4 + d7){
                res7 = d7;
                res4 = d4;
            } else if(res4 + res7  == d4 + d7){
                if(res4 > d4){
                    res4 = d4;
                    res7 = d7;
                }
            }
        }
    }
    if(res4*4 + res7*7 == n)
    {
        for(int i = 0; i<res4; i++){
            cout << 4;
        }
        for(int i=0; i< res7; i++){
            cout << 7;
        }
    } else {
        cout << -1;
    }
    cout << endl;
    return 0;
}