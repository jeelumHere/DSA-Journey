#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList{
    Node *head;
    Node *tail;

public:
    LiinkedList()
    {
        head = tail = NULL;
    }

    void pushFront(int val){
        Node* newNode = new Node(val); //dynamic
        if(head==NULL){
            head= tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void printLL(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkedList ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushFront(4);
    ll.pushFront(5);
    ll.printLL();
}