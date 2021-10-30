#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

struct fraction{
    int numerator; // tử số
    int denominator; // mẫu số
};
struct node {
    node *next; 
    fraction *data;
};
struct singleList {
    node *pHead;
    node *pTail;
};
void initialize(singleList *&list);
void insertLast(singleList *&list, int numerator, int denominator);
node *createNode(int numerator, int denominator);
void printList(singleList *list);
int getFactorial(int n);
double sumOfList(singleList *list);
int main(){
    singleList *list;
    initialize(list);
    int n,x;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter x: ";
    cin >> x;
    for(int i =1; i<= n; i++){
        int numerator = pow(x,i);
        int denominator = getFactorial(i);
        insertLast(list,numerator,denominator);
    }
    cout << "Your data: ";
    printList(list);
    double result = sumOfList(list);
    cout << "\nYour result: " <<result << endl;
    return 0;
}
void initialize(singleList *&list){
    list = new singleList;
    list->pHead = list->pTail = NULL;
}
node *createNode(int numerator, int denominator){
    node *pNode = new node;
    if(pNode == NULL){
        cout << "Fail program" << endl;
        exit(1);
    }
    else{
        fraction *source = new fraction;
        // add value 
        source->numerator = numerator;
        source->denominator = denominator;
        pNode->data = source;
        pNode->next = NULL;
    }
    return pNode;
}
void insertLast(singleList *&list, int numerator, int denominator){
    node *pNode = createNode(numerator,denominator);
    if (list->pTail == NULL){
        list->pHead = list->pTail = pNode;
    } else {
        list->pTail->next = pNode;
        list->pTail = pNode;
    }
}
void printList(singleList *list){
    node *temp = list->pHead;
    while(temp != NULL){
        fraction *source = temp->data;
        if(temp->next != NULL)
            cout << source->numerator << "/" << source->denominator << "+";
        else
            cout << source->numerator << "/" << source->denominator;
        temp = temp->next;
    }
}
int getFactorial(int n){
    if (n<=1){
        return 1;
    }
    return n*getFactorial(n-1);
}
double sumOfList(singleList *list){
    double sum = 0;
    node *temp = list->pHead;
    while(temp != NULL){
        fraction *source = temp->data;
        sum += (source->numerator *1.0 / source->denominator);
        temp = temp->next;
    }
    return sum;
}
