#include <bits/stdc++.h>
#define MAX 100

using namespace std;

class Queue
{
    public:
        int node[MAX];
        int inp; // move element to queue
        int out; // remove element from queue
        void push();
        void pop();
        void Display();
    //constructor.
    Queue(void)
    {
        inp = -1;
        out = -1;
    }
};
void Queue::push()
{
    int value;
    if (inp == MAX - 1)
    {
        cout << "The queue is full!" << endl;
    }
    else
    {   // nhap 1
        if(out == -1){
            out = 0; //set place = 0;
        }
        cout << "Enter the value of node: ";
        cin >> value;
        inp++;
        node[inp] = value;
        //inp = 0 ;
        //node[0] = 1, nod[1]= 2, node[2] = 3, node[3] = 4, node[4] = 5 ==>inp = 4;
    }
}
// pop: xóa ptu dau tien
// 1 2 3 4 5 
// queue:  2 3 4 5 
// pop = 4;
// out = 4;
// pop: 
//inp: 4
//out: 5
void Queue::pop()
{
    if (out == -1 || out > inp)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        cout << "Node: " << node[out] << endl;
        //out = 0;
        out++;
        //out = 1;  
    }
}
void Queue::Display()
{                  //duyệt các node trong hàng đợi
    if (out == -1) //trường hợp hàng đợi rỗng
        cout << "Queue is empty " << endl;
    else
    {
        cout << "Nội dung hàng đợi : ";
        for (int i = out; i <= inp; i++)
            cout << node[i] << setw(3);
    }
    cout << endl;
}

int main()
{
    int choice;
    Queue X; //định nghĩa đối tượng X là queue
    do
    {
        cout << "1. Đưa phần tử vào hàng đợi" << endl;
        cout << "2. Lấy phần tử ra khỏi hàng đợi" << endl;
        cout << "3. Duyệt các node của hàng đợi " << endl;
        cout << "0. Thoát " << endl;
        cout << "Đưa vào lựa chọn : ";
        cin >> choice;
        switch (choice)
        {
        case 0: cout << "GOOD BYE"; break;
        case 1:
            X.push();
            break;
        case 2:
            X.pop();
            break;
        case 3:
            X.Display();
            break;
        default:
            cout << "Lựa chọn sai" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}