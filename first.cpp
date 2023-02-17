#include<iostream>
#include<algorithm>
using namespace std;

class Node{
    Node *left;
    int data;
    Node *right;
    friend class BST;
};

class BST{
    public:Node* insert(Node *root , int x){
        if(root == NULL){
            Node *newnode = new Node();
            newnode->left = NULL;
            newnode->data = x;
            newnode->right = NULL;
            return newnode;
        }
        else if(x <= root->data){
            
            root->left = insert(root->left , x);
        }
        else{
            root->right = insert(root->right , x);
        }
        return root;
    }
    public : void preorder(Node *root){
        if(root == NULL){
            return ;
        }
        else{
            cout<<" "<<root->data;
            preorder(root->left);
            preorder(root->right);
        }
    }
    public: void inorder(Node* root){
        if(root == NULL){
            return ;
        }
        else{
            inorder(root->left);
            cout<<" "<<root->data;
            inorder(root->right);
        }
    }
    public:bool search(Node *root , int x){
        if(root == NULL){
            return false;
        }
        else if(root->data == x){
            return true;
        }
        else if(root->data < x){
            return search(root->right,x);
        }
        else{
            return search(root->left,x);
        }
    }
    public:int min(Node *root){
        if(root == NULL){
            cout<<"Empty Tree"<<endl;
            return -1;
        }
        else if(root->left==NULL){
            return root->data;
        }
        else{
            return min(root->left);
        }
    }
     public:int maxi(Node *root){
        if(root == NULL){
            cout<<"Empty Tree"<<endl;
            return -1;
        }
        else if(root->right==NULL){
            return root->data;
        }
        else{
            return maxi(root->right);
        }
    }
    public : int height(Node *root){
        if(root == NULL){
            cout<<"Empty Tree ";
            return -1;
        }
        else{
            return max(height(root->left),height(root->right))+1;
        }
    }
};
int main(){
    BST btree;
    Node *root = NULL;
    root = btree.insert(root,15);
    root = btree.insert(root,20);
    root = btree.insert(root,12);
    btree.preorder(root);
    btree.inorder(root);
    int k = btree.maxi(root);
    int m = btree.min(root);
    cout<<m<<" "<<k;
    cout<<btree.search(root,23);
    return 0;
}