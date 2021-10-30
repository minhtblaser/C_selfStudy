#include <iostream>
using namespace std;
/* tạo cấu trúc node */
struct Node  {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
struct Node *head, *tail; // Khởi tạo Node head global của dslk đôi.
  
/* tạo node mới */
struct Node* CreateNode(int x) {
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
/* hiển thị từ đầu đến cuối */
void Print() {
    struct Node* temp = head;
    printf("\nĐầu đến cuối: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
  
/* hiển thị từ cuối về đầu */
void ReversePrint() {
    struct Node* temp = tail;
    if(temp == NULL) return; // empty list, exit
    // Traversing backward using prev pointer
    printf("\nCuối về đầu: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
/* thêm node vào đầu danh sách */
void InsertFirst(int x) {
  //sử dụng hàm tạo Node tạo một Node mới
    struct Node* newNode = CreateNode(x);
   //nếu danh sách rỗng thì node chèn vào vừa là node đầu vừa là node cuối
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    //Nếu danh sách không rỗng thì, dịch chuyển Node head về node mới chèn, và cho con trỏ của newNode trỏ đến Node head
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
/* thêm node vào cuối danh sách */
void InsertLast(int x) {
  //sử dụng hàm tạo Node để tạo node mới newNode
    struct Node* newNode = CreateNode(x);
    //Nếu danh sách rỗng thì newNode vừa là node đầu vừa là node cuối
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    //Nếu danh sách có phần tử thì, 
    tail->next = newNode;// con trỏ next của tail trỏ đến newNode
    newNode->prev = tail;// con trỏ prev của newNode trỏ đến tail
    tail = newNode;//dịch chuyển tail về newNode, vì tail luôn luôn quản lý phần tử cuối cùng trong danh sách
}
/* Xóa node đầu trong danh sách */
void DelFirst() {
  //Nếu danh sách rỗng thì return và thoát khỏi hàm
    if(head == NULL) {
        return;
    }
    //ngược lại nếu danh sách có phần tử thì 
    head = head->next;//thực hiện dịch chuyển node head đến node kế tiếp
    head->prev = NULL;//sau đó cho con trỏ prev của head = null
}
/* Xóa node cuối trong danh sách */
void DelLast() {
  //Nếu danh sách rỗng thì return và thoát khỏi hàm
    if(head == NULL) {
        return;
    }
    //Ngược lại nếu danh sách có phần tử thì 
    tail = tail->prev;//thực hiện dịch chuyển tail về node trước đó
    tail->next = NULL;//sau đó cho con trỏ next của tail == null
}
int main() {
  
    head = NULL;
 //gọi hàm thêm node vào đầu danh sách
     
    InsertFirst(2);
    InsertFirst(3);
    InsertFirst(4);
    cout<<"Danh sách sau khi thêm node vào đầu: \n";
    Print();
    ReversePrint(); 
    cout<<"\n----------end--------------\n";
 //gọi hàm thêm node vào cuối danh sách
    InsertLast(5);
    InsertLast(6);
    InsertLast(7);
    cout<<"Danh sách sau khi thêm node vào cuối: \n";
    Print(); 
    ReversePrint();
    cout<<"\n----------end--------------\n";
  //gọi hàm xóa đầu danh sách
    DelFirst();
    cout<<"Danh sách sau khi xóa đầu : \n";
    Print();
    ReversePrint();
    cout<<"\n----------end--------------\n";
  //gọi hàm xóa cuối danh sách
    DelLast();
    cout<<"Danh sách sau khi xóa cuối : \n";
    Print();
    ReversePrint();
 
    cout<<"\n---------------------------------------\n";
    cout<<"Chương trình này được đăng tại freetuts.net";
}