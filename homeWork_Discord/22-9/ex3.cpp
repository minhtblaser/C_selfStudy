#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,k,temp;
    queue<int>q;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> temp;
        q.push(temp);
    }
    cin >> k;
    for(int i = 0; i<k; i++){
        int x = q.front();
        q.push(x);
        q.pop();
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}