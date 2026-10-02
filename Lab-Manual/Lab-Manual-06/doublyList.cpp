#include<iostream>
using namespace std;

class Node{
    public:

    double data;
    Node *next,*prev;

    Node(double val){
        data = val;
        next = prev = NULL;
    }
    
};

class LinkedList{
    Node *head,*tail;

    public : 
    LinkedList(){
        head = tail = NULL;
    }

    void insert_front(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insert_bottom(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        return;
    }

    void printList(){
        Node* temp = head;
        cout<<"<<<<<<<<<<<--------Straight Linked List---->>>>>>>>>>>>>>>>>"<<endl;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }

        cout<<"<<<<<<<<<<<--------Reversed Linked List---->>>>>>>>>>>>>>>>>"<<endl;
        temp = tail;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
    }
};

int main(){
    LinkedList ll;
    do{
        cout<<"\nPress 1 to insert at top "<<endl;
        cout<<"Press 2 to insert at top "<<endl;
        cout<<"Press 3 toprint linked list "<<endl;
        cout<<"Enter Choice: ";
        int ch;cin>>ch;
        switch(ch){
            case 1: cout<<"Enter Node Data: ";
            int val;cin>>val;
            ll.insert_front(val);
            break;

            case 2: 
            cout<<"Enter Node Data: ";
            cin>>val;
            ll.insert_bottom(val);
            case 3: ll.printList();
            break;

            default: cout<<"Invaid Choice"<<endl;
        }
    }
    while(true);
}