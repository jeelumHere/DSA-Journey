#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Stack{
    Node *head,*tail;

    public : 
    Stack(){
        head = tail = NULL;
    }

    void push(){
        int val;
        cout<<"Enter data in stack: ";
        cin>>val;
        Node* newNode = new Node(val);
        if(head==NULL || tail==NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pop(){
        if(head==NULL || tail==NULL){
            cout<<"Stack uunderflow"<<endl;
            return;
        }
        cout<<"Value poped: "<<head->data<<endl;
        if(head->next==NULL){
            head = tail = NULL;
            return;
        }
        Node* temp = head->next;
        delete head;
        head = temp;
    }

    void top(){
        if(head==NULL || tail==NULL){
            cout<<"Stack uunderflow"<<endl;
            return;
        }
        cout<<"Stack top value: "<<head->data<<endl;
    }

    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        else return false;
    }
};


int main(){
    Stack st1;
    cout<<"<<<<<<<<<<<-----------Stack Implementation using linked list----------------------->>>>>>>>>>>>>>>>>>>"<<endl;
    do{
        cout<<"Press 1 to push value into stack"<<endl;
        cout<<"Press 2 to pop value from stack"<<endl;
        cout<<"Press 3 to get top value from stack"<<endl;
        cout<<"Press 4 to check if stack is empty"<<endl;
        int ch;
        cout<<"Enter choice: ";
        cin>>ch;
        switch(ch){
            case 1: st1.push(); break;
            case 2: st1.pop(); break;
            case 3: st1.top(); break;
            case 4: cout<<"Is Empty? "<<st1.isEmpty()<<" "<<endl; break;
            default : cout<<"Invalid Choice"<<endl;
        }
    }
    while(true);
}