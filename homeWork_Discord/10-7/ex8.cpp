#include <bits/stdc++.h>

using namespace std;
// Một số X như thế nào thì chia hết cho 10 ? Đó là khi X phân tích ra thừa số nguyên tố, 
// sẽ luôn chứa 2 thừa số là 2 và 5 (Vì 10 = 2 * 5, mà 2 và 5 nguyên tố cùng nhau).
// Một số X có k chữ số 0 tận cùng, tức là X chia hết cho 10k, và không chia hết cho 10k+1.
// Khi đó, bậc lũy thừa của 2 và 5, giá trị nhỏ hơn sẽ phải đúng bằng k (10k = 2k * 5k)
// Vậy ta cần xác định số chữ số 0 của số X, thì chỉ cần xác định bậc lũy thừa của 2 và 5 mà X có,
// rồi lấy ra số nhỏ hơn.
// Ví dụ : X = 27 * 3 * 55 ⇒ X có 5 chữ số 0 tận cùng. Điều đó đúng, vì giá trị X = 1200000
int factorial(int n){
    if(n>0) return  n*factorial(n-1);
    else{
    return 1;
    }
}
int main(){
    int num2 = 0, num5 = 0;
    int n;
    cin >> n;
    int result_factor = factorial(n);
    while(result_factor % 2 == 0){
        result_factor /= 2;
        num2++;
    }
    while(result_factor % 5 == 0){
        result_factor /= 5;
        num5++;
    }
    int k = min(num2, num5);
    int d = pow(10,k);
    int result = 0;
    result_factor = factorial(n);
    while(result_factor > 10){
        result = result_factor % d;
        result_factor /= d;
    }
    cout << result << endl;
    return 0;
}