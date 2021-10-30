#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Student {
    int id;
    char name[30];
};
struct node {
    Student *data;
    node *next;
};
struct singleList{
    node *pHead;
};
void initialize (singleList *&list);
node *createNode(Student *source);
Student *enter();
void insertLast (singleList *&list, Student *source);
void printList(singleList *list);
void sortList(singleList *&list);
void removeNode(singleList *&list, int id_delete);
int main(){
    singleList *list;
    int id_delete;
    initialize(list);
    Student *minh = enter();
    insertLast(list, minh);
    Student *phat = enter();
    insertLast(list, phat);
    Student *an = enter();
    insertLast(list, an);
    printList(list);
    cout << "\nT.he list after swaping\n";
    sortList(list);
    printList(list);
    cout << "\nEnter id delete: ";
    cin >> id_delete;
    removeNode(list,id_delete);
    cout << "\nNew list\n";
    printList(list);
    return 0;
}
void initialize (singleList *&list){
    list = new singleList;
    list->pHead = NULL;
}
node *createNode(Student *source){
    node *pNode = new node;
    if(pNode != NULL){
        pNode->data = source;
        pNode->next = NULL;
    } else {
        cout << "Fail allocate memory" << endl;
    }
    return pNode;
}
Student *enter(){
    Student *source = new Student;
    cout << "enter id: ";
    cin >> source->id;
    cin.ignore();
    cout <<"enter name: ";
    gets(source->name);
    return source;
}
void insertLast (singleList *&list, Student *source){
    node *pNode = createNode(source);
    if(list->pHead == NULL){
        list->pHead = pNode;
    } else {
        node *temp = list->pHead;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = pNode;
    }
}
void printList(singleList *list){
    node *temp = list->pHead;
    if(temp == NULL){
        cout << "\nThe list is empty";
        return;
    }
    while(temp != NULL){
        Student *student = temp->data;
        cout << "Id: "<<student->id << "\t" <<"Name: "<< student->name << endl;
        temp = temp->next;
    }
}
void sortList(singleList *&list){
    for(node *temp = list->pHead; temp != NULL; temp = temp->next){
        for(node *temp2 = temp->next; temp2 != NULL; temp2 = temp2->next){
            Student *ptemp = temp->data;
            Student *ptemp2 = temp2->data;
            if (ptemp->id > ptemp2->id){
                int id = ptemp->id;
                char name[30];
                strcpy(name,ptemp->name);
                //swap value
                ptemp->id = ptemp2->id;
                strcpy(ptemp->name,ptemp2->name); 
                ptemp2->id = id;
                strcpy(ptemp2->name, name);
            }
        }
    }
}
void removeNode(singleList *&list, int id_delete){
    node *pDel = list->pHead;
    if (pDel == NULL)
        cout << "The list is empty";
    else {
        node *pPre = NULL;
        while (pDel != NULL){
            Student *temp = pDel->data;
            if (temp->id == id_delete){
                break;
            }
            pPre = pDel;
            pDel = pDel->next;
        } if (pDel == NULL){
            cout <<"not find" <<id_delete;
        } else {
            if(pDel == list->pHead){
                //check the first nodes
                list->pHead = list->pHead->next;
                //begin delete node
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
            } else {
                //check the nodes 
                pPre->next = pDel->next;
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
            }
        }
    }
}
