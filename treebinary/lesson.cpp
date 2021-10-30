#include <bits/stdc++.h>

using namespace std;
// define struct node
struct Node {
    int data;
    Node *left;
    Node *right;
} *T;
// define class tree
class Tree {
    public:
        // constructor
        Tree(void){
            T = NULL;
        }
    // create a discrete node 
    Node *Make_Node(void);
    // create root node
    void Make_Root(void);
    void Insert_Left(Node *root, int value);
    void Remove_Left(Node *root, int value);
    void Insert_Right(Node *root, int value);
    void Remove_Right(Node *root, int value);
    void Clear_Tree(Node *&root);
    void NLR(Node *root); // scanf tree according to first
    void LNR(Node *root); // scanf tree according to between
    void LRN(Node *root); // scanf tree according to follow
    void Function(void); // function to check methods on tree 
};
Node *Tree::Make_Node(void){
    Node *temp;
    int value;
    temp = new Node;
    cout << "Value of node: ";
    cin >> value;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void Tree::Make_Root(void){
    if(T==NULL){
        Node *temp = Make_Node();
        T = temp;
        temp->left = NULL;
        temp->right = NULL;
    } else {
        cout << "Tree have already root";
    }
}
void Tree::Insert_Left(Node *root, int value){
    if(root != NULL){
        if(root->data == value){
            if(root->left != NULL){
                cout << "Node " << value << "have already left" << endl;
                return;
            }
            else {
                root->left = Make_Node(); // create left node
                return;
            }
        }
        Insert_Left(root->left, value);
        Insert_Right(root->right, value);
    }
}
void Tree::Insert_Right(Node *root, int value){
    if(root != NULL){
        if(root->data == value){
            if(root->right != NULL){
                cout << "Node " << value << "have already right" << endl;
                return;
            }
            else {
                root->right = Make_Node(); // create left node
                return;
            }
        }
        Insert_Left(root->left, value);
        Insert_Right(root->right, value);
    }
}
void Tree::Remove_Left(Node *root, int value){
    if(root != NULL){
        if(root->data == value){
            if(root->left == NULL){
                cout << "Node " << value << "don't have left node" << endl;
                return;
            } else if ((root->left)->left != NULL || (root->left)->right != NULL){
                cout << "Node " << value << "have already" << endl;
                return;
            }
            else if ((root->left)->left == NULL && (root->left)->right == NULL){
                // if node have left child 
                Node *rp = root->left;
                root->left = NULL;
                delete(rp);
                return;
            }
        }
        Remove_Left(root->left, value);
        Remove_Left(root->right, value);
    }
}
void Tree::Remove_Right(Node *root, int value){
    if(root != NULL){
        if(root->data == value){
            if(root->right == NULL){
                cout << "Node " << value << "don't have left node" << endl;
                return;
            } else if ((root->right)->left != NULL || (root->right)->right != NULL){
                cout << "Node " << value << "have already" << endl;
                return;
            }
            else if ((root->right)->left == NULL && (root->right)->right == NULL){
                // if node have left child 
                Node *rp = root->right;
                root->right = NULL;
                delete(rp);
                return;
            }
        }
        Remove_Right(root->left, value);
        Remove_Right(root->right, value);
    }
}

void Tree::Clear_Tree(Node *&root){
    if(root != NULL){
        Clear_Tree(root->left);
        Clear_Tree(root->right);
        cout << "Node " << root->data << "is deleted"<< endl;
        delete(root);
    }
}
void Tree::NLR(Node *root){
    if(root != NULL){
        cout << root->data << setw(3);
        NLR(root->left);
        NLR(root->right);
    }
}
void Tree:: LNR(Node *root){
    if(root != NULL){
        LNR(root->left); // scanf according to orders 
        cout << root->data << setw(3); // check node
        LNR(root->right);
    }
}
void Tree::LRN(Node *root){
    if(root != NULL){
        LRN(root->left);
        LRN(root->right);
        cout << root->data << setw(3); // check
    }
}
void Tree::Function(void){
    int choice, value;
    Node *temp, *root;
    do{
        cout << "\nMenu" << endl;
        cout << "1. Create original root" << endl;
        cout << "2. Create left node" << endl;
        cout << "3. Create right node" << endl;
        cout << "4. Remove left node" << endl;
        cout << "5. Remove right node" << endl;
        cout << "6. Remove all tree" << endl;
        cout << "7. Scanf node left right" << endl;
        cout << "8. Scanf left node right" << endl;
        cout << "9. Scanf left right node" << endl;
        cout << "0. Exit";
        cout << "\nYour choice: ";
        fflush(stdin);
        cin >> choice;
        switch(choice){
            case 1: Make_Root(); break;
            case 2:
                root = T; 
                cout << "Value left node: ";
                cin >> value;
                Insert_Left(root, value);
                break;
            case 3: 
                root = T;
                cout <<"The value of right left: ";
                cin >> value;
                Insert_Right(root, value);
                break;
            case 4: 
                root = T;
                cout << "The value of node: ";
                cin >> value;
                Remove_Left(root, value);
                break;
            case 5:
                root = T;
                cout << "The value of node";
                cin >> value;
                Remove_Right(root, value);
                break;
            case 6: 
                Clear_Tree(T); 
                T = NULL;
                break;
            case 7: 
                cout << "Scanf NLR: ";
                root = T;
                NLR(root);
                break;
            case 8:
                cout << "Scanf LNR: ";
                root = T;
                LNR(root);
                break;
            case 9: 
                cout << "Scanf LRN: ";
                root = T;
                LRN(root);
                break;
        }
    } while(choice != 0);
}
int main(){
    Tree X;
    X.Function();
    return 0;
}
