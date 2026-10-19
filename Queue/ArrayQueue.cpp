#include<iostream>
using namespace std;

class Queue{
    int size;
    int end;
    int* arr;
    public : 
    Queue(){
        QueueSize();
    }
    void QueueSize(){
        cout<<"Enter Queue Size: ";
        cin>>size;
        arr = new int[size];
        end = -1;
    }

    void enqueue(){
        if(end>=size-1){
            cout<<"Queue is full"<<endl;
            return;
        }
        end++;
        cout<<"Enter Value you want to addin queue: ";
        cin>>arr[end];
    }

    int dequeue(){
        if(end==-1){
            cout<<"No value presend in Queue."<<endl;
            return 0;
        }
        int front = arr[0];
        end--;
        for(int n=0;n<=end;n++){
            arr[n] = arr[n+1];
        }
        return front;
    }

    int peek(){
        if(end==-1){
            cout<<"No value in queue"<<endl;
            return 0;
        }
        int front = arr[0];

        return arr[0];
    }

    bool isEmpty(){
        if(end==-1){
            return true;
        }
        else return false;
    }

    bool isFull(){
        if(end==size-1) return true;
        else return false;
    }

    int QSize(){
        return end;
    }
    
};

int main(){
    Queue q1;
    bool con = true;
    do{
        cout<<"Enter value 1 to push in queue"<<endl;
        cout<<"Enter value 2 to pop in queue"<<endl;
        cout<<"Enter value 3 to see first value in queue"<<endl;
        cout<<"Enter value 4 check if queue is empty"<<endl;
        cout<<"Enter value 5 check if queue is full"<<endl;
        cout<<"Enter value 6 check queue size"<<endl;
        cout<<"Enter 7 to exit"<<endl;
        int ch;
        cout<<"Enter Choice: ";cin>>ch;
        switch(ch){
            case 1: q1.enqueue(); cout<<endl; break;
            case 2: cout<<"Value: "<<q1.dequeue(); cout<<endl; break;
            case 3: cout<<"Value: "<<q1.peek(); cout<<endl; break;
            case 4: cout<<"is empty? "<<q1.isEmpty(); cout<<endl; break;
            case 5: cout<<"is full? "<<q1.isFull(); cout<<endl; break;
            case 6: cout<<"Size: "<<q1.QSize(); cout<<endl; break;
            case 7: con = false; cout<<"Program exits here"<<endl; break;
            default: cout<<"Invalid choice"<<endl;
        }
    }
    while(con);
    
}