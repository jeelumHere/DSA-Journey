// Implement 3 different function to delete from start, end or in between the circular linked list. Call
// the functions in the main and display the circular linked list after each deletion

#include<iostream>
using namespace std;

struct node{
    float data;
    node* next;
};

node* start = NULL;
node* tail;

void delete_top(){
    if(start==NULL || tail==NULL ){
        cout<<"There are no nodes in linked list."<<endl;
    }
    else{
        node *temp = start->next;
        delete start;
        start = temp;
        tail->next = temp;
        if(temp==NULL)
        tail = start = NULL;
    }
}

void delete_bottom(){
    node* temp = start;
    while(temp->next!=tail){
        temp = temp->next;
    }

    temp->next = start;
    delete tail;
    tail = temp;
    return;

}

void delete_middle(int delVal){
    if(start==NULL || tail==NULL){
        cout<<"Linked List has no nodes"<<endl;
    }
    else{
        if(start->data==delVal) delete_top();
        else if(tail->data==delVal) delete_bottom();
        else{
            node* temp = start;
            while(temp->next->data!=delVal){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            delete temp->next;
        }
        
    }
}

void myInsertAtTop(){
    if(start==NULL){
        start = new node;
        start->next = NULL;
        cout<<"Enter Node Data : ";cin>>start->data;
        tail = start;
    }
    else{
        node* newNode = new node;
        newNode->next = start;
        cout<<"Enter Node Data : ";cin>>newNode->data;
        start = newNode;
        tail->next = start;
    }
}

void myPrintList(){
    node* temp = start;
    if(start==NULL){
        cout<<"No Nodes Present."<<endl;
    }
    else{
        while(temp->next!=start){
            cout<<"Data : "<<temp->data<<endl;
            temp = temp->next;
        }
        cout<<"Data : "<<temp->data<<endl;
        cout<<"Data : "<<start->data<<endl;
        cout<<"The circle of Nodes is completed"<<endl;
    }
    return;
}

int main(){
    do{
        cout<<"Press 1 to insert at front in circular linked list"<<endl;
        cout<<"Press 2 to delete at front in circular linked list"<<endl;
        cout<<"Press 3 to delete at bottom in circular linked list"<<endl;
        cout<<"Press 4 to delete at middle in circular linked list"<<endl;
        cout<<"Press 5 to see th data"<<endl;
        cout<<"Enter Choice: ";
        int ch;cin>>ch;
        switch(ch){
            case 1: myInsertAtTop();
            break;

            case 2: delete_top();
            break;

            case 3: delete_bottom();
            break;
            case 4:
            cout<<"Enter nodes data of deleting node: ";
            int val;cin>>val; 
            delete_middle(val);
            break;

            case 5: myPrintList();
            break;

            default : cout<<"Invalid Choice"<<endl;
        }
    }
    while(true);
}