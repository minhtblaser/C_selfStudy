#include <bits/stdc++.h>
// way1
using namespace std;
// 1 2 3 4 5 //
// n = 5 => 0(n)
int main(){
    int n, a[100];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bool kt1 = true;
    bool kt2 = true;
    for(int i = 1; i<n; i++){
        if(a[i] <= a[i-1]) kt1 = false;  // break;
        if(a[i] >= a[i-1]) kt2 = false;   
    }         
    if(kt1 || kt2){
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;   
}
// way2
// #include<iostream>

// using namespace std;

// // 1 2 3 4 5
// // 0 1 2 3 4 
// // dem = 4

// void Kiemtra (int n, int a[]){
//     int counttang = 0;
//     int countgiam = 0;
//     for (int i = 1; i < n  ; i++){
//         if(a[i] > a[i-1] ){
//             counttang ++;
//         } else if( a[i] < a[i-1]){
//             countgiam ++;
//         }
//     }
//     // CONDITION: 
//     if (counttang == n - 1 || countgiam == n -1 ){
//             cout << "YES";
//         }else {
//             cout <<"NO";
//     }
// }
// int main (){
//     int n; 
//     int a[100];
//     cin >> n;
//     for (int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     Kiemtra (n,a);
//     return 0;
// }
