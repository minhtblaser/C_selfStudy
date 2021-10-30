#include <iostream>
#include <algorithm>

using namespace std;

int main (){
    int num2 = 0, num5 = 0;
    //declare a number ten of thousand
    int x;
    cin >> x;
    while (x % 2 == 0){
        num2++;
        x /= 2;
    }
    while(x % 5 == 0){
        num5++;
        x /= 5;
    }
    cout << min(num2, num5) << endl;
    return 0;
}