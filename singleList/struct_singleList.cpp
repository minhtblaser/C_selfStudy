#include<stdio.h>
#include<string.h>
typedef struct Date {
    int day, month, year;
};
typedef struct Student {
    char id[30];
    char name[30];
    float GPA;
    Date birthday;
} St;
struct NODE {
    St data;
    node *pNext;
};
struct LIST {
    NODE *pHead;
    NODE *pTail;
};
void create (LIST &input);
NODE *createNote(int list); 
void addFirst(LIST &input, NODE *p);
void addLast(LIST &input, NODE *p);

int main(){
    LIST list;


    return 0;
}
void create (LIST &input){
    input.pHead = NULL;
    input.pTail = NULL;
}
NODE *createNote(int list){
    NODE *p = new NODE;
    if(p == NULL){
        printf("\nError.");
        exit(1);
    }
    p->data = list; // send data to variable (list) of NODE P
    p->pNext = NULL;// create NODE but NODE has not any link
    return p;
}
void addFirst(LIST &input, NODE *p){
    if(input.pHead == NULL){
        input.pHead = input.pTail = p; // first node similarity to last nodes        
    } else {
        p->pNext = input.pHead;
        input.pHead = p; // update node P again 
    }
}
void addLast(LIST &input, NODE *p)
{
    if(input.pHead == NULL){
        input.pHead = input.pTail = p;
    } else {
        input.pTail->pNext = p; // pointer of NODE pTail link to Node P
        input.pTail = p; // update NODE P again
    }
}