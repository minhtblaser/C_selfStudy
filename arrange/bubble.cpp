#include <iostream>

using namespace std;

void enter(int a[], int &n);
void print(int a[], int n);
void sortBubble(int a[], int n);
int main(){
    int n;
    int a[100]; 
    cout << "Enter n: ";
    cin >> n;
    enter(a,n);
    cout << "Your numbers: ";
    print(a,n);
    cout << "\nSort bubble: ";
    sortBubble(a,n);
    print(a,n);
    return 0;
}
void enter(int a[],int &n){
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
}
void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
void sortBubble(int a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = n - 1; j > i; j--){
            if(a[j] < a[j-1]){ // check 
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}