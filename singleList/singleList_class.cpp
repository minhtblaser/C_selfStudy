#include <bits/stdc++.h>

using namespace std;

struct Student{
    int id;
    char name[100];
};
struct Node{
    Student *data;
    Node *next;
};
struct singleList{
    Node *head;
};
void initialize(singleList *&list){
    list = new singleList;
    list->head = NULL;
}
Student *enterStudent(){
    Student *source = new Student;
    cout << "Enter id: ";
    cin >> source->id;
    cin.ignore();
    cout << "Enter name: ";
    gets(source->name);
    return source;
}
Node *createNode(Student *source){
    Node *pNode = new Node;
    if(pNode != NULL){
        pNode->data = source;
        pNode->next = NULL;
    } else {
        cout << "Error";
        exit(1);
    }
    return pNode;
}
void addLast(singleList *&list, Student *source){
    Node *pNode = createNode(source);
    if(list->head == NULL){
        list->head = pNode;
    } else {
        Node *temp = list->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = pNode;
        pNode->next = NULL;
    }
}
void SortList(singleList *&list){
    for(Node *temp1 = list->head; temp1 != NULL; temp1 = temp1->next){
        for(Node *temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next){
            Student *sVtemp1 = temp1->data;
            Student *sVtemp2 = temp2->data;
            if(sVtemp1->id < sVtemp2->id){
                int id = sVtemp1->id;
                char name[100];
                strcpy(name, sVtemp1->name);
                //swap
                sVtemp1->id= sVtemp2->id;
                strcpy(sVtemp1->name, sVtemp2->name);
                sVtemp2->id = id;
                strcpy(sVtemp2->name,name);
            }
        }
    }
}
void traverse(singleList *list){
    Node *temp = list->head;
    if(temp == NULL){
        cout << "The list is full";
    }
    cout<<"\n--------------DATA-------------\n";
    while(temp != NULL){
        //way 1
        // cout << temp->data->id << endl;
        // cout << temp->data->name << endl;
        //way2
        Student *source = temp->data;
        cout << source->id <<"\t"<< source->name << endl;
        temp = temp->next;
    }
}
void removeNode(singleList *&list, int id_delet){
    Node *pDel = list->head;
    if(pDel == NULL){
        cout << "The list is empt";
    } else {
        Node *pPre = NULL;
        while(pDel != NULL){
            Student *source = pDel->data;
            if(source->id == id_delet){
                break;
            }
            pPre = pDel;
            pDel = pDel->next;
        }
        if(pDel == NULL){
            cout << "Not found";
        } else {
            if(pDel == list->head){
                list->head = list->head->next;
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
            } else {
                pPre->next = pDel->next;
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
            }
        }
    }
}
int main(){ 
    singleList *list;
    initialize(list);
    Student *Minh = enterStudent();
    addLast(list,Minh);
    Student *Phat = enterStudent();
    addLast(list,Phat);
    Student *Anh = enterStudent();
    addLast(list,Anh);
    traverse(list);
    cout << "\nNew list: ";
    SortList(list);
    traverse(list);
    int id_delet;
    cout << "Enter id_delet: ";
    cin >> id_delet;
    removeNode(list,id_delet);
    cout << "\nNew list: ";
    traverse(list);
    return 0;
}