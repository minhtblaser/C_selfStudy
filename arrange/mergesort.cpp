#include <iostream>

using namespace std;

void enter(int a[], int &n);
void print(int a[], int n);
void mergeSort(int a[], int left, int right);
void merge(int a[], int left, int mid, int right);
int main(){
    int n;
    int a[100]; 
    cout << "Enter n: ";
    cin >> n;
    enter(a,n);
    cout << "Your numbers: ";
    print(a,n);
    cout << "\nSort bubble: ";
    mergeSort(a,0,n-1);
    print(a,n);
    return 0;
}
void enter(int a[],int &n){
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
}
void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
void mergeSort(int a[], int left, int right){
    if(left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);
    merge(a,left,mid,right);
}
void merge(int a[], int left, int mid, int right){
    int nTemp = right - left + 1;
    int temp[nTemp];
    int pos = 0;
    int i = left;
    int j = mid+1;
    while(!(i>mid&&j>right)){
        if((i<=mid && j<=right && a[i]<a[j]) || j>right)
            temp[pos++] = a[i++];
        else
            temp[pos++] = a[j++];
    }
    for(int i = 0; i<nTemp; i++){
        a[left+i] = temp[i];
    }
}
 