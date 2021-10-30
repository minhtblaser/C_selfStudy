#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ll;
int n, x[1001], y[1001], f[1001][1001];

int main(){
    cin >> n;
    for(int i = 1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    f[1][1] = 1;
    for(int i = 2; i<=n; i++) {
        f[i][0] = f[i-1]+ x[i];
        f[i][i] = f[i-1][i-1] + y[i];
        for(int j = 1; j<=i-1; j++){
            f[i][j] = min(f[i-1][j-1]+y[i],f[i-1][j+1]+x[i]);
        }
    }
    cout << f[n][0];
    return 0;
}