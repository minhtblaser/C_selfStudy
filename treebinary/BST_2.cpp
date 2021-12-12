#include <bits/stdc++.h>
typedef int Item;

using namespace std;

struct node
{
    Item data;    // type of data.
    node *left;  //connect to left side.
    node *right; //connect to right side.
};
class BST
{
private:
    Item n;
public:
    node *root; // this is a node root.
    //constructor
    BST(void)
    {
        root = NULL; //establist with NULL
    }
    node *newNode(Item value);                //create node with value
    node *search(node *root, Item value);     //find node with value
    void input(Item);
    void printAscent(Item, Item); //print
    void preorder(node *root);               //scan first
    void inorder(node *root);                //scan midddle
    void postorder(node *root);              // scan last
    node *insert(node *root, Item value);     // add a node with value to tree
    node *minValue(node *p);                 // find the node with min value
    node *deleteNode(node *root, Item value); //delete node with value
    void Function(void);                      //menu
};
node *BST::newNode(Item value)
{
    node *temp = new node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node *BST::search(node *root, Item value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }
    if (root->data < value)
    {
        return search(root->right, value);
    }
    else
    {
        return search(root->left, value);
    }
}
node *BST::insert(node *root, Item value)
{
    if (root == NULL)
    { //check the list is empty ?
        return newNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}
void BST::input(Item n){
    for(int i=0; i<n; ++i){
        Item value;
        cout << "\n Giá trị node cần thêm:";
        cin >> value;
        root = insert(root, value);
    }
}
void printAscent(Item start, Item end){
    if(start>end){
        return;
    }
    printAscent(start*2+1, end);
    cout << root->data << endl;
    printAscent(start*2+2, end);
}
node *BST::minValue(node *p)
{
    node *current = p;            //current poItem to "p"
    while (current->left != NULL) //scan left side
    {
        current = current->left;
    }
    return current;
}
node *BST::deleteNode(node *root, Item value)
{
    if (root == NULL)
    {
        //check the list is empty ???
        return root;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        //case 2:
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        //case 3:
        node *temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}
void BST::preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << setw(5);
        preorder(root->left);
        preorder(root->right);
    }
}
void BST::inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << setw(5);
        inorder(root->right);
    }
}
void BST::postorder(node *root)
{
    postorder(root->left);
    postorder(root->right);
    cout << root->data << setw(5);
}
void BST::Function(void)
{
    node *tmp;
    Item value, choice;
    do
    {
        cout << "\n CÂY NHỊ PHÂN TÌM KIẾM";
        cout << "\n 1. Thêm node vào cây BST";
        cout << "\n 2. Loại node trên cây BST ";
        cout << "\n 3. Tìm node trên cây BST ";
        cout << "\n 4. Duyệt theo thứ tự trước";
        cout << "\n 5. Duyệt theo thứ tự giữa ";
        cout << "\n 6. Duyệt theo thứ tự sau ";
        cout << "\n 0. Thoát ";
        cout << "\n Đưa vào lựa chọn:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n So luong node cần thêm:";
            cin >> n;
            input(n);
            break;
        case 2:
            cout << "\n Giá trị node cần loại:";
            cin >> value;
            root = deleteNode(root, value);
            break;
        case 3:
            cout << "\n Giá trị node cần tìm:";
            cin >> value;
            tmp = search(root, value);
            if (tmp == NULL)
                cout << "\n Node không có trên cây";
            else
                cout << "\n Node " << value << "có trên cây";
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            inorder(root);
            break;
        case 6:
            postorder(root);
            break;
        default:
            if (choice != 0)
                cout << "\n Lua chon sai";
            break;
        }
    } while (choice != 0);
}
Item main()
{
    BST X;
    X.Function();
    return 0;
}