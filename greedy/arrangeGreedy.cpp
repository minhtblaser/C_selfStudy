#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, n;
    int a[100], b[100];
    bool check = false;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            b[i] = a[i];
        }
        sort(b,b+n);
        for(int i=0; i<n; i++){
            if(a[i] == b[i] || a[n-i-1] == b[i]){
                check = true;
            } else {
                check = false;
            }
        }
        if(check){
            cout << "yes";
        } else {
            cout << "no";
        }
    }



    return 0;
}