#include<iostream>
using namespace std;
int main () {
    int a;
    int arr[100];
    cin >> a;
    for (int i = 0; i < a ; i++){
        cin >> arr [i];
    }
    int squace = 0;
    for (int i = 0; i < a; i++){
        squace = arr[i] * arr[i];

    cout << squace << " ";
    }

return 0;
}