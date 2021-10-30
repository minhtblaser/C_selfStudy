#include <iostream> 

using namespace std;

int main(){
    int n;
    cin >> n;
    int c = 1;
    for (int i = 1; i<=n; i++) {
        c *= i;
        while(c % 10 == 0 && c > 99){
          c /=10;
        }
        c %= 100;
    }
    cout << c % 10;
    return 0;
}