#include <bits/stdc++.h>

using namespace std;

vector<int>alternatingSUM(vector<int>a){
    int x = 0, y = 0;
    for(int i = 0; i < a.size(); i+=2) x += a[i];
    for(int i = 1; i < a.size(); i+=2) y += a[i];
    return {x,y};
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> result = alternatingSUM(a);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}