#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,k;
    int a[100];
    bool b[100];
    cin >> n;
    queue<int>q;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<100; i++){
        b[i] = false;
    }
    cin >> k;
    for(int i = 0; i<n; i++){
    if(!b[a[i]]){
        if(q.size() < k){
            // tránh lặp lại 2 số trên màn hình 
            b[a[i]] = true;
            q.push(a[i]);
        } else {
            //đặt lại giá trị cho lần sau
            b[q.front()] = false;
            b[a[i]] = true;
            q.push(a[i]);
            q.pop();
            }
        }
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}   