#include <iostream>
#include <stdio.h>

using namespace std;

void enter(int a[], int &n);
void print(int a[], int n);
int findMin(int a[], int n);
int findMax(int a[], int n);
int findMin2(int a[], int n);
int findMax2(int a[], int n);
int main(){
    int n;
    int a[100]; 
    cout << "Enter n: ";
    cin >> n;
    enter(a,n);
    cout << "Your numbers: ";
    print(a,n);
    int result_max2 = findMax2(a,n);
    cout << "\nMAX2: " << result_max2 << endl;
    int result_min2 = findMin2(a,n);
    cout << "MIN2: " << result_min2 << endl;
    return 0;
}
void enter(int a[],int &n){
    for(int i = 0; i < n; i++){
        cout << "a[" << i+1 << "]: ";
        cin >> a[i];
    }
}
void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
int findMax(int a[], int n){
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(max < a[i])
        max = a[i];
    }
    return max;
}
int findMin(int a[], int n){
    int min = a[0];
    for(int i = 1; i < n; i++){
        if(min > a[i])
        min = a[i];
    }
    return min;
}
int findMin2(int a[], int n){
    int min = findMin(a, n);
    int min2 = findMax(a, n);
    for(int i = 0; i < n; i++){
        if(a[i] < min2 && a[i] != min){
            min2 = a[i];
        } 
    }
    return min2;
}
int findMax2(int a[], int n){
    int max = findMax(a, n);
    int max2 = a[0];
    for(int i = 1; i < n; i++){
        if(max2 < a[i] && a[i] != max){
            max2 = a[i];
        } 
    }
    return max2;
}


