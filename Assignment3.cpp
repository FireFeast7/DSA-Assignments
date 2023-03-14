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
	public:Node *inorderPredecessor(Node *ptr){
		if(ptr->LeftThread == true){
			return ptr->left;
		}
		ptr = ptr->left;
		while(ptr->RightThread== false){
			ptr = ptr->right;
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
	public: void preorder(Node *root){
		if(root == NULL){
			cout<<"Tree is Empty"<<endl;
		}
		Node *ptr = root;
		while(ptr!=NULL){
			cout<<ptr->data<<" ";
			if(ptr->LeftThread == false){
				ptr = ptr->left;
			}
			else if(ptr->RightThread == false){
				ptr = ptr->right;
			}
			else{
				while(ptr!=NULL && ptr->RightThread==true){
					ptr = ptr->right;
				}
				if(ptr!=NULL){
					ptr=ptr->right;
				}
			}
		}
	}
	public : Node *caseA(Node *root,Node *parent,Node *ptr){
		if(parent == NULL){
			root = NULL;
		}
		else if(ptr == parent->left){
			parent->LeftThread = true;
			parent->left = ptr->left;
		}
		else{
			parent->RightThread= true;
			parent->right = ptr->right;
		}
		free(ptr);
		return root;
	}
	public : Node *caseB(Node *root,Node *parent,Node *ptr){
		if(parent == NULL){
			root = NULL;
		}	
		else if(ptr == parent->right){
			if(ptr->LeftThread == true){
				ptr->right->left = ptr->right;
				parent->left = ptr->left;
			}
			else{
				ptr->left->right = ptr->right;
				parent->right = ptr->left;
			}
		}
		else{
			if(ptr->RightThread == true){
				ptr->left->right = ptr->right;
				parent->right = ptr->left;			
			}
			else{
				ptr->right->left = ptr->right;
				parent->left = ptr->left;
			}
		}
		free(ptr);
		return root;
	}
	public : Node *caseC(Node *root,Node *parent,Node *ptr){
		if(parent == NULL){
			root = NULL;
		}	
		else{
			Node *succ = inorderSuccessor(root);
			ptr->data = succ->data;
			if(succ->LeftThread==true && succ->RightThread==true){
				caseB(root,parent,ptr);
			}
			else{
				caseA(root,parent,ptr);
			}
		}
		free(ptr);
		return root;
	}
	public:Node *del(Node *root , int val){
		Node *parent = NULL;
		Node *ptr = root;
		bool found = false;
		while(ptr!=NULL){
			if(val == ptr->data){
				found = true;
				break;
			}
			parent = ptr;
			if(val < ptr->data){
				if(ptr->LeftThread==false){
					ptr = ptr->left;
				}
				else{
					break;
				}
			}
			else{
				if(ptr->RightThread == false){
					ptr = ptr->right;
				}
				else{
					break;
				}
			}
		}
			if(found == false){
				cout<<"Key Not Present"<<endl;
			}
			else if(ptr->LeftThread == false && ptr->RightThread == false){
				root = caseC(root,parent,ptr);
			}
			else if(ptr->LeftThread == false){
				root = caseB(root,parent,ptr);
			}
			else if(ptr->RightThread == false){
				root = caseB(root,parent,ptr);
			}
			else{
				root = caseA(root,parent,ptr);
			}
		return root;
	}
};
int main(){
    TBST t1;
    int ch;
	int key;
	int val;
    Node *root = NULL;
    ch = 0;
    while(ch!=-1){
        cout<<endl;
    cout<<"1.Insertion "<<endl;
    cout<<"2.Preorder"<<endl;
    cout<<"3.Inorder"<<endl;
    cout<<"4.Delete Elements "<<endl;
    cout<<"-1 to Stop "<<endl;
    cin>>ch;
    switch(ch){
        case -1:cout<<"Program Ending";
            break;
        case 1:cout<<"Enter The val to Be added "<<endl;
		    cin>>val;
			root=t1.insert(root,val);
            break;
        case 2:t1.preorder(root);
            break;
        case 3:t1.inorder(root);
            break;    
        case 4:cout<<"Enter The key to Be deleted "<<endl;
		    cin>>key;
			root = t1.del(root,key);
            break;    
        default:cout<<" Wrong Input "<<endl;
            break;
        }
    }
    return 0;
}