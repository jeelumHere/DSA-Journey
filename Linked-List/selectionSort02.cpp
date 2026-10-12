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
    Node *head ,*tail;
    public : 
    LinkedList(){
        head = tail = NULL;
    }


    void insert_front(){
    cout<<"Enter value you want to insert : ";
    int val;cin>>val;
    Node* newNode = new Node(val);

    if(head==NULL){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    return;
}

    void print_list(){
    if(head==NULL){
        cout<<"No nodes are present in linked list"<<endl;
    }
    else{
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp= temp->next; 
        }
    }
    return;
}

// selection sort has a big O notation of n squre O(n2)
// it uses two while loop 1 on curr and other on temp
// it constantly compares the temo node and minNode to get the minimumnode data

void selectionSort(){
    if(head==NULL){
        cout<<"No nodes are present in the list"<<endl;
        return;
    }

    Node* curr = head;
    Node *minNode,*temp;
    while(curr!=NULL){
        minNode = curr;
        temp = curr->next;
        while(temp!=NULL){
            if(minNode->data > temp->data){
                minNode = temp;
            }
            temp = temp->next;
        }
        // swapping
        swap(curr->data, minNode->data);
        curr = curr->next;
    }
}
};

int main(){
    LinkedList ll;
    do{
        cout<<"Press 1 to insert node"<<endl;
        cout<<"Press 2 to see list"<<endl;
        cout<<"Press 3 to sort list"<<endl;
        cout<<"Enter Choice: ";
        int ch; cin>>ch;
        switch(ch){
            case 1: ll.insert_front(); break;
            
            case 2: ll.print_list(); break;
            
            case 3: ll.selectionSort(); break;

            default:cout<<"Invalid Choice"<<endl;
        }
    }
    while(true);
}