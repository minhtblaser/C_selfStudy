#include <iostream>

using namespace std;
// duyệt tuyến tính == linear search
struct node {
    int data; // struct 
    node *pNext;
};   
struct singlelist{
    node *pHead;
    node *pTail;
};
void initialize(singlelist &list);
node *createNode(int x);
void printList(singlelist list);
int sizeOfList(singlelist list);
void addFirst(singlelist &list, int x);
void addLast(singlelist &list, int x);
void addAt(singlelist &list, int pos, int x);
void removeNode(singlelist &list, int d);
node *searchNode(singlelist list, int n);
void sortList(singlelist &list);
void addLastElement(singlelist &list, node *p);
void freeMemory(singlelist &list);
float sumOfList(singlelist list);// tính tổng
void Max(singlelist list);
// tìm kiếm phần tử nhỏ nhất / lớn nhất
// in ra số lượng trong ds
int main(){
    singlelist list;
    int n,pos,value,value_dele;
    initialize(list);
    cout << "The number of nodes: ";
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        node *pNode = createNode(x);
        addLastElement(list,pNode);
    }
    cout << "The list number: ";
    printList(list);
    // cout << "\n-enter the new value: ";
    // cin >> value;
    // cout << "-enter the position: ";
    // cin >> pos;
    // addAt(list,pos,value);
    // cout << "-The new list of number: ";
    // printList(list);
    // cout << "\n-Enter the value to delete: ";
    // cin >> value_dele;
    // removeNode(list,value_dele);
    // cout << "\nThe list of number after deleting: ";
    // printList(list);
    // cout << "\nThe list of number by arranging: ";
    // sortList(list);
    // printList(list);
    float result_sunm = sumOfList(list);
    cout << "\nThe result sum of list number is "<< result_sunm <<endl;
    Max(list);
    freeMemory(list);
    return 0;
}
void initialize(singlelist &list){
    list.pHead = NULL;
    list.pTail = NULL;
}
node *createNode(int x){
    node *temp = new node;
    if (temp != NULL){
        temp->data = x;
        temp->pNext = NULL;
    } else {
        cout <<"PROGRAM FAILED" << endl;
    }
    return temp;
}
void addLastElement(singlelist &list, node *p){
    if(list.pHead == NULL){
        list.pHead = list.pTail = p; // first node is the same last node
    }else{
        list.pTail->pNext = p;
        list.pTail = p;
    }
}
void printList(singlelist list){
    node *temp = list.pHead;
    if(temp == NULL){
        cout << "The list is empty";
        return;
    }
    while(temp != NULL){
        cout << " " << temp->data << " ";
        temp = temp->pNext;
    }
}

int sizeOfList(singlelist list){
    node *temp = list.pHead;
    int nSize = 0;
    while(temp != NULL){
        temp = temp->pNext;
        nSize++;
    }
    return nSize;
}
void addFirst(singlelist &list, int x){
    node *temp = createNode(x);
    //check the list is empty ??
    //if the list is empty, temp is the first node
    if(list.pHead == NULL){
        list.pHead = temp;
    } else {
        temp->pNext = list.pHead;
        list.pHead = temp;
    }
}
void addLast(singlelist &list, int x){
    node *pNode = createNode(x);
    if (list.pHead == NULL){
        list.pHead = pNode;
    } else {
        node *temp = list.pHead;
        while(temp != NULL){
            temp = temp->pNext;
        }
    temp->pNext = pNode;
    }
}
void addAt(singlelist &list, int pos, int x){
    if(pos < 0 || pos >= sizeOfList(list)){
        cout << "Novalid position do insert";
        return;
    } 
    if (pos == 0){
        addFirst(list, x);
    } else if (pos == sizeOfList(list) - 1){
        addLast(list, x);
    } else {
        node *pNode = createNode(x);
        node *pIns = list.pHead;
        node *pPre = NULL;
        int i = 0;
        while(pIns != NULL){
            // the inserted position 
            if(i == pos)
                break;
            pPre = pIns; // store
            pIns = pIns->pNext;
            i++;
        }
        //connect the link among nodes 
        pNode->pNext = pIns;
        pPre->pNext = pNode;
    }
}
void removeNode(singlelist &list, int x){
    node *pDel = list.pHead;
    if(pDel == NULL){
        cout << "The list is empty";
    }
    else {
        node *pPre = NULL;
        while(pDel != NULL){
            if(pDel->data == x){
                break;
            }
            pPre = pDel;
            pDel = pDel->pNext;
        }
        if(pDel == NULL){
            cout << "Could not found number";
        }
        else {
            //case 1: remove the first node 
            if(pDel == list.pHead){
                //point to the next node, it is the new first node
                list.pHead = list.pHead->pNext;
                //begin delete node
                pDel->pNext = NULL;
                delete pDel;
                pDel = NULL;
            }
            else{
                //case 2: remove not the first node
                // two node point to the same place
                pPre->pNext = pDel->pNext;
                //pDeL is null, it also meant deleting
                pDel->pNext = NULL;
                delete pDel;
                pDel = NULL;
            }
        }
    }
}
node *searchNode(singlelist list, int n){
    node *temp = list.pHead;
    while(temp != NULL){
        if(temp->data == n){
            break;
        }
        temp=temp->pNext; 
    }
    return temp;
}
void sortList(singlelist &list){
    for(node *temp = list.pHead; temp != NULL; temp = temp->pNext){
        for(node *temp2 = temp->pNext; temp2 != NULL; temp2 = temp2->pNext){
            if(temp->data > temp2->data){
                int ptemp = temp->data;
                temp->data = temp2->data;
                temp2->data = ptemp;
            }
        }
    }
}
void freeMemory(singlelist &list){
    cout << "\nStarting to delete\n";
    while(list.pHead != NULL){
        node *temp = list.pHead;
        list.pHead = temp->pNext;
        temp->pNext =NULL;
        cout << temp->data << " is deleted\n";
        delete temp;
        temp = NULL;
    }
    cout << "Deleted is complete\n";
}
float sumOfList(singlelist list){
    node *temp = list.pHead;
    float sum = 0;
    while(temp != NULL){
        sum += temp->data;
        temp = temp->pNext;
    }
    return sum;
}
void Max(singlelist list){
    int Max =0;
    node *temp = list.pHead;
    while (temp != NULL){
        if( temp->data > Max){
           Max = temp->data;
 
        }
        temp = temp->pNext;
    }
    cout <<"Phan tu lon nhat: " << Max << endl;
 
}