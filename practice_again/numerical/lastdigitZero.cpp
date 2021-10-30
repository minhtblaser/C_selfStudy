#include <bits/stdc++.h>

using namespace std;

int factorial(int n){
    if(n>0) return  n*factorial(n-1);
    else{
    return 1;
    }
}
int main(){
    int num2 = 0, num5 = 0;
    int n;
    cin >> n;
    int result_factor = factorial(n);
    while(result_factor % 2 == 0){
        result_factor /= 2;
        num2++;
    }
    while(result_factor % 5 == 0){
        result_factor /= 5;
        num5++;
    }
    int k = min(num2, num5);
    int d = pow(10,k);
    int result = 0;
    result_factor = factorial(n);
    while(result_factor > 10){
        result = result_factor % d;
        result_factor /= d;
    }
    cout << result << endl;
    return 0;
}