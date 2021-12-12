// Giả sử chúng ta cần sắp xếp dãy số [5 1 4 2 8] này tăng dần.
// Lần lặp đầu tiên:
// ( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Ở đây, thuật toán sẽ so sánh hai phần tử đầu tiên, và đổi chỗ cho nhau do 5 > 1.
// ( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Đổi chỗ do 5 > 4
// ( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Đổi chỗ do 5 > 2
// ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Ở đây, hai phần tử đang xét đã đúng thứ tự (8 > 5), vậy ta không cần đổi chỗ.

// Lần lặp thứ 2:
// ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
// ( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Đổi chỗ do 4 > 2
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
// ( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
// Bây giờ, dãy số đã được sắp xếp, Nhưng thuật toán của chúng ta không nhận ra điều đó ngay được. 
//Thuật toán sẽ cần thêm một lần lặp nữa để kết luận dãy đã sắp xếp khi và khi khi nó đi từ đầu tới cuối 
//mà không có bất kỳ lần đổi chỗ nào được thực hiện.

// Lần lặp thứ 3:
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )

#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);

int main(){
    int arr[5] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    cout << "Bubble sort: ";
    printArray(arr,n);
}
void bubbleSort(int arr[], int n){
    bool haveSwap = false; //đat co
    for(int i=0; i<n-1; ++i){
        haveSwap = false;
        for(int j=0; j<n-1-i; ++j){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                haveSwap = true;
            }
        }
            if(!haveSwap){ //haveswap == true //haveswap == false;
                break;
        }
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