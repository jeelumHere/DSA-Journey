// Create a circularly linked list with 6 nodes. Print the circularly linked list. Use functionfrom
// examples in the lab manual. Make all function calls in the main method.

// LAB 6:
// INTRODUCTION TO CIRCULAR AND DOUBLY LINKED LISTS

#include<iostream>
using namespace std;

struct node{
    float data;
    node* next;
};

node* start = NULL;
node* tail;

void insertAtTop(){
    if(start==NULL){
        start = new node;
        cout<<"Enter Data into Node: ";
        cin>>start->data;
        start->next = NULL;
        tail = start;
    }
    else{
        tail->next = new node;
        tail = tail->next;
        cout<<"Enter Data into Node: ";
        cin>>tail->data;
        tail->next = start;
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

void printList(){
    tail = start;
    cout<<"Data is: "<<tail->data<<endl;
    tail = tail->next;
    while(tail!=start){
        cout<<"Data is: "<<tail->data<<endl;
        tail = tail->next;
    }
    cout<<"Data is: "<<tail->data<<endl;
    tail = tail->next;
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
        cout<<"Press 2 to see th data"<<endl;
        cout<<"Enter Choice: ";
        int ch;cin>>ch;
        switch(ch){
            case 1: myInsertAtTop();
            break;

            case 2: myPrintList();
            break;

            default : cout<<"Invalid Choice"<<endl;
        }
    }
    while(true);
}