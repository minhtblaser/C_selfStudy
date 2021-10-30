#include <iostream>
// mutual recursion
using namespace std;
bool isOdd (int n);
bool isEven (int n){
    if(n == 0){
        return true;
    } else {
        return isOdd(n-1);
    }
}
bool isOdd (int n){
    return !isEven(n);
}
int main(){
    int n;
    cin >> n;
    if (isEven(n)){
        cout << "This is even number" << endl;
    } else {
        cout << "This is odd number" << endl;
    }
    return 0;
}