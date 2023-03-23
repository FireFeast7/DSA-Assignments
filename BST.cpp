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
    public: void swap(Node *temp){
        if(temp == NULL){
            return ;
        }
        else{
            Node *ptr;
            swap(temp->left);
            swap(temp->right);
            ptr = temp->left;
            temp->left = temp->right;
            temp->right = ptr;
        }
    }
     public: Node* minvalue(Node *node){
        Node *current = node;
        while(current && current->left!=NULL){
            current = current->left;
        }
        return current;
    }
    public : Node* del(Node *root, int key)
    {
        if(root == NULL){
            return root;
        }
        else if(key < root->data){
            root->left = del(root->left,key);
        }
        else if(key > root->data){
            root->right = del(root->right,key);
        }
        else{
            if(root->left==NULL && root->right ==NULL){
                delete root;
                root= NULL;
                
            }
            else if(root->left==NULL){
                Node* temp = new Node() ;
                temp = root;
                root = root->right;
                delete temp;
            }
             else if(root->right==NULL){
                Node* temp = new Node() ;
                temp = root;
                root = root->left;
                delete temp;
            }   
            else{
                Node *temp = minvalue(root->right);
                root->data = temp->data;  
                root->right = del(root->right,temp->data);
            }
        }
        return root;
    }
};
int main(){
    BST btree;
    Node *root = NULL;
    root = btree.insert(root,20);
    root = btree.insert(root,10);
    root = btree.insert(root,30);
    root = btree.insert(root,25);
    root = btree.insert(root,40);
    root = btree.insert(root,15);
    root = btree.insert(root,5);
    root = btree.insert(root,3);
    btree.preorder(root);
    cout<<endl;
    btree.inorder(root);
    cout<<endl;
    int k = btree.maxi(root);
    int m = btree.min(root);
    cout<<" "<<m<<endl<<" "<<k<<endl;
    cout<<" "<<btree.search(root,23)<<endl;
//    btree.swap(root);
//    btree.inorder(root);
   root = btree.del(root,20);
   root = btree.del(root,5);
    btree.inorder(root);
    return 0;
}

    