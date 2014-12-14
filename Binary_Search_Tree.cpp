#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
}*root;
class BST{
    public:
//---------------------------Creating Node-----------------------------
        node *create_node(int value){
            node *temp;
            temp = new node;
            if(temp==NULL){cout<<"memory not allocated."<<endl;}
            else{
                temp->data = value;
                temp->left = NULL;
                temp->right = NULL;
                return temp;
            }
        }
//----------------------------Inserting Element-------------------------
        void insert_elem(int value){
            node *temp,*s;
            temp = create_node(value);
            if(root == NULL){
                root = temp;
                temp->left = NULL;
                temp->right = NULL;
            }

            else{
                s = root;
                while(s!=NULL){
                    if(value > s->data && s->right!=NULL){
                       s = s->right;
                    }
                    else if(value < s->data && s->left!=NULL){
                       s = s->left;
                    }
                    else break;
                }
                if(value > s->data){
                    s->right = temp;
                    temp->left = NULL;
                    temp->right = NULL;
                }
                else{
                    s->left = temp;
                    temp->left = NULL;
                    temp->right = NULL;
                }
            }
        }
//-----------------------------Querying/Searching Element---------
        node *Search_elem(int value){
            node *s = root;
            if(root==NULL){cout<<"Tree is Empty."<<endl;return s = NULL;}
            else{
                while(s!=NULL){
                    if(value > s->data && s->right!=NULL){
                       s = s->right;

                    }
                    else if(value < s->data && s->left!=NULL){
                       s = s->left;
                    }
                    else if(value == s->data){
                       // cout<<"Key exists in the tree."<<endl;
                        return s;
                        break;
                    }
                    else {
                        return s = NULL;
                        break;
                    }
                }
            }
        }
//-----------------------Get Parent of a given node value----------
        node *get_parent(int value){
            node *parent,*s = root;
            if(root==NULL){cout<<"Tree is Empty."<<endl;return parent=NULL;}
            else if(root->data==value){
                return parent = root;
            }
            else{
                while(s!=NULL){
                    if(value == s->data){
                            return parent;
                    }
                    else if(value > s->data && s->right!=NULL){
                        parent = s;
                        s = s->right;
                    }
                    else if(value < s->data && s->left!=NULL){
                        parent = s;
                        s = s->left;
                    }
                    else {
                        cout<<"Key does not exist in the tree."<<endl;
                        break;
                    }
                }
            }
            //return parent;
        }
//-----------------------------Get Successor of give node----------
/*In Binary Tree, Inorder successor of a node is the next node in Inorder traversal of the Binary Tree.
Inorder Successor is NULL for the last node in Inoorder traversal.
1> If right subtree of node is not NULL, then succ lies in right subtree. Do following.
Go to right subtree and return the node with minimum key value in right subtree.
2> If right sbtree of node is NULL, then succ is one of the ancestors. Do following.
Travel up using the parent pointer until you see a node which is left child of it’s parent.
The parent of such a node is the succ.
*/
        node *Successor(int value){
            node *given_node,*succ,*par;
            given_node = Search_elem(value);
            if(given_node==NULL){cout<<"Key does not exist in the tree."<<endl; return succ=NULL;}
            else if(given_node->right!=NULL){
               succ = minimum(given_node->right);
                return succ;
            }
            else{
                par = get_parent(given_node->data);
                while(par!=NULL && par->right == given_node){
                    given_node = par;
                    par = get_parent(par->data);
                }
                return par;
            }
        }


//-----------------------------Find maximum of the tree------------
        node *maximum(node *s){
            if(s==NULL){cout<<"S is Empty."<<endl; return s;}
            else {
                while(s->right!=NULL){s = s->right;}
            }
            return s;
        }

//-----------------------------Find minimum of the tree------------
        node *minimum(node *s){
            if(s==NULL){cout<<"S is empty."<<endl;return s;}
            else{
                while(s->left!=NULL){s = s->left;}
            }
            return s;
        }

//-----------------------------Remove Node-------------------------
        int delete_elem(int value){
            node *del,*succ,*del_parent;
            del = Search_elem(value);
            if(del==NULL){cout<<"Key does not exist."<<endl; return false;}
            else{del_parent=get_parent(del->data);
            if(del->left==NULL && del->right==NULL){
                if(del_parent->right==del){del_parent->right=NULL;}
                if(del_parent->left==del){del_parent->left = NULL;}
                //free(del);
            }
            else if(del->left!=NULL && del->right==NULL){
                //node *left_store = del->left;
                if(del_parent->right==del){del_parent->right=del->left;}
                if(del_parent->left==del){del_parent->left = del->left;}
                free(del);
            }
            else if(del->right!=NULL && del->left==NULL){
               // node *right_store = del->right;
                if(del_parent->right==del){del_parent->right=del->right;}
                if(del_parent->left==del){del_parent->left = del->right;}
                free(del);
            }
            else{
                succ = Successor(del->data);
                node *succ_parent= get_parent(succ->data);
                int d = succ->data;
                if(succ_parent->right==succ){succ_parent->right=NULL;}
                if(succ_parent->left==succ){succ_parent->left = NULL;}
                del->data = d;
            }
            }
        }
//-----------------------------Preorder----------------------------
        int preorder(node *root){
        if(root!=NULL){
            cout<<root->data<<endl;
            if(root->left!=NULL){preorder(root->left);}
            if(root->right!=NULL){preorder(root->right);}
        }
        else{cout<<"Tree is NULL"<<endl;return 0;}
    }

//-----------------------------------------------------------------

};


