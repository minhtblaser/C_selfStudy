#include <bits/stdc++.h>

using namespace std;

struct Node{
    // giá trị của dữ liệu
    int data;
    // con trỏ trỏ của chính bản thân nó,
    // và nó trỏ tới một thằng Node kế tiếp cũng có kiểu
    Node *next;
};
// kiểu danh sách quản lý
struct singleList{
    // con trỏ head;
    Node *head;
};
Node *createNode(){
    
}