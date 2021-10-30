#include <iostream>

using namespace std;
// ethuranos
bool isPrime(int n,bool mark[]){
    if(n<=1) return false;
    int a = 2; 
    while(true){
        if (a*a > n) break;
        int p = a*a;
        while(p<=n){
            mark[p] = true;
            p += a; 
        }
        a++;
        while(a <= n && mark[a] == true) a++;
        if (a>n) break;
    }
    return (mark[n]) ? false:true;
}
int main(){
    int n;
    bool mark[100];
    cin >> n;
    if(isPrime(n,mark) == false){ 
        cout << "This is not prime number.";
    } else {
        cout << "This is prime number";
    }
    return 0;
}