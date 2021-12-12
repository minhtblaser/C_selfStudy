#include <bits/stdc++.h>
typedef int Item
#pragma once;
typedef struct Node
{                    //định nghĩa một Node
    Customer data;   //thành phần dữ liệu
    Node *next;      //thành phần liên kết
};
class Queue
{ //xây dựng lớp queue
private:
    Node *start; //đây là con trỏ đến Node đầu tiên
    Node *end;   //đây là con trỏ đến Node cuối cùng
    Node *np;    //sử dụng một con trỏ trung gian
public:
    void Push(void);
    int Pop();
    void Display(void);                      
    Queue(void)
    { //constructor của lớp
        start = NULL;
        end = NULL;
        np = NULL;
    }
};
void Queue::Push(void)
    {              //đưa phần tử vào hàng đợi
        int value; //giá trị Node cần thêm
        cout << "Giá trị Node:";
        cin >> value;
        np = new Node;    //cấp phát miền nhớ cho Node
        np->data = value; //thiết lập dữ liệu cho Node
        np->next = NULL;  //thiết lập liên kết cho Node
        if (start == NULL)
        {                     //nếu danh sách rỗng
            start = end = np; //Node đầu và Node cuối là một
            end->next = NULL; //cuối cùng là NULL
        }
        else
        {                                                                                          //trường hợp danh sách rỗng
            end->next = np; //Node cuối cùng là np
            end = np;                                                                              //đây là Node cuối mới
            end->next = NULL;                                                                      //thiết lập liên kết cho end
        }
    }
int Queue::Pop()
    { //lấy phần tử ra khỏi hàng đợi
        int x;
        if (start == NULL)
        { //nếu danh sách rỗng
            cout << "Hàng đợi rỗng" << endl;
        }
        else
        {                        //trường hợp hàng đợi không rỗng
            np = start;          //np trỏ đến Node đầu danh sách
            x = np->data;        //đây là nội dung Node loại bỏ
            start = start->next; //dịch chuyển lên một Node
            delete (np);         //giải phóng Node đầu tiên
            return (x);
        }
    }
void Queue::Display(void)
    { //duyệt hàng đợi
        np = start;
        if (np == NULL)
            cout << "Hàng đợi rỗng" << endl;
        else
        {
            cout << "Nội dung hàng đợi:";
            while (np != NULL)
            {
                cout << np->data << setw(3);
                np = np->next;
            }
            cout << endl;
        }
    }
void Queue::function(){
    Item choice;
    ifstream file;
    file.open("D:/C_advance/practice_DST/ex7/data.txt");
    file >> n;
    for(int i=1; i<=n; ++i){
        Customer source;
        file >> source; 
        Push();
    }
    do{
        cout <<"0.Nhấn 0 để thoát màn hình." << endl;
        cout <<"1.Thêm 1 khách hàng vào hàng đợi chờ phục vụ, cho biết số thứ tự của người đó." << endl;
        cout <<"2.Cho biết thông tin khách hàng tiếp theo sẽ được phục vụ là ai và xuất khách hàng đó ra khỏi hàng đợi." << endl;
        cout <<"3.Cho biết có bao nhiêu khách hàng chưa được phục vụ?" << endl;
        cout <<"4.Cho biết có bao nhiêu khách hàng đã được phục vụ?" << endl;
        cout <<"Lua chon: ";
        cin >> choice;
        switch(choice){ 
            case 0:{
                cout << "GOOD BYE" << endl;
                break;
            }
            case 1: 
            {
                
                break;
            }
            case 2: 
            {
                
                break;
            }
            case 3:
            {
                
                
                break;
            }
            case 4: 
            {
                
                break;
            }
        }
    }while(choice != 0);
    file.close();
}