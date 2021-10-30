#include <iostream>

using namespace std;

void enter(int a[], int &n);
void print(int a[], int n);
float average (int a[], int n);
int findNumberNear(int a[], int n);
int main(){
    int n;
    int a[100]; 
    cout << "Enter n: ";
    cin >> n;
    enter(a,n);
    cout << "Your numbers: ";
    print(a,n);
    float result_average = average(a,n);
    cout << "\nThe average of numbers: " << result_average;
    int result_near = findNumberNear(a,n);
    cout << "\nThe near number: " << result_near;
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
float average (int a[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    float average = (float) sum / n;
    return average;
}
int findNumberNear(int a[], int n){
    int findNumber = 0;
    int average_result = int (average(a, n));
    for (int i = 0; i < n; i++){
        if(a[i] == average_result){
            findNumber = a[i];
        }
    }
    return findNumber;
}