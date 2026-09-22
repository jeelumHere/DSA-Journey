#include<iostream>
using namespace std;

class Node{
    public : 
    float data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
    Node *head,*tail;

    public : 
    LinkedList(){
        head = tail = NULL;
    }
    void pushFront(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
            return;
        }
    }

    void pushBack(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
            return;
        }
    }

    void printLinkedList(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    LinkedList List01;
    List01.pushFront(102);
    List01.pushFront(876);
    List01.pushFront(769);
    List01.pushFront(001);

    List01.pushBack(145);
    List01.pushBack(98);
    List01.pushBack(123);
    List01.pushBack(111);

    List01.printLinkedList();
}