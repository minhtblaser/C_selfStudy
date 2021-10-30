#include <iostream>

using namespace std;

class Math {
    public:
    static int maxOfArray (int arr[], int n) {
        int maxValue = arr[0];
        for(int i = 1; i < n; i++){
            if (maxValue < arr[i]){
                maxValue = arr[i];
            }
        }
        return maxValue;
    }
    static double maxOfArray (double arr[], int n){
        double maxValue = arr[0];
        for(int i = 1; i < n; i++){
            if (maxValue < arr[i]){
                maxValue = arr[i];
            }
        }
        return maxValue;
    }
};

int main(){
    int arr1[] = {3,5,6,9,12,14,2,99,12,3,23};
    double arr2[] = {3.3,5.4,9.1,7.8,9,15};
    cout << Math :: maxOfArray(arr1, sizeof(arr1, sizeof(arr1)/sizeof(int))) << endl;
    cout << Math :: maxOfArray(arr2, sizeof(arr2, sizeof(arr2)/sizeof(double))) << endl;
    return 0;
}