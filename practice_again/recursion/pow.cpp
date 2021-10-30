#include <bits/stdc++.h>

using namespace std;

long long recursion(int a, int b){
    if(b == 0) return 1;
    return a*recursion(a,b-1);
}
int main(){
    int a,b;
    cin >> a >> b;
    cout << recursion(a,b);
    return 0;
}