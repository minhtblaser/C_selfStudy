//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
#include <bits/stdc++.h>
#include "language.cpp"
typedef int Item;
#pragma once

struct node
{
    Language data;   // type of data.
    node *left;      //connect to left side.
    node *right;     //connect to right side.
};
class BST
{
private:
    Item n;
    node *root; // this is a node root.
public:
    //constructor
    BST(void)
    {
        root = NULL; //establist with NULL
    }
    node *newNode(Language value);                //create node with value
    node *search(node *root, string word_find);   //find node with value
    void input(node *root);       //input            
    void inorder(node *root);                     //scan midddle
    node *insert(node *, Language);               // add a node with value to tree
    node *deleteNode(node *root, string word_delete); // delete node with value
    node *minValue(node *p);
    void Function();                              //menu
};
node *BST::newNode(Language value){
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
//Them mot node
//
node *BST::insert(node *root, Language value){
    if (root == NULL)
    { //check the list is empty ?
        return newNode(value);
    }
    //su dung ham strcmp
    if (value.getEnglish() < (root->data).getEnglish())
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
//Xoa mot node
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
//Them mot node
void BST::input(node *root){
    Language value;
    string new_english, new_vietnamese;
    fflush(stdin);
    cout << "English:";
    getline(cin, new_english);
    value.setEnglish(new_english);
    fflush(stdin);
    cout << "Vietnamese:";
    getline(cin, new_vietnamese);
    value.setVietnamese(new_vietnamese);
    root = insert(root, value);
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
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Tim kiem theo mot tu khoa
node *BST::search(node *root, string word_find)
{
    if (root == NULL || (root->data).getEnglish() == word_find)
    {
        return root;
    }
    if ((root->data).getEnglish() < word_find)
    {
        return search(root->right, word_find);
    }
    else
    {
        return search(root->left, word_find);
    }
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Xoa mot node
node *BST::deleteNode(node *root, string word_delete)
{
    if (root == NULL)
    {
        //check the list is empty ???
        return root;
    }
    if (word_delete < (root->data).getEnglish())
    {
        root->left = deleteNode(root->left, word_delete);
    }
    else if (word_delete > (root->data).getEnglish())
    {
        root->right = deleteNode(root->right, word_delete);
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
        root->right = deleteNode(root->right, (root->data).getEnglish());
    }
    return root;
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Ham main de kiem tra
void BST::Function()
{
    node *tmp;
    Item choice;
    ifstream file;
    string word_delete, word_find;
    file.open("D:/C_advance/practice_DASA_2/ex3/data.txt");
    file >> n;
    for(int i=1; i<=n; ++i){
        Language value;
        file>>value;
        root = insert(root, value);
    }
    do
    {
        cout << "\n CÂY NHỊ PHÂN TÌM KIẾM";
        cout << "\n 1. Thêm node vào cây BST";
        cout << "\n 2. Xóa một nút.";
        cout << "\n 3. Tìm kiếm theo một từ khóa.";
        cout << "\n 0. Thoát ";
        cout << "\n Đưa vào lựa chọn:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            input(root);
            inorder(root);
            break;
        case 2:
            fflush(stdin);
            cout << "\n Giá trị node cần loại (english): ";
            getline(cin,word_delete);
            root = deleteNode(root, word_delete);
            inorder(root);
            break;
        case 3:
            fflush(stdin);
            cout << "\n Giá trị node cần tim (english): ";
            getline(cin,word_find);
            tmp = search(root, word_find);
            if (tmp == NULL)
                cout << "\n Node không có trên cây";
            else
                cout << "\n Tu " << word_find << " có trên cây";
            break;
        default:
            if (choice != 0)
                cout << "\n Lua chon sai";
            break;
        }
    } while (choice != 0);
    file.close();
}