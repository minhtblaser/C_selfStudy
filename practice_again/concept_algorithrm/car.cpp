#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct data {
    int val, time, id;
};
const int MAX = 1000;
data a[MAX];
int ans,sum;
int n;
bool compare(data u, data v){
    return u.val*v.time > u.time*v.val; 
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].val;
        sum += a[i].val;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i].time;
        a[i].id = i;
    }
    sort(a+1, a+n+1, compare);  
    for(int i = 1; i <= n; i++){
        ans += sum*a[i].time;
        sum -= a[i].val;
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++){
        cout << a[i].id << " ";
    }
    return 0;
}