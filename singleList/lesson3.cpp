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
node *addHead (node *l, int x){
    node *temp = new node; // create new node
    if(l == NULL){
        // if the list is empty, add value equal temp
        l = temp; 
    } else {
    temp->data = x;
    temp->next = l;
    l = temp;
    }
    return l;
}   
node *addTail(node *l, int x){
    node *temp = new node; // create node
    node *p = l;
    if(l == NULL){
        l = temp;
    } else {
        // find the last node
        while(p != NULL){
            p = p->next;
        } 
        temp->data = x;
        temp->next = NULL;
        p->next = temp; // add vaule of temp to p->next (the last node)
    }
    return l;
}
node *addAt(node *l, int k, int x){
    node *temp = new node; // create node
    node *p = l;
    for(int i = 0; i < k-1; i++){
        p = p->next;
    }
    temp->data = x;
    temp->next = p->next;
    p->next = temp; // add value of temp to p->next
    return l;
}
int main(){
    int n,x,k;
    cin >> n >> x;
    node *l = createNode(x);
    node *p = l;
    for(int i = 1; i<n; i++){
        cin >> x;
        p = addElement(p,x);
    }
    printList(l);
    cin >> k >> x;
    if(k == 0){
        l = addHead(l,x);
    } else if (k == n){
    l = addTail(l,x);
    } else {
        l = addAt(l,k,x);
    }
    printList(l);
    return 0;
}