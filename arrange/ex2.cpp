#include <iostream>

using namespace std;

void sortQuick(int a[], int left, int right);

int main (){
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sortQuick(a,0,n-1);
    int count = 1;
    for(int i = 0; i < n; i++){
        if (a[i+1] - a[i] == 0){
            count ++;
        } else {
            cout << a[i] << " " << count << "; ";
            count = 1;
        }
    }

    return 0;
}
void sortQuick(int a[], int left, int right){
    int p = a[(left+right)/2];
    int i = left, j = right;
    while (i < j){
        while (a[i] < p){
            i++;
        }
        while (a[j] > p){
            j--;
        }
        if( i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i<right){
        sortQuick(a,i,right);
    }
    if (left < j){
        sortQuick(a,left,j);
    }
}