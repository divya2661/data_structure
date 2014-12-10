#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    struct node *next;

} *start;

class link_list{
    public:
     node *create_node(int value)
    {
        struct node *temp, *s;
        temp = new(struct node);
        if (temp == NULL)
        {
            cout<<"Memory not allocated "<<endl;

        }
        else
        {
            temp->val = value;
            temp->next = NULL;
            return temp;
        }
    }

        void insert_pos(){
            int pos,value,counter=2;
            struct node *temp,*s,*ptr;
            cout<<"enter position to insert = ";
            cin>>pos;
            cout<<"enter value to insert= ";
            cin>>value;
            temp = create_node(value);
            s = start;
            while(s!=NULL){
                s = s->next;
                counter++;
            }
            if(pos==1){
                if(start==NULL){
                    start = temp;
                    temp->next = NULL;

                }
                else{
                    ptr = start;
                    start = temp;
                    temp->next = ptr;

                }

            }
            else if(pos>1 && pos<counter){
                ptr = start;int cnt=2;
                cout<<"pos=="<<pos<<endl;
                cout<<"cnt=="<<cnt<<endl;
                while(cnt<pos){
                    cout<<"while......"<<endl;
                    ptr = ptr->next;cnt++;
                }
                temp->next = ptr->next;
                ptr->next = temp;



            }
            else{cout<<"position is out of range. :P "<<endl;}

        }
        void delete_pos(){
            int pos,cnt=1,counter=2;
            node *s,*ptr;
            cout<<"enter position to delete.";
            cin>>pos;
            s = start;
            while(s!=NULL){
                s = s->next;
                counter++;
            }
            if(pos==1){
                if(s==NULL){cout<<"list is empty.";}
                else{
                    start = s->next;
                }


            }
            else if(pos>1 && pos<counter){
                s = start;
                while(cnt<pos){
                ptr = s;
                s = s->next;cnt++;
            }
                ptr->next  = s->next;
            }

            else {cout<<"position is out of range......"<<endl;}
            free(s);
            cout<<"element deleted....."<<endl;

        }
        void show(){
            node *ptr,*s;
            ptr = start;
            if(ptr == NULL){cout<<"list is empty."<<endl;}
            else{
                while(ptr!=NULL){
                    cout<<ptr->val<<endl;
                    ptr  = ptr->next;
                }
            }

        }


};

int main(){
    link_list list1;
    int choice,k=1;

    while(k==1){
        cout<<"------------------------------"<<endl;
        cout<<"1. insert element"<<endl;
        cout<<"2. delete element"<<endl;
        cout<<"3. show list"<<endl;
        cout<<"4. break."<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"enter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"inserting...."<<endl;
                list1.insert_pos();
                break;

            case 2:
                cout<<"deleting....."<<endl;
                list1.delete_pos();
                break;
            case 3:
                cout<<"current list."<<endl;
                list1.show();
                break;
            case 4:
                k=0;
                break;
        }

    }

}
