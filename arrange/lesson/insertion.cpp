//Thuật toán sắp xếp chèn thực hiện sắp xếp dãy số theo cách duyệt từng phần tử và chèn từng phần tử đó vào đúng
//vị trí trong mảng con(dãy số từ đầu đến phần tử phía trước nó) đã sắp xếp sao cho dãy số trong mảng sắp đã xếp 
//đó vẫn đảm bảo tính chất của một dãy số tăng dần.
//Cac buoc: 
//1) Khởi tạo mảng với dãy con đã sắp xếp có k = 1 phần tử(phần tử đầu tiên, phần tử có chỉ số 0)
//2) Duyệt từng phần tử từ phần tử thứ 2, tại mỗi lần duyệt phần tử ở chỉ số i thì đặt phần tử đó 
//vào một vị trí nào đó trong đoạn từ [0…i] sao cho dãy số từ [0…i] vẫn đảm bảo tính chất dãy số tăng dần. 
//Sau mỗi lần duyệt, số phần tử đã được sắp xếp k trong mảng tăng thêm 1 phần tử.
//3) Lặp cho tới khi duyệt hết tất cả các phần tử của mảng.

#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main(){
    int arr[5] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    cout << "Insertion sort: ";
    printArray(arr,n);
}
void insertionSort(int arr[], int n){
    int i, j, key;
    for(i = 1; i<n; ++i){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void printArray(int arr[], int n){
    for(int i=0; i<n; ++i){
        cout << arr[i] << setw(5);
    }
    cout << endl;
}
// Độ  phức tạp thuật toán

// 1) Trường hợp tốt: O(n)
// 2) Trung bình: O(n^2)
// 3) Trường hợp xấu: O(n^2)