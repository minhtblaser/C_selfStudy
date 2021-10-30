#include <bits/stdc++.h>

using namespace std;

int main(){
    long long res = 0;
    priority_queue<int, vector<int>> q;
    string s;
    int k, count[100] = {0};
    getline(std::cin,s);
    cin >> k;
    for(int i=0;i<s.length();i++){
        count[s[i]]++;
    }
    for(int i=0;i<s.size();i++){
        if(count[s[i]]>0){
            q.push(count[s[i]]);
            count[s[i]] = 0;
        }
    }
    while(k > 0 && q.size() > 0){
        k--;
        int temp = q.top(); q.pop();
        temp--;
        q.push(temp);
    }
    while(!q.empty()){
        res += q.top() * q.top();
        q.pop();
    }
    cout << res << endl;
}