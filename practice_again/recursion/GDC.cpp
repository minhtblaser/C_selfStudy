#include <bits/stdc++.h>

using namespace std;

int GDC(int a, int b){
    if(b == 0) return a;
    if(a % b == 0) return b;
    return GDC(b,a%b);
}
int main(){
    int a,b;
    cin >> a >> b;
    cout << GDC(a,b);
    return 0;
}