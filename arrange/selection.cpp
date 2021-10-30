#include <iostream>

using namespace std;

void enter(int a[], int &n);
void print(int a[], int n);
void selectionSort(int a[], int n);
int main(){
    int n;
    int a[100]; 
    cout << "Enter n: ";
    cin >> n;
    enter(a,n);
    cout << "Your numbers: ";
    print(a,n);
    cout << "\nSelection bubble: ";
    selectionSort(a,n);
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
void selectionSort(int a[], int n){
    int min;
    for(int i = 0; i < n-1; i++){
        min = i;  // set the first value is MIN
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min]){ // find the min number in array.
                min = j;
            }
        }
        if(min != i){
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;  
        }
    }
}




