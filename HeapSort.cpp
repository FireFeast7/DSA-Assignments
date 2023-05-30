#include<iostream>
#include<queue>
using namespace std;

class Node{
	int value ; 
	Node *left =nullptr;
	Node *right = nullptr;
	
	friend class Heap;
};

class Heap{
	Node *root = nullptr;
	int numNodes = 0;
	
	public :  void insert(int A[] , int n){
		numNodes = n;
		Node *newNode = new Node;
		newNode->value = A[0];
		root = newNode;
		int i =0;
		queue<Node*> q;
		q.push(root);
	
		while(i<n-1){
			Node *poppedNode = q.front();
			q.pop();
			
			Node *leftNode = new Node;
			leftNode->value = A[++i];
			poppedNode->left = leftNode;
			q.push(poppedNode->left);
			
			Node *rightNode = new Node;
			rightNode->value = A[++i];
			poppedNode->right = rightNode;
			q.push(poppedNode->right);
		}
		
	}
	 void breadthFirst() {
        queue<Node*> q ; 
        q.push( root ) ;
        while( !q.empty() ) {
            Node* poppedNode = q.front() ;
            cout << poppedNode -> value << " " ; 
            q.pop() ; 
            if( poppedNode -> left != NULL ) {
                q.push( poppedNode -> left ) ; 
            }
            if( poppedNode -> right != NULL ) {
                q.push( poppedNode -> right ) ;
            }
        }
        cout << "\n" ; 
    }
  
    Node* heapify(Node *node){
    	if(node == nullptr){
    		return nullptr;
		}
		node->left = heapify(node->left);
		node->right = heapify(node->right);
		if(node->left!=nullptr&& node->left->value > node->value){
			int temp = node->left->value;
			node->left->value = node->value;
			node->value = temp;
			
		}
		if(node->right!=nullptr && node->right->value > node->value){
			int temp = node->right->value;
			node->right->value = node->value;
			node->value = temp;
		}
		return node;
	}
	void sort(){
		    
		for(int i =0;i<numNodes;i++){
			heapify( root ) ; 
			Node *lastnode = getLastNodevalue();
			int temp = root->value;
			root->value = lastnode->value;
			lastnode->value=temp;
			cout << lastnode -> value << " " ; 
			deleteNode(root,lastnode->value);
		}	
	}
	Node* deleteNode(Node *node , int val){
		if(node == nullptr){
			return nullptr;
		}
		if(node->value == val){
			delete node;
			return nullptr;
		}
		node->left = deleteNode(node->left,val);
		node->right = deleteNode(node->right,val);
		return node;
	}
	Node* getLastNodevalue() {   
        queue<Node*> q ; 
        q.push( root ) ; 
        Node* poppedNode = nullptr ; 
        while( !q.empty() ) {
            poppedNode = q.front() ; 
            q.pop() ; 
            if( poppedNode -> left != nullptr ) {
                q.push( poppedNode -> left ) ;
            }
            if( poppedNode -> right != nullptr ) {
                q.push( poppedNode -> right ) ;
            }
        }
        return poppedNode ; 
    }

};

int main(){
	int keys[ 7 ] = { 87 , 5 , 34 , 99 , 44 , 12 , 68 } ; 
    Heap heap ; 
    heap.insert( keys , 7 ) ;
	heap.sort() ; 
	return 0;
}


