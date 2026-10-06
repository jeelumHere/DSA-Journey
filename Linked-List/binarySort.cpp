#include<iostream>
using namespace std;

class Node{
    public: 

    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;

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

void ascend_data(bool swapped){
     do
    {
        swapped = false;

        Node *curr = head;

        while(curr->next != NULL)
        {
            if(curr->data > curr->next->data)
            {
                int tempData = curr->data;
                curr->data = curr->next->data;
                curr->next->data = tempData;

                swapped = true;
            }

            curr = curr->next;
        }

    } while(swapped);
}

void descend_data(bool swapped){
     do
    {
        swapped = false;

        Node *curr = head;

        while(curr->next != NULL)
        {
            if(curr->data < curr->next->data)
            {
                int tempData = curr->data;
                curr->data = curr->next->data;
                curr->next->data = tempData;

                swapped = true;
            }

            curr = curr->next;
        }

    } while(swapped);
}

void bubble_sort(){
    if(head == NULL){
        cout<<"No nodes are present in the list"<<endl;
        return;
    }
    else{
        bool swapped;
        cout<<"Press 1 for small to big (ascending sorting)"<<endl;
        cout<<"Press 2 for big to small (descending sorting)"<<endl;
        cout<<"Enter Choice: ";
        int choice; cin>>choice;
        if(choice==1) ascend_data(swapped);
        else if(choice==2) descend_data(swapped);
        else return;
    }
}
 
int main(){
    while(true){
        cout<<"\nEnter 1 to insert data"<<endl;
        cout<<"Enter 2 to see list"<<endl;
        cout<<"Enter 3 to sort linked list"<<endl;
        int ch;
        cout<<"Enter choice: ";
        cin>>ch;
        switch(ch){
            case 1:insert_front(); break;
            
            case 2:print_list(); break;

            case 3:bubble_sort(); break;

            default:  cout<<"Inavlid Choice"<<endl;
        }
    }
}
