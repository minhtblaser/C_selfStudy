#include <bits/stdc++.h>

using namespace std;

int countGuessGame(int n){
    if (n < 1) return 0; 
    return countGuessGame(n/2) + 1;
}
int main(){
    int n;
    cin >> n;
    cout << countGuessGame(n);
    return 0;
}