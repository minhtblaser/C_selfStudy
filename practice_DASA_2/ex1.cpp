//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
#include<bits/stdc++.h>
using namespace std;
typedef int Item;
struct Node {
    Item data;
    Node *left;
    Node *right;
};
class BinaryTree{
    public:
        BinaryTree();
        BinaryTree(Item v);
        Node* createNode(Item v);
        bool isEmpty();
        void deleteTree(Node* &root);
        void preOrder(Node* root);
        void inOrder(Node* root);
        void posOrder(Node* root);
        void insertleft(Node* p, Item v);
        void insertright(Node* p, Item v);
        int height(Node* root);
        int countLeaf(Node* root);
        void findBigger(Node* root, Item v);
        Node* search(Node* root,Item v);
        int findMax(Node *root);
        bool perfectBinaryTree(Node* root);
        Node* root;
        int size;
};
BinaryTree::BinaryTree(){
    root = NULL;
    size = 0;
}
BinaryTree::BinaryTree(Item v){
    root = createNode(v);
    size = 1;
}
Node* BinaryTree::createNode(Item v){
    Node* p = new Node;
    p->data = v;
    p->left = p->right = NULL;
    return p;
}
bool BinaryTree::isEmpty(){
    return root == NULL;
}
void BinaryTree ::deleteTree(Node* &root){
    if (root != NULL){
        deleteTree (root->left);
        deleteTree (root->right);
        delete root;
        root = NULL;
    }
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Ham duyet truoc
void BinaryTree ::preOrder (Node* root){
    if (root != NULL){
        cout << root->data <<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Ham duyet giua
void BinaryTree ::inOrder (Node* root){
    if (root != NULL){
        inOrder (root->left);
        cout << root->data <<" ";
        inOrder(root->right);
    }
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Ham duyet sau
void BinaryTree::posOrder (Node* root){
    if (root != NULL){
        posOrder (root->left);
        posOrder (root->right);
        cout << root->data<<" ";
    }
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Ham them vao ben phai cay
void BinaryTree::insertright(Node* p,Item v){
    if (p == NULL) {
        cout << "error";
        return;
    }
    else if (p->right != NULL) {
        cout << "node right is existed";
        return;
    }
    else{
        p->right = createNode(v);
        size++;
    }
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Ham them vao ben trai cay
void BinaryTree::insertleft(Node* p, Item v){
    if (p == NULL) {
        cout << "error";
        return;
    }
    else if (p->left != NULL) {
        cout << "node left is existed";
        return;
    }
    else {
        p->left = createNode(v);
        size++;
    }
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Ham tim kiem
Node* BinaryTree::search (Node* root,Item v){
    if (root == NULL)
        return NULL;
    if (root->data == v)
        return root;
        Node *q = search(root->left,v);
    if (q==NULL)
        q = search (root->right,v);
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Ham xac dinh chieu cao
int BinaryTree::height(Node* root){
    if(root == NULL)    return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    if(h1>h2)   return h1+1;
    else return h2+1;
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Dem so nut la tren cay
int BinaryTree::countLeaf(Node* root){
    if(root== NULL) return 0;
    else{
        if(root->left == NULL && root->right == NULL) return 1;
        else return countLeaf(root->left) +countLeaf(root->right);
    }
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Dem so nut co gia tri hon X
int countBigger = 0;
void BinaryTree::findBigger(Node *root, Item v){
    if (root != NULL){
        if(root->data > v)  countBigger++;
        findBigger(root->left, v);
        findBigger(root->right, v);
    }
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Tim gia tri lon nhat trong cay
int BinaryTree::findMax(Node *root){
    // Base case
    if (root == NULL)
        return INT_MIN;
    // Return maximum of 3 values:
    // 1) Root's data 
    // 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Tim gia tri nho nhat trong cay
int findMin(Node *root)
    {
        //code
        if(root==NULL)
     {
         return INT_MAX;
     }
       int res=root->data;
       int left=findMin(root->left);
       int right=findMin(root->right);
       if(left<res)
       {
           res=left;
       }
       if(right<res)
       {
           res=right;
       }
       return res;
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Kiểm tra cây có phải là cây đầy đủ (Perfect binary tree).
bool BinaryTree::perfectBinaryTree(Node *root){
    return pow(2,height(root))-1 == size;
}
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
//Hàm main 
int main(){
    BinaryTree b(5);
    b.insertleft(b.root, 3);
    b.insertright(b.root, 7);
    b.insertleft(b.search(b.root,3), 2);
    b.insertright(b.search(b.root,3), 10);
    b.insertleft(b.search(b.root,7), 6);
    b.insertright(b.search(b.root,7), 1);
    b.preOrder(b.root);
    cout<<endl<<"Height: "<<b.height(b.root)<<endl;
    cout<<"Number of nodes: "<<b.size<<endl;
    cout<<"Count leaf node: "<<b.countLeaf(b.root)<<endl;
    b.findBigger(b.root,5);
    cout<<"Bigger than x: "<<countBigger<<endl;
    cout << "The max value is " << b.findMax(b.root) <<endl;
    if(b.perfectBinaryTree(b.root)){
        cout<<"This tree is a perfect binary tree"<<endl;
    }
    b.deleteTree(b.root);
}