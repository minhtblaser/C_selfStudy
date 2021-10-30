#include <iostream>
#include <math.h>
using namespace std;

int sum(int n){
    if (n == 1){
        return 1 ;
    } else {
        return pow(n,2) + sum(n-1);
    }
}

int main(){
    int n;
    cin >> n;   
    int result = sum(n);
    cout << "The result: " << result << endl;
    return 0;
}