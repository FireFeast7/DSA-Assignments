#include<iostream>
using namespace std;

class Node{
    Node *left;
    Node *right;
    int data;
    bool LeftThread;
    bool RightThread;
    friend class TBST;
};

class TBST{
    public : Node *insert(Node *root,int key){
        Node *curr = root;
        Node *parent = NULL;
        while(curr!=NULL){
            if(curr->data == key){
                cout<<"Node is Already Present in the Tree "<<endl;
                return root;
            }
            parent = curr;
            if(key>curr->data){
                if(curr->RightThread == false){
                    curr = curr->right;
                }
                else{
                    break;  
                }
            }
            else{
                if(curr->LeftThread == false){
                    curr = curr->left;
                }
                else{
                    break;
                }
            }
        }
        Node *newNode = new Node();
        newNode->data = key;
        newNode->LeftThread = true;
        newNode->RightThread = true;
        if(parent == NULL){
            root = newNode;
            newNode->left= NULL;
            newNode->right = NULL;
        }
        else if(key > parent->data){
            newNode->right = parent->right;
            newNode->left = parent;
            parent->RightThread = false;
            parent->right = newNode;
        }
        else{
            newNode->left = parent->left;
            newNode->right = parent;
            parent->LeftThread = false;
            parent->left = newNode;
        }
        return root;
    }
    public: Node *inorderSuccessor(Node *ptr){
        if(ptr->RightThread == true){
            return ptr->right;
        }
        ptr = ptr->right;
        while(ptr->LeftThread == false){
            ptr = ptr->left;
        }
        return ptr;
    }
    public: void inorder(Node *root){
        if(root == NULL){
            cout<<"Tree is Empty"<<endl;
        }
        Node *ptr = root;
        while(ptr->LeftThread == false){
            ptr = ptr->left;
        }
        while(ptr != NULL){
            cout<<ptr->data<<" ";
            ptr = inorderSuccessor(ptr);
        }
    }

};
int main(){
    TBST t1;
    Node *root = NULL;
    root = t1.insert(root,10);
    root = t1.insert(root,5);
    root = t1.insert(root,20);
    t1.inorder(root);
    return 0;
}
