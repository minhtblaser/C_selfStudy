#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = n-1; i>0; i--){
        bool swappedd = true;
        for(int j = 0; j<i; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swappedd = false;
            }
        }
        if (swappedd){
            break;
        }
    }
    for(int i = 0; i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}