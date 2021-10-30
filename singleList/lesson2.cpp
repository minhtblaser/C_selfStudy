#include <iostream>
// create node and add elements to node.
using namespace std;

struct node {
    int data;
    node *next; // cấu trúc tự trỏ
};
node *createNode(int x){
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}
node *addElement(node *p, int x){
    node *temp = createNode(x);
    p->next = temp;
    return temp;
}
void printList(node *l){
    node *p = l;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}
int main(){
    int n,x;
    cin >> n >> x;
    node *l = createNode(x);
    node *p = l;
    for(int i = 1; i<n; i++){
        cin >> x;
        p = addElement(p,x);
    }
    printList(l);
    return 0;
}