#include <bits/stdc++.h>

using namespace std;

int digitProduct(int n){
    int ans1 = 0, ans2 = 0;
    for(int i=9; i>=2; i--){
        while(n % i == 0){
            ans1 = ans1*10 + i;
            n /= i;
        }
    }
    while(ans1 > 0){
        ans2 = ans2*10 + ans1%10;
        ans1 /= 10;
    }
    return ans2;
}
int main(){
    int n;
    cin >> n;
    cout << digitProduct(n);
    return 0;
}