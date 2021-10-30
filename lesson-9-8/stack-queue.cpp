#include <iostream>
#include <stack> 
#include <queue>

using namespace std;

int main(){
    int n, m, value;
    cin >> n >> m;
    stack<int>vt; // stack <type data> name;
    queue<int>qe; // queue <type data> name;
    //vector
    for(int i = 0; i < n; i++){
        cin >> value;
        vt.push(value);
    }
    cout << "Stack: ";
    // {!false} == true 
    // kt stack có trống không
    while(!vt.empty()){
        // stack:  
        // 5 4 3 2 1
        cout << vt.top() << " "; // lấy phần tử đầu tiên 
        vt.pop(); //xóa phần tử đầu tiên
    }
    //vector: push_back >< pop_back;
    //queue
    fflush(stdin);
    for(int i = 0; i < m; i++){
        cin >> value;
        qe.push(value);
    }
    cout << "Queue: ";
    while(!qe.empty()){
        cout << qe.front() << " ";
        qe.pop();
    }
    return 0;
}