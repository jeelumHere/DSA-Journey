#include<iostream>
using namespace std;

class Node{
    public:

    Node* next;
    Node* prev;
    float data;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
    
};

class LinkedList{
    Node *head,*tail;

    public:
    LinkedList(){
        head = tail = NULL;
    }

    void insert_front(){
        cout<<"Enter Node's data: ";
        int val;
        cin>>val;
        Node* newNode = new Node(val);
        if(head==NULL || tail==NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            tail->next = newNode;
            newNode->prev = tail;
            head->prev = newNode;
            head = newNode;
        }
        return;
    }

    void insert_back(){
        cout<<"Enter node's data: ";
        int val;
        cin>>val;
        Node* newNode = new Node(val);
        if(head==NULL || tail==NULL){
            head = tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            return;
        }
    }

    void pop_front(){
        if(head==NULL || tail==NULL){
            cout<<"No Nodes are present"<<endl;
            return;
        }
        else if(head->next==NULL){
            delete head;
            delete tail;
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void search_list(){
        if(head==NULL || tail==NULL){
            cout<<"No Nodes are present"<<endl;
            return;
        }
        
        cout<<"Enter Node's data u want to search"<<endl;
        int val;
        cin>>val;
        if(head->data==val){
            cout<<"Node is found at head"<<endl;
            cout<<"Data    =>  "<<head->data<<endl;
            cout<<"Address =>  "<<head<<endl;
            return;
        }
        else{
            Node* temp = head->next;
            while(temp!=tail){
                if(temp->data==val){
                    cout<<"Node is found at head"<<endl;
                    cout<<"Data    =>  "<<temp->data<<endl;
                    cout<<"Address =>  "<<temp<<endl;
                    return;
                }
                temp = temp->next;
            }
        }
    }

    void sort_list(){
        if(head==NULL || tail==NULL){
            cout<<"No Nodes are present"<<endl;
            return;
        }
        else if(head==tail){
            cout<<"Only one node is present: "<<head->data<<endl;
            return;
        }
        Node* curr = head;
        while(curr!=NULL){
            Node* temp = curr->next;
            Node* minNode = curr;

            while(temp!=NULL){
                if(temp->data < minNode->data){
                    minNode = temp;
                }
                temp = temp->next;
            }

            // swapping
            int minData = curr->data;
            curr->data = minNode->data;
            minNode->data = minData;

            curr = curr->next;
        }
    }

    void print_list(){
        if(head==NULL){
            cout<<"No nodes are present"<<endl;
            return;
        }
        else if(head==tail){
            cout<<head->data<<endl;
            return;
        }
        else{
            cout<<"<<<<<<<----------Straight List------>>>>>>>>>>>>>>"<<endl;
            Node* temp = head;
            do{
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            while(temp!=tail);
            cout<<tail->data;
            cout<<"\n<<<<<<<<<<<<------------Reversed List----------->>>>>>>>>>>>>>>>"<<endl;
            temp = tail;
            do{
                cout<<temp->data<<" ";
                temp = temp->prev;
            }
            while(temp!=head);
            cout<<head->data;
            cout<<endl;
            return;
        }

    }
};

int main(){
    LinkedList ll;

    while(true){
        cout<<"Press 1 to insert at front"<<endl;
        cout<<"Press 2 to pop at front"<<endl;
        cout<<"Press 3 to print list"<<endl;
        cout<<"Press 4 to search list"<<endl;
        cout<<"Press 5 to sort list"<<endl;
        cout<<"Enter Choice: ";
        int ch;
        cin>>ch;
        switch(ch){
            case 1: ll.insert_front(); break;

            case 2: ll.pop_front(); break;

            case 3: ll.print_list(); break;
            
            case 4: ll.search_list(); break;

            case 5: ll.sort_list(); break;

            default: cout<<"Invalid Choice"<<endl;
        }
    }
}