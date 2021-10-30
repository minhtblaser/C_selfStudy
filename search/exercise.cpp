#include <iostream>

using namespace std;

int findMin(int n, int a[]);
int findMax(int n, int a[]);
void printList(int n, int a[]);
int main (){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    int result_min = findMin(n,a);
    int result_max = findMax(n,a);  
    //hoán đổi 2 cái giá trị 
    int temp = a[result_min];
    a[result_min] = a[result_max];
    a[result_max] = temp;
    printList(n,a);
    return 0;
}
int findMin(int n, int a[]){
    int min = 0;
    for(int i = 1; i<n; i++){
        if (a[min] > a[i]){
            min = i;
        }
    }
    return min;
}
int findMax(int n, int a[]){
    int max = 0;
    for(int i = 1; i<n; i++){
        if (a[max] <= a[i]){
            max = i;
        }
    }
    return max;
}
void printList(int n, int a[]){
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }
}