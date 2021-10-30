#include <iostream>

using namespace std;

int solve(int n){
    int sum = 0, k = 2;
    while (n>1){
        while(n % k == 0){
            sum += k;
            n /= k;
        }
        k++;
    }
    return sum;
}
int factorial(int n){
    while (n != solve(n)){
        n = solve(n);
    }
    return n;
}
int main(){
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}