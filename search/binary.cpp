#include <iostream>

using namespace std;

void enter(int n, int *arr){
    for(int i=0; i<n; i++){
        cout << "arr[" << i << "]: ";
        cin >> arr[i]; 
    }

}
void printArray(int n, int *arr){
    cout << "Your data: ";
    for(int i=0; i<n; i++){
    	
        cout << arr[i] << " ";
    }
}
int binarySearch (int n, int *arr, int x){
    int left = 0, right = n-1;
    int mid;
    do{
        int mid = (left + right)/2; // mid index
        if(arr[mid] == x){
            return mid; // find x at the position of mid
        } else if (x<arr[mid]){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    } while( left <= right);
    return -1;
}
int main(){
    int n,x;
    cout << "Enter n: ";
    cin >> n;
    int *arr;
    arr = new int[n];
    if (arr == NULL){
        exit(1);
    }
    enter(n, arr);
    printArray(n, arr);
    cout << "\nEnter the number which you want to see position: ";
    cin >> x;
    int result = binarySearch(n, arr, x);
    if (result == -1){
        cout << "The number doesn't exist";
    } else {
    cout << "\nThe number " << x << " at " << result << endl; 
    }
    delete[] arr;
    return 0;
}
