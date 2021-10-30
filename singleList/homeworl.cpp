#include <bits/stdc++.h>

using namespace std;

struct Student{
    int id;
    char name[100];
    float GPA;
    string class_subject;
    string major;
};
struct Node{
    Student *data;
    Node *next;
};
struct singleList{
    Node *head;
};
void initialize(singleList *&list);
Student *enterStudent();
Node *createNode(Student *source);
void addLast(singleList *&list, Student *source);
void SortList(singleList *&list);
void traverse(singleList *list);
void removeNode(singleList *&list, int id_delet);
void findStudentByID(singleList *&list, int id_find, Student *source);
int main(){ 
    singleList *list;
    initialize(list);
    // Student *Minh = enterStudent();
    // addLast(list,Minh);
    // Student *Phat = enterStudent();
    // addLast(list,Phat);
    // Student *Anh = enterStudent();
    // addLast(list,Anh);
    Student *source;
    int n;
    cout << "Enter the number of student: ";
    cin >> n;
    for(int i=0;i<n;i++){
        *(source+i) = enterStudent();
        addLast(list,source+i);
    }
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
    int id_find;
    cout << "\nEnter id_find: ";
    cin >> id_find;
    findStudentByID(list,id_find,source);
    return 0;
}
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
    cout << "Enter class: ";
    getline(cin, source->class_subject);
    cout << "Enter major: ";
    getline(cin, source->major);
    cout << "Enter GPA: ";
    cin >> source->GPA;
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
void findStudentByID(singleList *&list, int id_find, Student *source){
    Node *temp = list->head;
    Student *svTemp = temp->data;
    while(temp != NULL){
        if(svTemp->id == id_find){
            break;
        }
        temp = temp->next;
    }
    cout << svTemp->name << "\t" << svTemp->id << "\t" <<
            svTemp->class_subject << "\t" << svTemp->major << "\t" << svTemp->GPA << endl;
}