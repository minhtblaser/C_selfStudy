#include <iostream>
// 
using namespace std;

void printArray(int arr[], int n);
void print_permutation(int arr[], int n, int i);

int main(){
    int  M[3];
    M[0] = 10;
    M[1] = 2;
    M[2] = 5;
    print_permutation(M,3,0);
    return 0;
}
void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void print_permutation(int arr[], int n, int i){
    printArray(arr, n);
    for(int j = i + 1; j<n; j++){
        if(arr[i] > arr[j]){
            int swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
        }
        print_permutation(arr, n, i+1);
    }
}
