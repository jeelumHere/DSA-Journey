// Dynamic Stack
// Flexible size
// Usually uses linked list
// Memory allocated when needed
// Overflows only when memory is exhausted
// Better memory utilization

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node * prev;

    Node(){
        cout<<"Enter Nod's data";
        cin>>data;
        next = NULL;
        prev = NULL;
    }
};

class dynamicStack{
    Node *head,*tail;

    public:
    dynamicStack(){
        head = tail = NULL;
    }

    void push(){
        Node* newNode = new Node();
        if(head==NULL || tail==NULL){
            head =  tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop(){
        if(head==NULL || tail==NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else if(head==tail){
            cout<<"Top popped: "<<head->data<<endl;
            delete head;
            head = tail = NULL;
            return;
        }
        else{
            cout<<"Top popped: "<<tail->data<<endl;
            Node* temp = tail;
            tail = tail->prev;
            delete temp;
            return;
        }
    }

    void peek(){
        if(head==NULL || tail==NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<"Top value: "<<tail->data<<endl;
        return;
    }

    void print(){
        if(head==NULL || tail==NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else if(head==tail){
            cout<<"Top popped: "<<head->data<<endl;
            return;
        }
        else{
            Node* temp = tail;
            while(temp!=NULL){
                cout<<temp->data<<"  ";
                temp = temp->prev;
            }
            cout<<endl;
        }
    }
};

int main(){
    dynamicStack ds;
    while(true){
        cout<<"Press 1 to push"<<endl;
        cout<<"Press 2 to pop"<<endl;
        cout<<"Press 3 to peek"<<endl;
        cout<<"Press 4 to print"<<endl;
        int ch;
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch){
            case 1: ds.push(); break;

            case 2: ds.pop(); break;

            case 3: ds.peek(); break; 
            
            case 4: ds.print(); break;

            default:  cout<<"Invalid choice"<<endl;
        }
    }
}