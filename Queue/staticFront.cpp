// Queue
//  1   =>  FIFO    => First In First Out 
//  2   =>  LILO    => Last In Last Out 
#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int size;
    int front;
    int rear = 0;

    public: 
    Queue(){
        cout<<"Enter Queue Size: ";
        cin>>size;
        arr = new int[size];
    }

    void enqueue(){
        if(rear>size-1){
            cout<<"<<<<<<<<<<------------OverFlow------>>>>>>>>>>>>"<<endl;
            return;
        }
        cout<<"Enter Queue Value: ";
        int val;
        cin>>arr[rear];
        if(rear==0){
            front = arr[0];
        }
        rear++;
    }

    void dequeue(){
        cout<<"Front Value: "<<front<<endl;
        for(int n=0;n<rear;n++){
            arr[n] = arr[n+1];
        }
        rear--;
        front = arr[0];
    }

    void display(){
        if(rear==0){
            cout<<"<<<<<<-------Underflow----->>>>>>>>>>"<<endl;
            return;
        }
        cout<<"<<<<---------Diplaying Queue------->>>>>>>>>>"<<endl;
        for(int n=0;n<rear;n++){
            cout<<arr[n]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue q1;
    while(true){
        cout<<"Enter 1 to enqueue"<<endl;
        cout<<"Enter 2 to dequeue"<<endl;
        cout<<"Enter 3 to display Queue"<<endl;
        cout<<"Enter Choice: ";
        int ch; 
        cin>>ch;

        switch(ch){
            case 1: q1.enqueue(); break;

            case 2: q1.dequeue(); break;

            case 3: q1.display(); break;
            
            default:  cout<<"Invalid Choice"<<endl;
        }
    }
}