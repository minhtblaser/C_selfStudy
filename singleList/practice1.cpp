#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};
struct singleList {
    list = new singleList; 
    node *pHead;
    node *pTail;
};
void initialize(singleList &list);
node *createNode(int x);
void addElement(singleList &list, node *p);
void addFirst(singleList &list, node *p);
int sizeOfList(singleList list);
void printList(singleList &list);
int findMax(singleList list);
int findMin(singleList list);
void addElementInFirst(singleList &list, int value);
void addElementInLast(singleList &list, int value);
void addAt(singleList &list, int pos ,int value);
void removeNode(singleList &list, int x);
float sumOfList(singleList list);
node *searchNumber(singleList list, int x);
void freeMemory(singleList &list);
int main(){
    singleList list;
    initialize(list);
    int n,value,pos,value_delete,value_find;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        node *pNode = createNode(x);
        addElement(list,pNode);
    }
    cout << "The list of number: ";
    printList(list);
    int max = findMax(list);
    int min = findMin(list);
    cout<< "\nThe max number in the list: " << max << endl;
    cout<< "The min number in the list: " << min << endl;
    float sum = sumOfList(list);
    cout << "The sum of list nodes: " << sum;
    cout << "\nEnter the number you want to find: ";
    cin >> value_find;
    node *result_find = searchNumber(list,value_find);
    if (result_find != NULL){
        cout << "\nThe number is found in the list";
    } else {
        cout << "\nThe number is not found in the list";
    }
    cout << "\n-enter the new value: ";
    cin >> value;
    cout << "-enter the position: ";
    cin >> pos;
    addAt(list,pos,value);
    cout << "-The new list of number: ";
    printList(list);
    cout << "\nEnter the number to delete: ";
    cin >> value_delete;
    removeNode(list,value_delete);
    cout <<"\nThe new list of number after deleting: ";
    printList(list);
    freeMemory(list);
    return 0;
}
void initialize(singleList &list){
    list.pHead = NULL;
    list.pTail = NULL;
}
node *createNode(int x){
    node *temp = new node;
    if (temp != NULL){
        temp->next = NULL;
        temp->data = x;
    } else {
        cout << "Program failed";
    }
    return temp;
}
void addElement(singleList &list, node *p){
    if(list.pHead == NULL){
        list.pHead = list.pTail = p; 
    } else {
        list.pTail->next = p;
        list.pTail = p;
    }
}
void addFirst(singleList &list, node *p){
    if(list.pHead == NULL){
        list.pHead = list.pTail = p;
    } else {
        p->next = list.pHead;
        list.pHead = p;
    }
}
void printList(singleList &list){
    node *temp = list.pHead;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    } 
}
int findMax(singleList list){
    int max = list.pHead->data;
    for(node *k = list.pHead; k != NULL; k = k->next){ 
        if (max < k->data){
            max = k->data;
        }
    }
    return max;
}
int findMin(singleList list){
    int min = list.pHead->data;
    for(node *k = list.pHead; k != NULL; k = k->next){
        if (min > k->data){
            min = k->data;
        }
    }
    return min;
}
void addElementInFirst(singleList &list, int value){
    node *temp = createNode(value);
    if(list.pHead == NULL){
        list.pHead = temp;
    } else {
        temp->next = list.pHead;
        list.pHead = temp;
    }
}
// Thêm vào cuối
// Chúng ta sẽ cần Node đầu tiên, và giá trị muốn thêm. Khi đó, ta sẽ:
// Tạo một Node mới với giá trị value
// Nếu head = NULL, tức là danh sách liên kết đang trống. Khi đó Node mới(temp) sẽ là head luôn.
// Ngược lại, ta sẽ duyệt tới Node cuối cùng(Node có next = NULL), và trỏ next của thằng cuối tới Node mới(temp).
void addElementInLast(singleList &list, int value){
    node *temp = createNode(value);
    if(list.pHead == NULL){
        list.pHead = temp;
    } else {
        node *pNode = list.pHead;
        while(pNode->next != NULL){
            pNode = pNode->next;
        }
        pNode->next = temp;
    }
}
void addAt(singleList &list, int pos, int value){
    if (pos < 0 || pos >= sizeOfList(list)){
        cout << "No valid position do insert.";
            return ;
    }
    if(pos == 0){
        addElementInFirst(list,value);
    } else if (pos == sizeOfList(list)-1){
        addElementInLast(list,value);
    } else {
        node *pNode = createNode(value);
        node *pIns = list.pHead;
        node *pPre = NULL;
        int i = 0;
        while(pIns != NULL){
            if(i == pos){
                break;
            }
            pPre = pIns;
            pIns = pIns->next;
            i++;
        }
        pNode->next = pIns;
        pPre->next= pNode;
    }
}
int sizeOfList(singleList list){
    node *temp = list.pHead;
    int size = 0;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    return size;
}
void removeNode(singleList &list, int x){
    node *pDel = list.pHead;
    if (pDel == NULL){
        cout << "\nThe list is empty";
    } else {
        node *pPre = NULL;
        while (pDel != NULL){
            if (pDel->data == x){
                break;
            }
            pPre = pDel;
            pDel = pDel->next;
        }
        if(pDel == NULL){
            cout << "\nCould not find the number";
        } else {
            if(pDel == list.pHead){
                //check the first nodes
                list.pHead = list.pHead->next;
                //begin delete node
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
            }else if (pDel->next == NULL) {
                list.pTail = pPre;
                list.pTail->next = NULL;
                delete pDel;
                pDel = NULL;
            }
            else {
                //check the nodes 
                pPre->next = pDel->next;
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
            }
        }
    }
}
void freeMemory(singleList &list){
    cout << "\nStarting to delete\n";
    while(list.pHead != NULL){
        node *temp = list.pHead;
        list.pHead = temp->next;
        temp->next = NULL;
        cout << temp->data << " is deleted\n";
        delete temp;
        temp = NULL;
    }
    cout << "Deleted is complete\n";
}
float sumOfList(singleList list){
    node *temp = list.pHead;
    float sum = 0;
    while(temp != NULL){
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}
node *searchNumber(singleList list, int x){
    node *temp = list.pHead;
    while(temp != NULL){
        if(temp->data == x){
            break;
        }
        temp = temp->next;
    }
    return temp;
}
