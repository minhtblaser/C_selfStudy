#include <bits/stdc++.h>

using namespace std;

struct Node{
    // giá trị của dữ liệu
    int data;
    // con trỏ trỏ của chính bản thân nó,
    // và nó trỏ tới một thằng Node kế tiếp cũng có kiểu
    Node *next;
};
// kiểu danh sách quản lý
struct singleList{
    Node *head;
    // sử dụng con trỏ head quản lý hết danh sách 
};
void initialize(singleList &input){
    // danh sách rỗng chưa có dữ liệu
    input.head = NULL;
}
// create a new node
Node *createNode(int x){
    Node *pNode = new Node; //cấp phát bộ nhớ;
    if(pNode != NULL){
        pNode->data = x;
        pNode->next = NULL;
    }else{
        cout << "Error";
        exit(1);
    }
    return pNode;
}
// print 
void traverse(singleList list){
    Node *temp = list.head;
    // kt danh sách rỗng
    if(temp == NULL){   
        cout <<"The list is empty!!" << endl;
    } 
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int sizeOfList(singleList list){
    int size = 0;
    Node *temp = list.head;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    return size;
}
void addFirst(singleList &list, int x){
    Node *pNode = createNode(x);
    // Danh sách rỗng, nên phần tử đầu tiên sẽ là node 
    if(list.head == NULL){
        list.head = pNode;
    } else {
        pNode->next = list.head;
        list.head = pNode;
    }
}
void addLast(singleList &list, int x){
    Node *pNode = createNode(x); // tạo cái node mới 
    // Danh sách rỗng, nên phần tử đầu tiên sẽ là node
    if(list.head == NULL){
        list.head = pNode;
    } else {
        Node *temp = list.head;
        // duyệt tìm phần tử cuối cùng, để thêm vào
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = pNode;
    }
}
void addAt(singleList &list, int pos, int x){
    // kiểm tra vị trí có hợp lệ không;
    if(pos < 0 || pos >= sizeOfList(list)){
        cout << "The position is invalid to insert a node" << endl;
    }
    //
    if(pos == 0){
        addFirst(list,x);
    } else if (pos == sizeOfList(list)-1){
        addLast(list,x);
    } else {
        Node *Ins = list.head;
        Node *pPre = NULL; // previous: trước 
        Node *pNode = createNode(x);
        int i = 0;
        while(Ins != NULL){
            if(i == pos){
                break;
            }
            pPre = Ins;
            Ins = Ins->next;
            i++;
        }
        pPre->next = pNode;
        pNode->next = Ins;
    }
}
void removeNode(singleList &list, int value_delete){
    Node *pDel = list.head;
    if(pDel == NULL){
        cout << "\nthe list is empty";
    } else {
        Node *pPre = NULL;
        while(pDel != NULL){
            if(pDel->data == value_delete){
                break;
            }
            // thiết lập con trỏ pPre và pDel
            pPre = pDel;
            pDel = pDel->next;
        }
        if(pDel == NULL){
            cout << "Could not find the number\n";
        } else {
            //Nếu giá trị là đầu tiên
            if(pDel == list.head){
                //cập nhật lại head;
                list.head = list.head->next;
                //quy trình xoá node
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
            } else {
                // cập nhật lại vị trí của previous
                // trỏ tới giá trị mà pDel trỏ tới
                pPre->next = pDel->next;
                // quy trình xoá node  
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
            }
        }
    }
}
Node *searchNode(singleList list, int value_find){
    Node *temp = list.head;
    while(temp != NULL){
        if(temp->data == value_find){
            break;
        }
        temp = temp->next;
    }
    return temp;
}
void sortList(singleList &list){
    for(Node *temp1 = list.head; temp1 != NULL; temp1 = temp1->next){
        for(Node *temp2 = list.head; temp2 != NULL; temp2 = temp2->next){
            if(temp1->data > temp2->data){
                int temp_value = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp_value;
            }
        }
    }
}
int main(){
    singleList list;
    initialize(list);
    // addFirst(list, 1);
    // addFirst(list, 2);
    // addFirst(list, 3);
    // addFirst(list, 4);
    // addFirst(list, 5);
    // traverse (list);
    addLast(list, 7);
    addLast(list, 8);
    addLast(list, 9);
    addLast(list, 10);
    cout <<"the size of single list: "<<sizeOfList(list)<<endl;
    traverse(list);
    cout << "\nthe new list: "; 
    addAt(list, 3, 99);
    traverse(list);
    cout <<"\nthe size of single list: "<<sizeOfList(list)<<endl;
    removeNode(list, 99);
    cout << "the new list: "; 
    traverse(list);
    int value_find;
    cout << "\nenter the number: ";
    cin >> value_find;
    Node *result = searchNode(list,value_find);
    if(result != NULL){
        cout << "The number is exist";
    } else {
        cout << "Not found";
    }
    cout << endl;
    sortList(list);
    traverse(list);
    return 0;
}