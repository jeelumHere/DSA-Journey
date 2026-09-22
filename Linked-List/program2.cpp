#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
    Node *head, *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    void pushFront(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode; // this is for the NULL case
        }
        else
        {
            newNode->next = head;
            head = newNode;
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
        }
    }

    void printLinkedList()
    {
        Node *temp = head;
        int n = 0;
        while (temp != NULL)
        {
            n++;
            cout << "Value "<<n<< " : "<<temp->data<<endl;
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList ll;
    ll.pushFront(0);
    ll.pushFront(1);
    ll.pushFront(10);
    ll.pushBack(20);
    ll.printLinkedList();
}