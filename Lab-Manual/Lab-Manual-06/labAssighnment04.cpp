//  Implement a function void printreverse()to display the doubly linked list in reverse order.
// Call the function in the main method to display the list in reverse order.
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

    void print_reversed_list(){
        if(head==NULL){
            cout<<"No nodes are present in linked list"<<endl;
            return;
        }

        cout<<"<<<<<<<<<<----------Reversed List--------->>>>>>>>>>>>>"<<endl;
        
        Node* temp = tail;
        while(temp!=NULL){
            cout<<"Data : "<<temp->data<<endl;
            temp = temp->prev;
        }
        return;
    }
};


int main(){
    DoubleList ll;
    while(true){
        cout<<"Press 1 to insert data "<<endl;
        cout<<"Press 2 to print reverse list "<<endl;
        cout<<"Enter Choice : ";
        int ch;cin>>ch;

        switch(ch){
            case 1: ll.insert_front(); break;
            case 2: ll.print_reversed_list(); break;
            default: cout<<"Invalid choice"<<endl;
        }
    }
}