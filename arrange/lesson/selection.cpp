// Ideal:
// arr[] = 62 24 15 22 1
 
// Tìm phần tử nhỏ nhất trong trong arr[0...4]
// và đổi chỗ nó với phần tử đầu tiên
// [1] 24 15 22 62
 
// Tìm phần tử nhỏ nhất trong trong arr[1...4]
// và đổi chỗ nó với phần tử đầu tiên của arr[1...4]
// 1 [15] 24 22 62
 
// Tìm phần tử nhỏ nhất trong trong arr[2...4]
// và đổi chỗ nó với phần tử đầu tiên của arr[2...4]
// 1 15 [22] 24 62
 
// Tìm phần tử nhỏ nhất trong trong arr[3...4]
// và đổi chỗ nó với phần tử đầu tiên của arr[3...4]
// 11 12 22 [24] 62
#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int n);
void printArray(int arr[], int n);

int main(){
    int arr[5] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]); // 20/4 = 5;
    selectionSort(arr,n);
    cout << "Selection sort: ";
    printArray(arr,n);
}
void selectionSort(int arr[], int n){
    int min_index;// min_index;
    for(int i=0; i<n; ++i){ 
        min_index = i; // set place
        for(int j=i+1; j<n; ++j){
            if(arr[j] < arr[min_index]){
                swap(arr[j], arr[min_index]);
            }
        }
    }
}
void printArray(int arr[], int n){
    for(int i=0; i<n; ++i){
        cout << arr[i] << setw(5);
    }
    cout << endl;
}
//Độ  phức tạp thuật toán:
//Trường hợp tốt: O(n^2)
//Trung bình: O(n^2)
//Trường hợp xấu: O(n^2)