#include <iostream>
// nested recursion 
using namespace std;

int akermann(int m, int n){
    if(m == 0){
        return n+1;
    } else if (n == 0){
        return akermann(m-1, 1);
    } else {
        return akermann(m-1, akermann(m,n-1));
    }
}

int main(){
    int result = akermann(4,5);
    cout << result << endl;
    return 0;
}