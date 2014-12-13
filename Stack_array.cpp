#include<bits/stdc++.h>
#define size 100
using namespace std;
class stack1{
    int element[size];
    int top;
    public:
    stack1() {
        top = -1;
    }
    int isEmpty(){
        if(top == -1){return 1;}
        else return 0;
    }
    int isFull(){
        if(top == (size-1)){return 1;}
        else{return 0;}
    }
    int top_elem(){
        if(isEmpty()==1){cout<<"stack1 is empty. :( "<<endl;}
        else{
            return element[top];
        }
        return 0;
    }
    void push(int value){
        if(isFull()==1){cout<<"stack1 is full. :( "<<endl;}
        else{
                top++;
                element[top] = value;
        }

    }
    int pop(){
        if(isEmpty()==1){cout<<"stack1 is empty."<<endl;}
        else{
            int pop_elem =  element[top];
            top = top-1;
            return pop_elem;
        }
    }
    void display(){
        cout<<"current stack..."<<endl;
        for(int i=0;i<=top;i++){
            cout<<element[i]<<endl;
        }

    }
};
int main(){
    stack1 s;
    int choice,k=1;
    while(k==1){
        cout<<"----------------------------"<<endl;
        cout<<"1.push element"<<endl;
        cout<<"2.pop element"<<endl;
        cout<<"3.display stack element"<<endl;
        cout<<"4. get top element."<<endl;
        cout<<"5. Exit."<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                int elem;
                cout<<"enter valuse of element: ";
                cin>>elem;
                s.push(elem);
                cout<<"inserted....."<<endl;
                break;
             case 2:
                s.pop();
                cout<<"deleted...."<<endl;
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout<<"top element: "<<s.top_elem()<<endl;
                break;
            case 5:
                k=0;break;
        }

    }
return 0;
}
