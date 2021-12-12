#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *right;
    node *left;
} * T;
class Tree
{
public:
    Tree(void)
    {
        T = NULL;
    }
    node *Make_Node(void);                    //create node with value
    void Make_Root(void);                     //creat root node
    void Insert_Left(node *root, int value);  //create left leaf node
    void Insert_Right(node *root, int value); //create right leaf node
    void Remove_Left(node *root, int value);  //delete left leaf node
    void Remove_Right(node *root, int value); //delete right leaf node
    void Clear_Tree(node *root);              //free memory allocated
    void NLR(node *root);                     //Node-Left-Right
    void LNR(node *root);                     //Left-Node-Right
    void LRN(node *root);                     //Left-Right-Node
    void Function(void);                      //hàm kiểm tra các thao tác trên cây
};
node *Tree::Make_Node(void)
{
    node *temp = new node;
    int value;
    cout << "Enter value: ";
    cin >> value;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void Tree::Make_Root(void)
{
    if (T != NULL)
    {
        cout << "Tree have already root node";
    }
    else
    {
        node *temp = Make_Node();
        T = temp;           // node root is node temp;
        temp->left = NULL;  //link to node left
        temp->right = NULL; //link to node right
    }
}
void Tree::Insert_Left(node *root, int value)
{
    if (root != NULL)
    { //check the list is empty
        if (root->data == value)
        { //check the node is exist.
            if (root->left != NULL)
            { //check the left node
                cout << "Node " << value << " have left node.";
                return;
            }
            else
            {
                root->left = Make_Node();
                return;
            }
        }
        Insert_Left(root->left, value);  // find left node
        Insert_Left(root->right, value); // find right node
    }
}
void Tree::Insert_Right(node *root, int value)
{
    if (root != NULL)
    { //check the list is empty
        if (root->data == value)
        { //check the node is exist.
            if (root->right != NULL)
            { //check the right node
                cout << "Node " << value << " have left node.";
                return;
            }
            else
            {
                root->rightt = Make_Node();
                return;
            }
        }
        Insert_Right(root->left, value);  // find left node
        Insert_Right(root->right, value); // find right node
    }
}
void Tree::Remove_Left(node *root, int value)
{
    if (root != NULL)
    { //check the list is empty
        if (root->data == value)
        { //check the node is exist.
            if (root->left == NULL)
            { //check the left node
                cout << "Node " << value << " have not node " << endl;
            }
            else if ((root->left)->left != NULL || (root->left)->right != NULL)
            {
                cout << "Node " << value << " has left node" << endl;
            }
            else if ((root->left)->right == NULL && (root->left)->left == NULL)
            {
                node *rp = root->left;
                root->left = NULL;
                delete (rp);
                return;
            }
        }
        Remove_Left(root->left, value);
        Remove_Left(root->right, value);
    }
}
void Tree::Remove_Right(node *root, int value)
{
    if (root != NULL)
    { //check the list is empty
        if (root->data == value)
        { //check the node is exist.
            if (root->right == NULL)
            { //check the right node
                cout << "Node " << value << " have not node " << endl;
            }
            else if ((root->right)->left != NULL || (root->right)->right != NULL)
            {
                cout << "Node " << value << " has left node" << endl;
            }
            else if ((root->left)->right == NULL && (root->left)->left == NULL)
            {
                node *rp = root->right;
                root->right = NULL;
                delete (rp);
                return;
            }
        }
        Remove_Right(root->left, value);
        Remove_Right(root->right, value);
    }
}
void Tree::Clear_Tree(node *root)
{
    if (root != NULL)
    {
        Clear_Tree(root->left);
        Clear_Tree(root->right);
        cout << "Node" << root->data << "is deleted" << endl;
        delete (root);
    }
}
void Tree::NLR(node *root)
{
    if (root != NULL)
    {                                  //nếu cây không rỗng
        cout << root->data << setw(3); //thăm node
        NLR(root->left);               //duyệt theo thứ tự trước cây con trái
        NLR(root->right);              //duyệt theo thứ tự trước cây con phải
    }
}
void Tree::LNR(node *root)
{
    { //duyệt cây theo thứ tự giữa
        if (root != NULL)
        {                                  //nếu cây không rỗng
            LNR(root->left);               //duyệt theo thứ tự giữa cây con trái
            cout << root->data << setw(3); //thăm node
            LNR(root->right);              //duyệt theo thứ tự giữa cây con phải
        }
    }
}
void Tree::LRN(node *root)
{
    if (root != NULL)
    {                                  //nếu cây không rỗng
        LRN(root->left);               //duyệt theo thứ tự sau cây con trái
        LNR(root->right);              //duyệt theo thứ tự sau cây con phải
        cout << root->data << setw(3); //thăm node
    }
}
void Tree::Function(void)
{
    int choice;
    int value;
    node *tmp, *root;
    do
    {
        cout << "\n CÁC THAO TÁC TRÊN CÂY" << endl;
        cout << "1. Tạo node gốc" << endl;
        cout << "2. Tạo node lá trái" << endl;
        cout << "3. Tạo node lá phải " << endl;
        cout << "4. Loại bỏ node lá trái " << endl;
        cout << "5. Loại bỏ node lá phải " << endl;
        cout << "6. Loại bỏ cả cây " << endl;
        cout << "7. Duyệt Node Left Right" << endl;
        cout << "8. Duyệt Left Node Right" << endl;
        cout << "9. Duyệt Left Right Node" << endl;
        cout << "0. Thoát " << endl;
        cout << "Đưa vào lựa chọn:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Make_Root();
            break;
        case 2:
            root = T;
            cout << "Giá trị node lá trái:";
            cin >> value;
            Insert_Left(root, value);
            break;
        case 3:
            root = T;
            cout << " Giá trị node lá phải:";
            cin >> value;
            Insert_Right(T, value);
            break;
        case 4:
            root = T;
            cout << " Giá trị node:";
            cin >> value;
            Remove_Left(root, value);
            break;
        case 5:
            root = T;
            cout << " Giá trị node:";
            cin >> value;
            Remove_Right(root, value);
            break;
        case 6:
            Clear_Tree(T);
            T = NULL;
            break;
        case 7:
            cout << "Duyệt NLR:";
            root = T;
            NLR(root);
            cout << endl;
            break;
        case 8:
            cout << "Duyệt LNR:";
            root = T;
            LNR(root);
            cout << endl;
            break;
        case 9:
            cout << "Duyệt LRN:";
            root = T;
            LRN(root);
            cout << endl;
            break;
        }
    } while (choice != 0);
}
int main(void)
{
    Tree X;
    X.Function();
}