#include <iostream>
#include <stdio.h>

using namespace std;

void enter(int a[], int &n);
void print(int a[], int n);
float average (int a[], int n,int x);
int main(){
    int n,x;
    int a[100]; 
    cout << "Enter n: ";
    cin >> n;
    enter(a,n);
    cout << "Your numbers: ";
    print(a,n);
    cout << "\nEnter x: ";
    cin >> x;
    float result = average(a,n,x);
    cout << "Your result: " << result;
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
float average (int a[], int n, int x){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= x)
            sum += a[i];
    }
    float average = (float) sum / n;
    return average;
}
