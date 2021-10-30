#include <iostream>
#include <stdio.h>

using namespace std;

void enter(int a[], int &n);
void print(int a[], int n);
int findMin(int a[], int n);
int findMax(int a[], int n);
void printMaxMin(int a[], int n);
int main(){
    int n;
    int a[100]; 
    cout << "Enter n: ";
    cin >> n;
    enter(a,n);
    cout << "Your numbers: ";
    print(a,n);
    cout << "\nNew numbers after deleting: ";
    printMaxMin(a,n);
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
void printMaxMin(int a[], int n){
	int min = findMin(a,n);
	int max = findMax(a,n);
    for(int i = 0; i < n; i++){
        if(a[i] == min || a[i] == max){
            a[i] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] != 0){
        	cout << a[i] << " ";
		}
    }
}
