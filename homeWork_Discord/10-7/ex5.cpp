#include <bits/stdc++.h>

using namespace std;
// n = 24 
int solve (int n){
    int sum = 0, k = 2; // reset
    while (n>1){
        while (n % k == 0){
            sum += k;
            n /= k;
        }
        k++;
    }
    return sum;
}
int factorSum(int n){
    while(n != solve(n)){//solve(n) = 9 
        n = solve(n); // n = 9; 
        // call stack 
    }
    return n;
}

int main(){
    int n;
    cin >> n;
    cout << factorSum(n) << endl;
    return 0;
}
