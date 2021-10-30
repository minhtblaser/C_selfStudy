// #include <bits/stdc++.h>
// way 1
// using namespace std;

// int countNumbers(int n){
//     int count = 1;
//     while (n >=10){
//         count++;
//         n /= 10;
//     }
//     return count;
// }   
// int pagesNumbering(int n){
//     int v1 = 0, v2 = 0, k = 1;
//     int count = countNumbers(n);
//     if(n<=9 && n>0){
//         v1 = n; 
//         v2 = 0;
//     } else {
//         for(int i=1 ; i<=count-1; i++){
//             v1 = (n - (pow(10,i)-1)) * count;
//             v2 = v2 + 9*i*k;
//             k = k*10;
//         }
//     }
//     return v1 + v2;
// }
// int main(){
//     int n;
//     cin >> n;
//     cout << pagesNumbering(n);
//     return 0;
// }
//way2

// C++ program to count total number
// of digits we have to write
// from 1 to n
#include <bits/stdc++.h>
using namespace std;
 
int totalDigits(int n)
{
   
    // number_of_digits store total
    // digits we have to write
    int number_of_digits = 0;
 
    // In the loop we are decreasing
    // 0, 9, 99 ... from n till
    // ( n - i + 1 ) is greater than 0
    // and sum them to number_of_digits
    // to get the required sum
    for(int i = 1; i <= n; i *= 10)
        number_of_digits += (n - i + 1);
 
    return number_of_digits;
}
 
// Driver code
int main()
{
    int n = 13;
   
    cout << totalDigits(n) << endl;
   
    return 0;
}