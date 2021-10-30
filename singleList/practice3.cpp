#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

struct node {
    int x;
    int i;
    node *next;
};
struct singleList {
    node *pHead;
    node *pTail;
};
void initialize(singleList *&list){
    list = new singleList;
    list->pHead = list->pTail = NULL;
}
node *createNode(int x, int i){
    node *pNode = new node;
    if(pNode == NULL){
        cout << "Fail program";
        exit(1);
    } else {
        pNode->x = x;
        pNode->i = i;
        pNode->next = NULL;
    }
    return pNode;
}
void insertLast(singleList *&list, node *p){
    if(list->pHead == NULL){
        list->pHead = list->pTail = p;
    } else {
        list->pTail->next = p;
        list->pTail = p;
    }
}
void printList(singleList *list){
    node *temp = list->pHead;
    while(temp != NULL){
        
        if(temp->next != NULL){
            cout << temp->x << "^" << temp->i << "+";
        } else {
            cout << temp->x << "^" << temp->i;
        }
        temp = temp->next;
    }
}
double sumOfList(singleList *list){
    double sum = 0;
    for (node *temp = list->pHead; temp != NULL; temp = temp->next){
        double value = pow(temp->x,temp->i);
        sum += value;
    }
    return sum;
}
int main(){
    singleList *list;
    initialize(list);
    int n,x;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter x: ";
    cin >> x;
    for(int i = 1; i<=n; i++){
        node *p = createNode(x,i);
        insertLast(list,p);
    }
    cout << "Your data: \n";
    printList(list);
    double result = sumOfList(list); 
    cout << "\nYour result: " << result << endl; 
    return 0;
}