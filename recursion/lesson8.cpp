#include <iostream>

using namespace std;

int choose(int n, int k);

int main(){
    int n,k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;
    int result = choose(n,k);
    cout <<"Result: " << result << endl;
    return 0;
}
int choose(int n, int k){
    if(k == 0 || n == k) return 1;
    return choose(n-1,k) + choose(n-1,k-1);

}