#include <iostream>
#include <math.h>

using namespace std;

void sortQuick(int b[], int left, int right){
    int p = b[(left+right)/2];
    int i = left, j = right;
    while (i < j){
        while (b[i] < p){
            i++;
        }
        while (b[j] > p){
            j--;
        }
        if( i <= j) {
            int temp = b[i];
            b[i] = b[j];
            b[j] = temp;
            i++;
            j--;
        }
    }
    if (i<right){
        sortQuick(b,i,right);
    }
    if (left < j){
        sortQuick(b,left,j);
    }
}
bool check (int x){
    if(sqrt(x) == (int) sqrt(x)){
        return true;
    }
    return false;
}
void printArray(int b[], int k){
    if(k == 0){
        cout << "NULL";
    } else {
    cout << b[0] << " ";
    for(int i = 1; i<k; i++){
        if (b[i] != b[i-1]){
            cout << b[i] << " ";
            }
        }
    }
}
int main(){
    int n;
    int a[100];
    int b[100];
    cin >> n;
    for(int i = 0;i<n; i++){
        cin >> a[i];
    }
    int k = 0;
    for(int i = 0; i<n ;i++){a
        if(check(a[i]) == true){
            b[k] = a[i];
            k++;
        }
    }
    sortQuick(b,0,k-1);
    printArray(b,k);
    return 0;
}