#include <iostream>

using namespace std;

void sortQuick(int a[], int left, int right);
int solve (int a[], int n);
int main (){
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(a,n);
    return 0;
}
void sortQuick(int a[], int left, int right){
    int p = a[(left+right)/2];
    int i = left, j = right;
    while (i < j){
        while (a[i] < p){
            i++;
        }
        while (a[j] > p){
            j--;
        }
        if( i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i<right){
        sortQuick(a,i,right);
    }
    if (left < j){
        sortQuick(a,left,j);
    }
}
int solve (int a[], int n){
    sortQuick(a,0,n-1);
    if (a[0] > 0) return 0;
    for(int i = 1; i < n; i++){
        if((a[i] - a[i-1]) > 1){
             return a[i-1] + 1;
            }
        }
    return a[n-1] + 1;
}