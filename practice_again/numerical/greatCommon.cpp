#include <bits/stdc++.h>

using namespace std;

vector<bool> mark(100,false);

void isPrimeNumber(int n){
    int a = 2;
    int p = a*a;
    while(true){
        if(p > n){
            break;
        }
        while(p <= n){
            mark[p] = true;
            p += a;
        }
        a++;
        while(a <= n && mark[a] == true){
            a++;
        }
        if(a>n) break;
    }
}
int greatCommonNumber(int a, int b){
    isPrimeNumber(min(a,b));
    for(int i = min(a,b); i >= 2; i--){
        if(mark[i] == false && a % i == 0 && b % i == 0){
            return i;
        }
    }
    return -1;
}
int main(){
    int a,b;
    cin >> a >> b;
    cout << greatCommonNumber(a,b) << endl;
    return 0;
}
