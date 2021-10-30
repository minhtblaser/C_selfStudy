#include <bits/stdc++.h>

using namespace std;

int x[11];
bool b[11];

void printArray(int a[], int n){
    for(int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << " ";
}
void solve(int k, int n){
    for(int i = 1; i <= n; i++){
        if(b[i]){
            x[k] = i;
            if(k == n){
                printArray(x,n);
            } else {
                b[i] = false;
                solve(k+1,n);
                b[i] = true;
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i<= n; i++){
        b[i] = true;
    }
    solve(1,n);
    return 0;
}