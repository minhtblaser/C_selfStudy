#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m, count = 0;
    cin >> n >> m;
    bool mark[100];
    for(int i=1;i<100;i++)
    {
        mark[i] = false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mark[i*j] = true;
        }
    }
    for(int i = 1; i<=m*n; i++){
        if(mark[i]){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}