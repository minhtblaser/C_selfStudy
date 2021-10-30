#include <iostream>

using namespace std;

int digitProduct(int n){
    if (n == 1) return 1;
    if (n == 0) return 10;
    int ans = 0;
    int ans2 = 0;
    for(int i = 9; i>=2; i--){
        while(n % i == 0){
            ans = ans * 10 + i;
            n /= i;
        }
    }
    while (ans > 0){
        ans2  = ans2*10 + ans%10;
        ans /= 10;
    }
    return (n == 1) ? ans2 : -1;
}
int main(){
    int n;
    cin >> n;
    cout << digitProduct(n);    
    return 0;
}