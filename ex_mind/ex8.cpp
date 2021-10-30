#include <iostream>

using namespace std;

int lastDigit(int n){
    int res = 1;
    for(int i = 2; i<=n; i++){
        res *= i;
        while (res % 10 == 0 && res > 9){
            res /= 10; 
        }
        res %= 100;
    }
    return res %= 10;
}
int main(){
    int n;
    cin >> n;
    cout << lastDigit(n);
    return 0;
}