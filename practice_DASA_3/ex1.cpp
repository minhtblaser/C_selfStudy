#include <bits/stdc++.h>
 
using namespace std;
 
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
int linearSearch(int arr[], int n, int x);
int binarySearch(int arr[], int l, int r, int x);
void printArray(int arr[], int n);
int main()
{
    int arr[] = {23, 15, 17, 30, 4, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Bubble sort: ";
    bubbleSort(arr, n);
    printArray(arr, n);
    cout << "\nSelection sort: ";
    selectionSort(arr, n);
    printArray(arr, n);
    cout << "\nInsertion sort: ";
    insertionSort(arr, n);
    printArray(arr, n);
    cout << "\nQuick sort: ";
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    cout << "\nMerge sort: ";
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    int result  = linearSearch(arr,n,23);
    if(result == -1){
        cout << "\nNot found number in array." << endl;
    } else {
        cout << "\nFind number at position: " << result << endl;
    }
    int result_binary = binarySearch(arr,0,n-1,30);
    if(result_binary == -1){
        cout << "\nNot found number in array." << endl;
    } else {
        cout << "\nFind number at position: " << result_binary << endl;
    }
}
void bubbleSort(int arr[], int n)
{
    bool haveSwap = false;
    for (int i = 0; i < n - 1; ++i)
    {
        haveSwap = false;
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                haveSwap = true;
            }
        }
        if (!haveSwap)
            break;
    }
}
void selectionSort(int arr[], int n)
{
    int min_index;
    for (int i = 0; i < n - 1; ++i)
    {
        min_index = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = i;
                swap(arr[min_index], arr[j]);
            }
        }
    }
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Di chuyển các phần tử có giá trị lớn hơn giá trị 
       key về sau một vị trí so với vị trí ban đầu
       của nó */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && arr[left] < pivot)
            left++; // Tìm phần tử >= arr[pivot]
        while (right >= left && arr[right] > pivot)
            right--; // Tìm phần tử <= arr[pivot]
        if (left >= right)
            break;                   // Đã duyệt xong thì thoát vòng lặp
        swap(arr[left], arr[right]); // Nếu chưa xong, đổi chỗ.
        left++;                      // Vì left hiện tại đã xét, nên cần tăng
        right--;                     // Vì right hiện tại đã xét, nên cần giảm
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
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* Tạo các mảng tạm */
    int L[n1], R[n2];
 
    /* Copy dữ liệu sang các mảng tạm */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Gộp hai mảng tạm vừa rồi vào mảng arr*/
    i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy các phần tử còn lại của mảng L vào arr nếu có */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy các phần tử còn lại của mảng R vào arr nếu có */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
        int m = l + (r - l) / 2;
 
        // Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
int linearSearch(int arr[], int n, int x){
    for(int i = 0; i < n; ++i){
        if(arr[i] == x) return i;
    }
    return -1;
}
int binarySearch(int arr[], int l, int r, int x){
    int mid = (l+r)/2;
    while(l <= r){
        if(x > arr[mid]){
            l = mid+1;
        } else if (x < arr[mid]){
            r = mid-1;
        } else {
            return mid;
        }
        mid = (l+r)/2;
    }
    // Nếu không tìm thấy
    return -1;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << setw(5);
    }
}