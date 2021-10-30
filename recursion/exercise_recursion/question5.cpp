#include <iostream>
#include <math.h>

using namespace std;

int reverse(int n){
    int digit = (int) log10(n);
    if(n == 0){
        return 0;
    }
    return n%10 * pow(10, digit) + reverse(n/10);
}
int main(){
    int n;
    cout<<"enter n: ";
    cin >> n;
    int result = reverse(n);
    cout << "\nThe result: " << result << endl;
    return 0;
}
