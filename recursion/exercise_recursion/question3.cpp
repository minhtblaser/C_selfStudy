#include <iostream>

using namespace std;

int lograrit(int n){
    if (n < 0) return 0;
    if(n > 2) return 1 + lograrit(n/2);
    else return 1;
}

int main(){
    int n;
    cout<<"enter n: ";
    cin >> n;
    int result = lograrit(n);
    cout << "The result: " << result << endl;
    return 0;
}