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
void BinaryTree ::preOrder (Node* root){
    if (root != NULL){
        cout << root->data <<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void BinaryTree ::inOrder (Node* root){
    if (root != NULL){
        inOrder (root->left);
        cout << root->data <<" ";
        inOrder(root->right);
    }
}
void BinaryTree::posOrder (Node* root){
    if (root != NULL){
        posOrder (root->left);
        posOrder (root->right);
        cout << root->data<<" ";
    }
}
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
int BinaryTree::height(Node* root){
    if(root == NULL)    return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    if(h1>h2)   return h1+1;
    else return h2+1;
}
int BinaryTree::countLeaf(Node* root){
    if(root== NULL) return 0;
    else{
        if(root->left == NULL && root->right == NULL) return 1;
        else return countLeaf(root->left) +countLeaf(root->right);
    }
}
int countBigger = 0;
void BinaryTree::findBigger(Node *root, Item v){
    if (root != NULL){
        if(root->data > v)  countBigger++;
        findBigger(root->left, v);
        findBigger(root->right, v);
    }
}

Node* BinaryTree::search (Node* root,Item v){
    if (root == NULL)
        return NULL;
    if (root->data == v)
        return root;
        Node *q = search(root->left,v);
    if (q==NULL)
        q = search (root->right,v);
}
bool BinaryTree::perfectBinaryTree(Node *root){
    return pow(2,height(root))-1 == size;
}
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
    if(b.perfectBinaryTree(b.root)){
        cout<<"This tree is a perfect binary tree"<<endl;
    }
    b.deleteTree(b.root);
}