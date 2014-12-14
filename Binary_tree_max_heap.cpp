#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
} *root;
class Binary_tree{
        //node *create_node(int value);
        //void Insert_Elem(value)
        //int height
        //Max_Heapify
        //preorder


    public:
//------------------creating node ----------------------------------------
    node *create_node(int value){
        struct node *temp;
        temp = new node;
        if(temp==NULL){
            cout<<"memory not allocated"<<endl;
        }
        else{
            temp->data = value;
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        }
    }
//-------------------------inderting element------------------------------
    void Insert_Elem(int value){
        node *s,*temp;
        s = root;
        temp = create_node(value);
        if(root==NULL){
            root = temp;
            temp->left = NULL;
            temp->right = NULL;
        }
        else{
            queue<node *> qu;
            qu.push(root);
            while(qu.size()!=0){
                node *node1 = qu.front();
                qu.pop();
                if(node1->left!=NULL){qu.push(node1->left);}
                if(node1->right!=NULL){qu.push(node1->right);}
                if(node1->left==NULL){
                    node1->left = temp;
                    temp->left=NULL;
                    temp->right=NULL;
                    break;
                }
                else{
                    if(node1->right==NULL){
                        node1->right = temp;
                        temp->left=NULL;
                        temp->right=NULL;
                        break;
                    }

                }
            }
        }
    }
//-----------------------------level order traversal--------------------------------------------
    vector <node *> level_travel(){
        queue<node *>qu;
        vector <node *> A;
        vector<int> vec_data;
        qu.push(root);
        int cnt=0;
            while(qu.size()>0){
                node *node1 =qu.front();
                A.push_back(node1);
                vec_data.push_back(node1->data);
                qu.pop();cnt++;
                if(node1->left!=NULL){qu.push(node1->left);}
                if(node1->right!=NULL){qu.push(node1->right);}
            }
        return A;
    }
//-----------------------------height--------------------------------------------
    vector <int> data_vec(){
        queue<node *>qu;
        vector<int> vec_data;
        qu.push(root);
        int cnt=0;
            while(qu.size()>0){
                node *node1 =qu.front();
                vec_data.push_back(node1->data);
                qu.pop();cnt++;
                if(node1->left!=NULL){qu.push(node1->left);}
                if(node1->right!=NULL){qu.push(node1->right);}
            }
        return vec_data;
    }
//-----------------------------max-heapify---------------------------------------
    int Max_Heapify(node *node1){
        int largest,k;
        if(node1->left==NULL){return 0;}
        else{
        if(node1->left->data > node1->data){
            k=1;
            largest = node1->left->data;
        }
        else{
            largest = node1->data;
        }
        if(node1->right!=NULL){
            if(node1->right->data > largest){
                k=0;largest = node1->right->data;
            }
        }
        if(largest!= node1->data){
            if(k==1){
                swap(node1->data,node1->left->data);
                if(node1->left->left!=NULL){
                    Max_Heapify(node1->left);
                }
            }
            else if(k==0) {
                swap(node1->data,node1->right->data);
                if(node1->left->right!=NULL){
                        Max_Heapify(node1->right);
                }
            }
            else return 0 ;
        }
    }}
//------------------------------------Max-Heap conversion-------------------------------
    vector<node *> Max_Heap(vector<node *> A){
         for(int i=A.size()/2;i>=0;i--){
                    Max_Heapify(A[i]);
               }
        return A;
    }
//------------------------------------Heap Sorting----------------------------------

vector<int> Heap_Sort(vector<node *> vec_node){
    vector<int> sorted;
    int i;
    for(i=vec_node.size()-1;i>0;i--){
        swap(vec_node[0]->data,vec_node[i]->data);
        sorted.push_back(vec_node[i]->data);
        vec_node[i]->data=0;
        Max_Heapify(vec_node[0]);
    }
    sorted.push_back(vec_node[0]->data);
    return sorted;
    }
//------------------------------------preorder traversal--------------------------------
    int preorder(node *root){
        if(root!=NULL){
            cout<<root->data<<endl;
            if(root->left!=NULL){preorder(root->left);}
            if(root->right!=NULL){preorder(root->right);}

        }
        else{cout<<"Tree is NULL"<<endl;return 0;}
    }

};
int main(){
    Binary_tree bt;
     vector <node *> vec_node;
     vector<int>vec_data;
    int choice,k=1;
    while(k==1){
        cout<<"1. create binary tree."<<endl;
        cout<<"2. Convert binary tree to Max Heap."<<endl;
        cout<<"3. Display preorder of tree."<<endl;
        cout<<"4. Display Level Order of tree."<<endl;
        cout<<"5. Height/Size of the tree."<<endl;
        cout<<"6. Sort Heap."<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                int n,node;
                cout<<"Enter number of nodes you want to insert: ";
                cin>>n;
                cout<<"Enter values of nodes."<<endl;
                while(n--){
                    cin>>node;
                    bt.Insert_Elem(node);
                }
                break;
            case 2:
               vec_node = bt.level_travel();
                bt.Max_Heap(vec_node);
                break;
            case 3:
                cout<<"Preorder treversal...."<<endl;
                bt.preorder(root);
                break;
            case 4:
                cout<<"Level order traversal."<<endl;
                vec_data = bt.data_vec();
                for(int i=0;i<vec_data.size();i++){cout<<vec_data[i]<<endl;}
                break;
            case 5:
                vec_data = bt.data_vec();
                cout<<"Height: "<<int(log2(vec_data.size()))<<endl;
                break;

            case 6:
                vec_node = bt.Max_Heap(bt.level_travel());
                vector<int>sorted;
                sorted = bt.Heap_Sort(vec_node);
                for(int i=sorted.size()-1;i>=0;i--){cout<<sorted[i]<<endl;}
                break;
        }
    }
}
