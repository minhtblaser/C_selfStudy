#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std; 

int findCount(int n){
    int count = 1;
    while(n>=10){
        n/=10;
        count++;
    }
    return count;
}
int pagesNumbering(int n)
{
    int k = 1;
    int v1 = 0;
    int v2 = 0;
    int count = findCount(n);
    if(n<10 && n>0){
        v1 = n;
        v2 = 0;
    } else {
        for(int i = 1 ;i<=count-1; i++){
            v1 = (n - (int)pow(10,i)+1) * count;
            v2 = v2 + (9*i)*k;
            k *=10;
        }
    }
    return (v1+v2);
}
int main(){
    int n; 
    cin >> n;
    cout << pagesNumbering(n);
    return 0;
}