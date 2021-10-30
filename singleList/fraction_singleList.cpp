#include <bits/stdc++.h>

using namespace std;

struct Fraction {
    float first;
    float second;
};
struct Node {
    Fraction *data;
    Node *next;
};
struct singleList{
    Node *head;
    Node *tail;
};
void initialize(singleList *&list){
    list = new singleList;
    list->head = NULL;
    list->tail = NULL;
}
Node *createNode(float first, float second){
    Node *pNode = new Node;
    if(pNode == NULL){
        cout << "Error:";
        exit(1);
    }
    Fraction *source = new Fraction;
    source->first = first;
    source->second = second;
    pNode->data = source;
    pNode->next = NULL;
    return pNode;
}
void addLast(singleList *&list, float first, float second){
    Node *pNode = createNode(first, second);
    if(list->tail == NULL){
        list->head = list->tail = pNode;
    } else {
        list->tail->next = pNode;
        list->tail = pNode;
    }
}
void traverse(singleList *list){
    Node *temp = list->head;
    while(temp != NULL){
        Fraction *source = temp->data;
        cout << source->first << "/" << source->second << " + ";
        temp = temp->next;
    }

}
float findFactorial(int n){
    if(n <= 1) return 1;
    return n*findFactorial(n-1);
}
float sum(singleList *list){
    float sum = 0;
    Node *temp = list->head;
    while(temp != NULL){
        Fraction *source = temp->data;
        sum = sum + (source->second*1.0/source->second);
        temp = temp->next;
    }
    return sum;
}
int main(){
    singleList *list;
    initialize(list);
    int n, x;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter x: ";
    cin >> x;
    for(int i = 1; i<=n; i++){
        float first = pow (x,i);
        float second = findFactorial(n);
        addLast(list,first,second);
    }
    traverse(list);
    cout << "\nsum = " << sum(list);
    return 0;
}