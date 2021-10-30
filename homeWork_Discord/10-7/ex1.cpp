// #include <bits/stdc++.h>
// WAY 1
// using namespace std;

// int main(){
//     int a[100], b[100], n;
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int max = a[0];
//     for(int i = 0; i < n; i++){
//         if(max < a[i]){
//             max = a[i];
//         }
//     }
//     for(int i = 0; i <=max; i++){ // 0 1 2 3 4 5 6 
//         b[i] = 0; // b[0] = 0, b[1] = 0,....b[6] = 0
//     }
//     for(int i = 0; i < n; i++){
//         b[a[i]] += 1; // b[a[0]] = b[4] = 1; b[a[1]] = b[2] = 1; b[a[2]] = b[2] = 2,.....
//     }   
//     for(int i = 0; i <=max; i++){
//         if(b[i] > 0){
//             cout << i << " - " << b[i] <<";"; //b[0] = 0, b[1] = 0, b[2] = 2  
//             // 2 - 2; 
//         }
//     }
//     return 0;
// }
// WAY 2: 
#include<iostream>
using namespace std;
void sapxep (int n, int a[]){
    int temp;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n ; j++){
            if( a[i] > a[j]){
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}
//6 
// 2 2 4 5 5 6
void Dem(int n, int a[]){
    int Dem;
    for (int i = 0; i < n; i += Dem){ 
        Dem = 0;
        for (int j = 0; j < n; j++){
            if (a[i] == a[j])
                Dem ++; //Dem = 1; 
        }
        cout << a[i] << " - " << Dem <<";";
    }
}
int main (){
    int n;
    int a[100];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sapxep (n,a);
    Dem(n,a);
    cout << endl;
    return 0;
}