#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#define MAX 100
    
class Node{
    Node *left;
    int data;
    Node *right;
    friend class BinaryTree;
};
class Stack {
    int top;
public:
    Node *a[MAX]; 
    Stack() { top = -1; }
    void push(Node *);
    void pop();
    Node* peek();
    bool isEmpty();
};
void Stack::push(Node *x)
{
        a[++top] = x;      
}
void Stack::pop()
{
     a[top--];
}
Node* Stack::peek()
{
    if (top < 0) {
        return 0;
    }
    else {
        Node *x = a[top];
        return x;
    }
} 
bool Stack::isEmpty()
{
    return (top < 0);
}
class BinaryTree{
    private : int ch;
        public:Node *insert(){
            Node *temp = new Node();
            int x;
            cout<<"Enter Data or -1 for No Data "<<endl;
            cin>>x;
            if(x==-1){
                return NULL;
            }
            else{
                temp->data= x;
                cout<<"For The Left Child of "<<x<<endl;
                temp->left = insert();
                cout<<"For the Right Child of "<<x<<endl;
                temp->right = insert();
            }
            return temp;
        }
        public:void preorder(Node *root) {
        if (root == nullptr) {
            return;
        }

        Stack s;
        s.push(root);

        while (!s.isEmpty()) {
            Node *curr = s.peek();
            s.pop();
            cout << " " << curr->data;

            if (curr->right != nullptr) {
                s.push(curr->right);
            }

            
            if (curr->left != nullptr) {
                s.push(curr->left);
            }
        }
    }
        public:void inorder(Node *root){
            Stack s;
            Node *curr = root;
            while (curr != NULL || s.isEmpty() == false)
            {
                while (curr !=  NULL)
                {
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.peek();
                s.pop();
                cout << curr->data << " ";
                curr = curr->right;
            } 
        }
        public:void postorder(Node *root){
            Stack s1;
            Stack s2;
            s1.push(root);
            Node *curr = new Node();
            while(!s1.isEmpty()){
                curr = s1.peek();
                s1.pop();
                s2.push(curr);
                if(curr->left!=NULL){
                    s1.push(curr->left);
                }
                if(curr->right!=NULL){
                    s1.push(curr->right);
                }
            }
            while (!s2.isEmpty())
            {
                curr = s2.peek();
                s2.pop();
                cout<<" "<<curr->data;
            }   
        }
        public:int height(Node *root){
            int height = 0;
            int nodeCount = 0;
            queue<Node *> level;
            Node *currentNode;
            level.push(root);
            while(!level.empty()){
                    height++;
                    nodeCount = level.size();
            while(nodeCount--){
                currentNode = level.front();
                if (currentNode->left!=NULL)
                {
                    level.push(currentNode->left);
                }
                if(currentNode->right!=NULL){
                    level.push(currentNode->right);
                }
                level.pop();
                }
            }
            return height;
        }
        public: int countLeaves(Node *root){
            queue<Node *> nodes;
            int count = 0;
            nodes.push(root);
            while(!nodes.empty()){
                Node *temp = nodes.front();
                nodes.pop();
                if(temp->left==NULL && temp->right==NULL){
                    count++;
                }
                if(temp->left!=NULL){
                    nodes.push(temp->left);
                }
                if(temp->right!=NULL){
                    nodes.push(temp->right);
                }
            }
            return count;
        }
        public: int countInternal(Node *root){
            queue<Node *> q;
            int count = 0;
            q.push(root);
            while(!q.empty()){
                Node *curr = new Node();
                curr = q.front();
                q.pop();
                bool isInternal = 0;
                if(curr->left!=NULL){
                    isInternal = 1;
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    isInternal = 1;
                    q.push(curr->right);
                }
                if(isInternal){
                    count++;
                }
            }
            return count;
        }
        public:void deleteTree(Node *root){
            queue<Node *> q;
            q.push(root);
            while(!q.empty()){
                Node *curr = new Node();
                curr = q.front();
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
                delete (curr);
            }
        }
        public:void swapping(Node* root){
                if(root == NULL){
                    return ;
                }
                else{
                    Node *ptr;
                    swapping(root->left);
                    swapping(root->right);
                    ptr = root->left;
                    root->left = root->right;
                    root->right = ptr;
                }
        } 
        public:Node *copyTree(Node *root){
            if(root == NULL){
                return NULL;
            }
            else{
                Node *newNode = new Node();
                newNode = root;
                newNode->left = copyTree(root->left);
                newNode->right = copyTree(root->left);
                cout<<"SuccessFully Copied all the values to another Tree"<<endl;
                return newNode;
            }
        }
};

int main(){
    BinaryTree b1;
    int ch;
    Node *root = NULL;
    Node *copy = NULL;
    ch = 0;
    while(ch!=-1){
        cout<<endl;
    cout<<"1.Insertion "<<endl;
    cout<<"2.Preorder"<<endl;
    cout<<"3.Inorder"<<endl;
    cout<<"4.PostOrder"<<endl;
    cout<<"5.Height of Tree"<<endl;
    cout<<"6.Count Leaf Nodes "<<endl;
    cout<<"7.Count Internal Nodes "<<endl;
    cout<<"8.Delete Tree "<<endl;
    cout<<"9.Swapping Nodes "<<endl;
    cout<<"10.Copy Binary Tree"<<endl;
    cout<<"-1 to Stop "<<endl;
    cin>>ch;
    switch(ch){
        case -1:cout<<"Program Ending";
            break;
        case 1:root=b1.insert();
            break;
        case 2:b1.preorder(root);
            break;
        case 3:b1.inorder(root);
            break;    
        case 4:b1.postorder(root);
            break;    
        case 5:cout<<" "<<b1.height(root);
            break;    
        case 6:cout<<" "<<b1.countLeaves(root);
            break;       
        case 7:cout<<" "<<b1.countInternal(root);
            break;
        case 8:b1.deleteTree(root);
            break;                 
        case 9:b1.swapping(root);
            break;
        case 10:copy = b1.copyTree(root);
            break;
        default:cout<<" Wrong Input "<<endl;
            break;
        }
    }
    return 0;
}
