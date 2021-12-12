#include <iostream>
#include <iomanip>
using namespace std;
typedef struct node
{               //định nghĩa một node
    int data;   // thành phần dữ liệu
    node *next; //thành phần liên kết
};
class Queue
{ //xây dựng lớp queue
public:
    node *start; //đây là con trỏ đến node đầu tiên
    node *end;   // /đây là con trỏ đến node cuối cùng
    node *np;    // /sử dụng một con trỏ trung gian
    void Push(void)
    {              //đưa phần tử vào hàng đợi
        int value; //giá trị node cần thêm
        cout << "Giá trị node:";
        cin >> value;
        np = new node;    //cấp phát miền nhớ cho node
        np->data = value; //thiết lập dữ liệu cho node
        np->next = NULL;  //thiết lập liên kết cho node
        if (start == NULL)
        {                     //nếu danh sách rỗng
            start = end = np; //node đầu và node cuối là một
            end->next = NULL; //cuối cùng là NULL
        }
        else
        {                                                                                          //trường hợp danh sách rỗng
            end->next = np; //node cuối cùng là np
            end = np;                                                                              //đây là node cuối mới
            end->next = NULL;                                                                      //thiết lập liên kết cho end
        }
    }
    int Pop()
    { //lấy phần tử ra khỏi hàng đợi
        int x;
        if (start == NULL)
        { //nếu danh sách rỗng
            cout << "Hàng đợi rỗng" << endl;
        }
        else
        {                        //trường hợp hàng đợi không rỗng
            np = start;          //np trỏ đến node đầu danh sách
            x = np->data;        //đây là nội dung node loại bỏ
            start = start->next; //dịch chuyển lên một node
            delete (np);         //giải phóng node đầu tiên
            return (x);
        }
    }
    void Display(void)
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
    Queue(void)
    { //constructor của lớp
        start = NULL;
        end = NULL;
        np = NULL;
    }
};
int main(void)
{
    int choice;
    Queue X; //X là đối tượng Queue
    do
    {
        cout << "1.Thêm phần tử " << endl;
        cout << "2.Loại phần tử " << endl;
        cout << "3.Duyệt hàng đợi" << endl;
        cout << "0.Thoát " << endl;
        cout << "Đưa vào lựa chọn : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            X.Push();
            break;
        case 2:
            X.Pop();
            break;
        case 3:
            X.Display();
            break;
        default:
            cout << "Lựa chọn sai " << endl;
            break;
        }                  /*End of switch*/
    } while (choice != 0); /*End of while*/
} /*End of main()*/