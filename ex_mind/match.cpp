#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k, count=0;
    cin >> m >> n >> k;
    while(n != 0 || m != 0){
        if(n >= m){
            n -= k;
            while(n != 0 || m != 0){
                n--;
                m-=2;
                count++;
            }
        }else if (n < m){
            m -= k;
            while(n != 0 || m != 0){
                n--;
                m-=2;
                count++;
            }
        } 
    }
    cout << "Number group: " << count << endl;
    return 0;
}