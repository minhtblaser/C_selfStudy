//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
#include <bits/stdc++.h>
typedef int Item;

using namespace std;

struct node
{
    Item data;   // type of data.
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
    void preorder(node *root);               //scan first
    void inorder(node *root);                //scan midddle
    void postorder(node *root);              //scan last
    node *insert(node *root, Item value);    //add a node with value to tree
    node *minValue(node *p);                 //find the node with min value
    node *maxValue(node *p);                 //find the node with max value   
    Item sumOfList(node *p);                 //find the sum of list 
    void Function(void);                     //menu
};
node *BST::newNode(Item value)
{
    node *temp = new node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Xác định nút chứa khóa X.
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
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Tạo một cây nhị phân gồm n nút, mỗi nút lưu một phần tử của một mảng số
//nguyên cho trước.
void BST::input(Item n){
    for(int i=0; i<n; ++i){
        Item value;
        cout << "\n Giá trị node cần thêm: ";
        cin >> value;
        root = insert(root, value);
    }
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//In node có giá trị nhỏ nhất
node *BST::minValue(node *p)
{
    node *current = p;            //current poItem to "p"
    while (current->left != NULL) //scan left side
    {
        current = current->left;
    }
    return current;
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//In node có giá trị lớn nhất
node *BST::maxValue(node *p)
{
    node *current = p;             //current point to "p"
    while (current->right != NULL) //scan left side
    {
        current = current->right;
    }
    return current;
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//In theo giá trị giảm dần.
void BST::preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << setw(5);
        preorder(root->left);
        preorder(root->right);
    }
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//In theo giá trị tăng dần.
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
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << setw(5);
    }
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Tinh tong cac node 
Item BST::sumOfList(node *p){
    if(p == NULL){
        return 0;
    }
    return p->data + sumOfList(p->left) + sumOfList(p->right);
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Ham main de kiem tra
void BST::Function(void)
{
    node *tmp, *min_result, *max_result;
    Item value, choice;
    do
    {
        cout << "\n CÂY NHỊ PHÂN TÌM KIẾM";
        cout << "\n 1. Thêm node vào cây BST";
        cout << "\n 2. Xuất ra màn hình giá trị của mỗi nút theo chiều tăng dần.";
        cout << "\n 3. Xuất ra màn hình giá trị của mỗi nút theo chiều giảm dần.";
        cout << "\n 4. Xác định nút chứa khóa X.";
        cout << "\n 5. Cho biết nút có giá trị lớn nhất.";
        cout << "\n 6. Cho biết nút có giá trị nhỏ nhất.";
        cout << "\n 7. Tính tổng các giá trị trên cây..";
        cout << "\n 0. Thoát ";
        cout << "\n Đưa vào lựa chọn:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n So luong node cần thêm: ";
            cin >> n;
            input(n);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            cout << "\n Giá trị node cần tìm: ";
            cin >> value;
            tmp = search(root, value);
            if (tmp == NULL)
                cout << "\n Node không có trên cây";
            else
                cout << "\n Node " << value << " có trên cây";
            break;
        case 5:
            max_result = maxValue(root);
            cout << "\n Max value of BST: " << max_result->data << endl;
            break;
        case 6:
            min_result = minValue(root);
            cout << "\n Min value of BST: " << min_result->data << endl;
            break;
        case 7: 
            cout << "\n The sum of node: " << sumOfList(root) << endl;
            break;
        default:
            if (choice != 0)
                cout << "\n Lua chon sai";
            break;
        }
    } while (choice != 0);
}
int main()
{
    BST X;
    X.Function();
    return 0;
}