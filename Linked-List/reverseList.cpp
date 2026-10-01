// Reverse a linkded list
// we will have two more nodes current and prev
// we will initialize current with head
// we will initialize prev with null

// We perform 4 (four) steps to reverse a linked list
// 1) The next node points to the current nodes next
// 2) cur->next = prev;
// 3) prev = cur;
// 4) curr = next;
#include<iostream>
using namespace std;


class Node{
    public : 
    int data;
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

    void insert_front(int val){
        Node *newNode = new Node(val);
        if(head==NULL)
            head = tail = newNode;
        else{
            Node* temp;
            newNode->next = head;
            head = newNode;
        }
    }

    void showList(){
        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
    }

    void reverseList(){
        Node *prev,*next,*curr;
        curr = head;
        prev = NULL;
        next = NULL;

        if(head==NULL){
            cout<<"No nodes present in this linked list"<<endl;
            return;
        }
        else{
                while(curr!=NULL){
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
        }
        head = prev;
    }
};

int main(){
    LinkedList list01;
    list01.insert_front(30);
    list01.insert_front(20);
    list01.insert_front(10);
    list01.insert_front(1);
    cout<<"<<<<<<<<<<<-----------Linked List---------->>>>>>>>>>>>>"<<endl;
    list01.showList();
    cout<<"\n<<<<<<<<<<<-----------Reversed List---------->>>>>>>>>>>>>"<<endl;
    list01.reverseList();
    list01.showList();
}

// head = [data = 1, ptr=QWER1234]
// newNode->next = head;
// head = newNode;