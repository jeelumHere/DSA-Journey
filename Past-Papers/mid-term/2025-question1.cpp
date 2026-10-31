#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    int id;
    string name;
    Node* next;

    Node(int i,string n){
        id = i;
        name = n;
        next = NULL;
    }
};

class LinkedList{
    Node *head,*tail;

    public: 
    LinkedList(){
        head = tail = NULL;
    }

    void add_patient(){
        // adding patient at the end of list
        cout<<"Enter paient name: ";
        string name;
        cin>>name;
        cout<<"Enter patient id: ";
        int id;
        cin>>id;

        Node* newNode = new Node(id,name);
        if(head==NULL || tail==NULL){
            head = tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void remove_patient(){
        // removing the front on list patient first
        if(head==NULL || tail==NULL){
            cout<<"There are no patient in the list"<<endl;
            return;
        }
        else if(head==tail){
            cout<<"<<<<<<<<<<---------Patient Removed Details--------->>>>>>>>>"<<endl;
            cout<<"Id   :  "<<head->id<<endl;
            cout<<"Name :  "<<head->name<<endl;
            delete head,tail;
            head = tail = NULL;
            return;
        }
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
    }

    void patient_list(){
        if(head==NULL || tail==NULL){
            cout<<"There are no patient in the list"<<endl;
            return;
        }
        else if(head==tail){
            cout<<"<<<<<<<<<<---------Patient Removed Details--------->>>>>>>>>"<<endl;
            cout<<"Id   :  "<<head->id<<endl;
            cout<<"Name :  "<<head->name<<endl;
            return;
        }
        else{
            Node* temp = head;
            while(temp!=NULL){
                cout<<"id: "<<temp->id<<"   Name:   "<<temp->name<<endl;
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    LinkedList list;
    do{
        cout<<"Press 1 to add patient"<<endl;
        cout<<"Press 2 to remove patient"<<endl;
        cout<<"Press 3 to see patient list"<<endl;
        cout<<"Enter choice: ";
        int ch;
        cin>>ch;
        switch(ch){
            case 1: list.add_patient(); break;

            case 2: list.remove_patient(); break;

            case 3: list.patient_list(); break;

            default: cout<<"Invalid choice"<<endl;
        }
    }
    while(true);
}