#include <iostream>

using namespace std; 

void quickSort(int a[], int left, int right){
    int p = a[(left+right)/2];
    int i = left, j = right;
    while (i<j){
        while (a[i] < p){
            i++;
        }
        while(a[j] > p){
            j--;
        }
        if (i<=j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i<right){
        quickSort(a,i,right);
    }
    if (left < j){
        quickSort(a,left,j);
    }
}
int solve (int a[], int n){
    quickSort(a,0,n-1);
    if(a[0] > 0) return 0;
    for(int i = 1; i<n; i++){
        if ((a[i] - a[i-1]) > 1){
            return a[i-1] + 1; 
        }
    }
    return a[n-1] + 1;
}
int main(){
    int n;
    int a[100];
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    cout << solve(a,n);
    return 0;
}