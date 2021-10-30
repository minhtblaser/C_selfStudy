// #include <iostream>
// #include <algorithm>

// using namespace std;

// void quickSort(int a[], int left, int right){
//     int p = a[(left+right)/2];
//     int i = left, j = right;
//     while (i < j){
//         while(a[i] < p) i++;
//         while(a[j] > p) j--;
//         if (i<=j){
//             int temp = a[i];
//             a[i] = a[j];
//             a[j] = temp;
//             i++;
//             j--;
//         }
//     }
//     if (i<right) quickSort(a,i,right);
//     if (left<j) quickSort(a,left,j);
// }
// int main(){
//     int a[100];
//     int n;
//     cin >> n;
//     for(int i = 0; i<n; i++){
//         cin >> a[i];
//     }
//     quickSort(a,0,n-1);
//     int k = 1;
//     int max = 0;
//     for(int i = n-1; i >= 0; i--){
//         if(a[i] + k > max)
//             max = a[i] + k;
//         k++;
//     }
//     cout << max;
//     return 0;
// }

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(ans <= s[i]) ans ++;
    cout << ans;
}