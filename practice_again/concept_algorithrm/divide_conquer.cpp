#include <bits/stdc++.h>

using namespace std;

int countNumber(int n, int a[], int left, int right, int x){
    if(left == right){
        if(a[left] == x) return 1;
        else return 0;
    } else {
        int mid = (left + right) / 2;
        return countNumber(n, a, left, mid, x) + countNumber(n, a, mid + 1, right, x);
    }
}
int main(){ 
    int n,x;
    cin >> n;
    int a[100];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin >> x;
    cout << countNumber(n,a,0,n-1,x);
    return 0;
}