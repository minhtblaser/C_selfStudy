// Thuật toán sắp xếp quick sort là một thuật toán chia để trị( Divide and Conquer algorithm).
// Nó chọn một phần tử trong mảng làm điểm đánh dấu(pivot). 
// Thuật toán sẽ thực hiện chia mảng thành các mảng con dựa vào pivot đã chọn. 
// Việc lựa chọn pivot ảnh hưởng rất nhiều tới tốc độ sắp xếp. 
// Nhưng máy tính lại không thể biết khi nào thì nên chọn theo cách nào. Dưới đây là một số cách để chọn pivot thường được sử dụng:

// 1) Luôn chọn phần tử đầu tiên của mảng.
// 2) Luôn chọn phần tử cuối cùng của mảng.
// 3) Chọn một phần tử random.
// 4) Chọn một phần tử có giá trị nằm giữa mảng(median element).

// Quy trình của thuật toán sắp xếp quick sort

// Bước 1: Lấy phần tử chốt là phần tử ở cuối danh sách.
// Bước 2: Chia mảng theo phần tử chốt.
// Bước 3: Sử dụng sắp xếp nhanh một cách đệ qui với mảng con bên trái.
// Bước 4: Sử dụng sắp xếp nhanh một cách đệ qui với mảng con bên phải.

#include <bits/stdc++.h>

using namespace std;

int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int n);

int main(){
    int arr[5] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout << "Quick sort: ";
    printArray(arr,n);
}
// ham phan manh
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++; // Tìm phần tử >= arr[pivot]
        while(right >= left && arr[right] > pivot) right--; // Tìm phần tử <= arr[pivot]
        if (left >= right) break; // Đã duyệt xong thì thoát vòng lặp
        swap(arr[left], arr[right]); // Nếu chưa xong, đổi chỗ.
        left++; // Vì left hiện tại đã xét, nên cần tăng
        right--; // Vì right hiện tại đã xét, nên cần giảm
    }
    swap(arr[left], arr[high]);
    return left; // Trả về chỉ số sẽ dùng để chia đổi mảng
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
void printArray(int arr[], int n){
    for(int i=0; i<n; ++i){
        cout << arr[i] << setw(5);
    }
    cout << endl;
}
// Độ  phức tạp thuật toán

//1)Trường hợp tốt: O(nlog(n))
//2)Trung bình: O(nlog(n))
//3)Trường hợp xấu: O(n^2). 
