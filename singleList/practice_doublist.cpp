#include <iostream>

using namespace std;
struct node {
    int data;
    node *next;
    node *pre;
};
struct doubList {
    node *head;
    node *tail;
};
node *createList(int x);
void printList(doubList *list);
node *addHead(doubList *list, int x);
node *addTail(doubList *list, int x);
int main(){
    int n;
    cin >> n;
    node *list = createList(1);
    for(int i = 2; i<=n; i++){
        list = addHead(list,i);
        list = addTail(list,i);
    }
    printList(list);
    return 0;
}
node *createList(int x){
    doubList *list = new doubList;
    list->head = new node;
    list->head->pre = NULL;
    list->head->next = NULL;
    list->head->data = x;
    list->tail = list->head;
    return list;
}
void printList(doubList *list){
    node *p = list->head;
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}
node *addHead(doubList *list, int x){
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    temp->pre = list->head;
    list->head->pre= temp;
    list->head = temp;
    return list;
}
node *addTail(doubList *list, int x){
    node *temp = new node;
    temp->data =x; 
    temp->next = list->tail;
    temp->pre = NULL;
    list->tail->next = temp;
    list->tail = temp;
    return list;
}