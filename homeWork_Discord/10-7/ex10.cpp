#include <bits/stdc++.h>

using namespace std;

int pagesNumbering(int n)
{
    int number_of_digits = 0;
    for(int i = 1; i <= n; i *= 10)
        number_of_digits += (n - i + 1);
 
    return number_of_digits;
}
int main(){
    int n ;
    cin >> n;
    cout << pagesNumbering(n);
    return 0;
}