#include<iostream>
using namespace std;

class Node{
    public:  
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList{
    Node* head;
    Node* tail;

    public : 
    LinkedList(){
        head = tail = NULL;
    }
    void insert_front(){
        cout<<"Enter Node's data: ";
        int val; cin>>val;
        Node* newNode = new Node(val);
        if(head==NULL || tail==NULL){
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
        cout<<"Enter Node's data: ";
        int val; cin>>val;
        Node* newNode = new Node(val);
        if(head==NULL || tail==NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        return;
    }


    void delete_all(){
        if(head==NULL || tail==NULL){
            cout<<"No nodes available"<<endl;
            return;
        }
        Node* temp = head;
        while(temp!=NULL){
            Node* newTemp = temp->next;
            delete temp;
            temp = newTemp;
        }
        if(temp!=NULL){
            delete temp;
        }
        head = tail = NULL;
        return;
    }

    void print_List(){
        if(head==NULL || tail==NULL){
            cout<<"No Node's available"<<endl;
            return;
        }
        Node* temp = head;
        cout<<"<<<<--------Displaying Linked List--------->>>>>>>>"<<endl;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void print_reverse(){
        if(head==NULL || tail==NULL){
            cout<<"No Node's available"<<endl;
            return;
        }
        Node* temp = tail;
        cout<<"<<<<--------Displaying Reversed Linked List--------->>>>>>>>"<<endl;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
        cout<<endl;
    }

    void selection_sort(){
        if(head==NULL || tail==NULL)
        {
            cout<<"No Node's are present"<<endl;
            return;
        }
        Node* curr = head;
        while(curr!=NULL){
            Node* temp = curr->next;
            Node* minNode = curr;
            while(temp!=NULL){
                if(temp->data<minNode->data){
                    minNode = temp;
                }
                temp = temp->next;
            }

            // swapping
            int tempData = curr->data;
            curr->data = minNode->data;
            minNode->data = tempData;

            curr = curr->next;
        }
    }

    
};

int main(){
    LinkedList ll;
    while(true){
        cout<<"Press 1 to insert at front"<<endl;
        cout<<"Press 2 to print list"<<endl;
        cout<<"Press 3 to print reverse list"<<endl;
        cout<<"Press 4 to print delete all list"<<endl;
        cout<<"Press 5 to sort the list"<<endl;
        cout<<"Enter Choice: ";
        int ch; cin>>ch;
        switch(ch){
            case 1: ll.insert_front();
            break;

            case 2: ll.print_List();
            break;
            case 3: ll.print_reverse();
            break;
            case 4: ll.delete_all();
            break;
            case 5: ll.selection_sort();
            break;
            default: cout<<"Invalid CHoice"<<endl;
        }
    }
}
