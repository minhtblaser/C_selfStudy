#include <iostream>

using namespace std;

void enter(int a[], int &n);
void print(int a[], int n);
void quickSort(int a[], int left, int right);
int main(){
    int n;
    int a[100]; 
    cout << "Enter n: ";
    cin >> n;
    enter(a,n);
    cout << "Your numbers: ";
    print(a,n);
    cout << "\nArrange numbers by quicksort: ";
    quickSort(a,0,n-1);
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
void quickSort(int a[], int left, int right){
    if (left >= right) return;
    int i = left, j = right;
    int pivot = a[(left+right)/2];
    do{
        //check problem location first
        while(a[i] < pivot) i++;
        //check problem location second
        while(a[j] > pivot) j--;
        //check property
        if(i <= j){
            // swap value
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i < j);
    quickSort(a,left,j);
    quickSort(a,i,right);
}