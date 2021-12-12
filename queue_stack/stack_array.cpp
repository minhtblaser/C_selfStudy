#include <bits/stdc++.h>
#define MAXSIZE 10
using namespace std;
//array
//a[-1] dk: index > 0
//su dung mang đe cai dat cau truc stack 
typedef struct STK
{
    int top;           //place: performance
    int node[MAXSIZE]; //data of node in stakck
};
class STACK
{
public:
    STK s;       //define stack is MAX node
    void push(); //get value from stack
    void pop();
    void display();
    STACK(void)
    {
        s.top = -1; //establish s.top == -1;
        // tại sao dat gia tri bang 1????
    }
};
void STACK::push()
{
    int value;
    if (s.top == (MAXSIZE-1))
    { //check the list is empty
        cout << "The stack is full" << endl;
        return ; //exit(1);
    }
    else
    {
        cout << "Enter value: ";
        cin >> value;
        s.top = s.top + 1; //move top 1 node ===>> s.top = 0;
        s.node[s.top] = value; //s.node[0] = value ===> node[0] = value;
    }
}
// 1 2 3 4 5 ==> đưa vô stack
//---> pop = 5 
void STACK::pop()
{
    int value;
    if (s.top == -1)
    {
        cout << "The list is empty." << endl;
        return;
    }
    else
    {   //xoa gia tri 5 => s.top =  
        value = s.node[s.top]; //the value of node is taked.
        cout << "The value is deleted " << s.node[s.top] << endl;
        s.top = s.top - 1;
        //node [0,1,2,3];
    }
}
void STACK::display()
{
    if (s.top == -1)
    {
        cout << "The stack is empty" << endl;
        return;
    }
    else
    {
        cout << "\nThe list element: " << endl;
        for (int i = s.top; i >= 0; i--)
        {
            cout << s.node[i] << setw(3);
        }
    }
}
int main()
{            //chương trình chính
    STACK X; //định nghĩa đối tượng X
    int choice;
    cout << "CÁC THAO TÁC TRÊN STACK\n";
    do
    {
        cout << "\n------------------------------------------\n";
        cout << " 1 -- >PUSH\n ";
        cout << "2 -- >POP\n ";
        cout << "3 -- >DISPLAY\n ";
        cout << "0 -- >EXIT\n ";
        cout << "------------------------------------------\n";
        cout << "Đưa vào lựa chọn:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            X.push();
            break;
        case 2:
            X.pop();
            break;
        case 3:
            X.display();
            break;
        default:
            cout << "Lựa chọn sai";
            break;
        }
    } while (choice != 0);
}