#include <iostream>

using namespace std; 

int main(){
    int kq[100],a[100],b[100],t[100], n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i =0; i<n; i++){
        b[i] = 1;
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(a[i]>=a[j] && b[j]+1 > b[i]){
                b[i] = b[j] + 1;
                t[i] = j;
            }
        }
    }
    int csMax = 0;
    for(int i = 0; i<n; i++){
        if(b[csMax] < b[i]){
            csMax = i;
        }
    }
    int k = b[csMax];
    for(int i = k-1; i>=0; i--){
        kq[i] = a[csMax];
        csMax = t[csMax];
    }
    for(int i = 0; i<k; i++){
        cout << kq[i] << " ";
    }
    return 0;
}