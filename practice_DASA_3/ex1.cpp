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
 
        /* Di chuy???n c??c ph???n t??? c?? gi?? tr??? l???n h??n gi?? tr??? 
       key v??? sau m???t v??? tr?? so v???i v??? tr?? ban ?????u
       c???a n?? */
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
            left++; // T??m ph???n t??? >= arr[pivot]
        while (right >= left && arr[right] > pivot)
            right--; // T??m ph???n t??? <= arr[pivot]
        if (left >= right)
            break;                   // ???? duy???t xong th?? tho??t v??ng l???p
        swap(arr[left], arr[right]); // N???u ch??a xong, ?????i ch???.
        left++;                      // V?? left hi???n t???i ???? x??t, n??n c???n t??ng
        right--;                     // V?? right hi???n t???i ???? x??t, n??n c???n gi???m
    }
    swap(arr[left], arr[high]);
    return left; // Tr??? v??? ch??? s??? s??? d??ng ????? chia ?????i m???ng
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi l?? ch??? s??? n??i ph???n t??? n??y ???? ?????ng ????ng v??? tr??
         v?? l?? ph???n t??? chia m???ng l??m 2 m???ng con tr??i & ph???i */
        int pi = partition(arr, low, high);
 
        // G???i ????? quy s???p x???p 2 m???ng con tr??i v?? ph???i
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* T???o c??c m???ng t???m */
    int L[n1], R[n2];
 
    /* Copy d??? li???u sang c??c m???ng t???m */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* G???p hai m???ng t???m v???a r???i v??o m???ng arr*/
    i = 0; // Kh???i t???o ch??? s??? b???t ?????u c???a m???ng con ?????u ti??n
    j = 0; // Kh???i t???o ch??? s??? b???t ?????u c???a m???ng con th??? hai
    k = l; // IKh???i t???o ch??? s??? b???t ?????u c???a m???ng l??u k???t qu???
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
 
    /* Copy c??c ph???n t??? c??n l???i c???a m???ng L v??o arr n???u c?? */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy c??c ph???n t??? c??n l???i c???a m???ng R v??o arr n???u c?? */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l l?? ch??? s??? tr??i v?? r l?? ch??? s??? ph???i c???a m???ng c???n ???????c s???p x???p */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // T????ng t??? (l+r)/2, nh??ng c??ch n??y tr??nh tr??n s??? khi l v?? r l???n
        int m = l + (r - l) / 2;
 
        // G???i h??m ????? quy ti???p t???c chia ????i t???ng n???a m???ng
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
    // N???u kh??ng t??m th???y
    return -1;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << setw(5);
    }
}