int main(){
    BST bst;node *temp;
    int choice,k=1,n,val;
    while(k==1){
        cout<<"-------------------------------------"<<endl;
        cout<<"1. Insert Element in BST."<<endl;
        cout<<"2. Preorder Traversal."<<endl;
        cout<<"3. Search eelement in the tree."<<endl;
        cout<<"4. Find maximum of the tree."<<endl;
        cout<<"5. Find minimum of the tree."<<endl;
        cout<<"6. Get parent of the node."<<endl;
        cout<<"7. Get successor of a given node."<<endl;
        cout<<"8. Delete Element."<<endl;
        cout<<"9. Exit."<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter number of elements you want to insert: ";
                cin>>n;
                cout<<"Enter Elements"<<endl;
                while(n--){
                    cin>>val;
                    bst.insert_elem(val);
                }
                break;
            case 2:
                cout<<"Preorder Traversal..."<<endl;
                bst.preorder(root);
                break;
            case 3:
                int sch;
                cout<<"Enter element you want to search: ";
                cin>>sch;
               temp =  bst.Search_elem(sch);
               if(temp==NULL){cout<<"Key does not exist."<<endl;}
               else{cout<<"Key Exists."<<endl;}
                break;
            case 4:
                temp =  bst.maximum(root);
                if(temp!=NULL) {cout<<"Maximum: "<<temp->data<<endl;}
                break;
            case 5:
                temp = bst.minimum(root);
                if(temp!=NULL){cout<<"Minimum: "<<temp->data<<endl;}
                break;
            case 6:
                cout<<"Enter value to get parent: ";
                cin>>val;
                temp = bst.get_parent(val);
                if(temp!=NULL)cout<<"Parent: "<<temp->data<<endl;
                else if(temp==root)cout<<"This is root of the tree.It does not have any parent."<<endl;
                break;
            case 7:
                cout<<"Enter the value of node for which you want to find successor: ";
                cin>>val;
                temp = bst.Successor(val);
                if(temp!=NULL) {cout<<"Successor: "<<temp->data<<endl;}
                break;
            case 8:
                cout<<"Enter value which you want to delete: ";
                cin>>val;
                bst.delete_elem(val);
                break;
            case 9:
                k=0;
                break;
        }
    }
}
