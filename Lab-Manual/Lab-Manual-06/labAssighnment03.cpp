// Create a doubly linked list with 6 nodes. Print the doubly linked list. Use functions from examples
// in the lab manual. Make all function calls in the main method

#include<iostream>
using namespace std;


class Node{
    public :

    float data;
    Node *next,*prev;
    
    Node(float val){
        data = val;
        next = prev = NULL;
    }

};

class DoubleList{
    Node *head,*tail;

    public : 
    DoubleList(){
        head = tail = NULL;
    }

    void insert_front(){
        cout<<"Enter Nodes Data : ";
        int val;cin>>val;
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return;
    }

    void insert_back(){
        cout<<"Enter Nodes Data : ";
        int val;cin>>val;
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"The linked list is empty"<<endl;
            return;
        }
        else{
            if(head->next==NULL || tail->prev==NULL){
                delete head;
                head = tail = NULL;
                return;
            }
            Node *temp = head;
            temp = head->next;
            temp->prev  = NULL;
            delete head;
            head = temp;
            return;
        }
    }

    void pop_back(){
        if(head==NULL || tail==NULL){
            cout<<"No Nodes are present in thisdoublelinked list"<<endl;
            return;
        }
        if(head->next==NULL || tail->prev==NULL){
            delete head;
            delete tail;
            head = tail = NULL;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next!=tail){
                temp = temp->next;
            } 
            temp->next = NULL;
            delete tail;
            tail = temp;
            return;
        }
    }

    void print_list(){
        cout<<"<<<<<<<<---------Straight Linked List---------->>>>>>>>>>>>"<<endl;
        if(head==NULL){
            cout<<"No nodes are present in linked list"<<endl;
            return;
        }
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }

        cout<<"<<<<<<<<---------Reversed Linked List---------->>>>>>>>>>>>"<<endl;
        temp = tail;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
        return;
        }

};

int main(){
    DoubleList dl;
    do{
        cout<<"Press 1 to insert front node into double linked list: "<<endl;
        cout<<"Press 2 to insert back node into double linked list: "<<endl;
        cout<<"Press 3 to pop front node from double linked list: "<<endl;
        cout<<"Press 4 to pop back node from double linked list: "<<endl;
        cout<<"Press 5 to display list"<<endl;
        cout<<"Enter Choice : ";
        int ch;cin>>ch;
        switch(ch){
            case 1 : dl.insert_front(); break;

            case 2: dl.insert_back(); break;

            case 3: dl.pop_front(); break;

            case 4: dl.pop_back(); break;
            
            case 5: dl.print_list(); break;

            default : cout<<"Invalid Choice"<<endl;
        }
    }
    while(true);
}