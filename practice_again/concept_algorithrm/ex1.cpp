#include <bits/stdc++.h>
// dang toan tham lam
using namespace std;

int countDays(vector<int>a){
    int k = 1, max = 0;
    for(int i = 0; i<a.size(); i++){
        if(a[i]+k > max){
            max = a[i]+k;
        }
        k++;
    }
    return max;
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    cout << countDays(a) << endl;
    return 0;
}