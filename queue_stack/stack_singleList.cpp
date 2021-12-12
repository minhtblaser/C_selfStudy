#include <bits/stdc++.h>

using namespace std;

struct node
{
    int info;
    node *link;
} * Stack;
class stack_list
{
public:
    node *push(node *, int); //add elements to stack
    node *pop(node *);       // remove elements from stack
    void traverse(node *);   //scan stack
    stack_list()
    {
        Stack = NULL;
    }
};
node *stack_list::push(node *Stack, int item)
{
    node *temp = new node;
    temp->info = item;
    temp->link = Stack; // establish link to temp;
    Stack = temp;       // temp is the first node in the stack list
    return Stack;
}
node *stack_list::pop(node *Stack)
{
    node *temp;
    if (Stack == NULL)
    {
        cout << "The list is empty!" << endl;
    }
    else
    {
        temp = Stack;
        cout << "The element is removed " << temp->info << endl;
        Stack = Stack->link;
        free(temp);
    }
    return Stack;
}
void stack_list::traverse(node *Stack)
{
    node *ptr = Stack;
    if (Stack == NULL)
    {
        cout << "The stack is empty!" << endl;
    }
    else
    {
        cout << "The element in stack: ";
        while (ptr != NULL)
        {
            cout << ptr->info << setw(5);
            ptr = ptr->link;
        }
    }
}
int main()
{
    int choice, item;
    stack_list X;
    do
    {
        cout << "\n-----------------------------------------" << endl;
        cout << "CÁC THAO TÁC TRÊN STACK" << endl;
        cout << "\n----------------------------------------" << endl;
        cout << "1. Đưa phần tử vào stack" << endl;
        cout << "2. Lấy phần tử ra khỏi stack" << endl;
        cout << "3. Duyệt stack" << endl;
        cout << "0. Thoát" << endl;
        cout << "Dua vao lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Nhap gia tri: ";
            cin >> item;
            Stack = X.push(Stack, item);
            break;
        case 2:
            Stack = X.pop(Stack);
            break;
        case 3:
            X.traverse(Stack);
            break;
        default:
            cout << "Lựa chọn sai" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}