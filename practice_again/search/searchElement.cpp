#include <bits/stdc++.h>

using namespace std;

int countPlace(vector<int>a, int k){
    int i = 0, res = 0, pre = 0;
    while(i < a.size()){
        while(i < a.size() && a[i]-a[pre] <= k) i++;
        pre = i - 1;
        while(i < a.size() && a[i]-a[pre] <= k) i++;
        res++;
        pre = i;
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    cout << countPlace(a,k);
    return 0;
}