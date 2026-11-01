// Static Stack
// Fixed size	
// Uses array	
// Memory allocated beforehand	
// Can overflow when full	
// May waste memory
#include<iostream>
using namespace std;

int size;
class StaticStack{
    int top = -1;
    int *arr;

    public:
    StaticStack(){
        cout<<"Enter stack size: ";
        cin>>size;
        arr = new int[size];
    }
    
    void push(){
        if(top>=size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        cout<<"Enter value: ";
        int val;
        cin>>val;
        arr[++top] = val;
        return;
    }

    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<"Value popped: "<<arr[top]<<endl;
        top--;
    }

    void stack_size(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return;
        }
        else if(top==size-1){
            cout<<"Stack is full with it's size: "<<size<<endl;
        }
        else{
            cout<<"Stack current size is: "<<top+1<<endl;
        }
        return;
    }

    void peek(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return;
        }
        cout<<"Stack front: "<<arr[top]<<endl;
        return;
    }

    void print(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return;
        }
        for(int n=0; n<=top; n++){
            cout<<arr[n]<<"  ";
        }
        cout<<endl;
    }
};

int main(){
    StaticStack ss;
    while(true){
        cout<<"Press 1 to push"<<endl;
        cout<<"Press 2 to pop"<<endl;
        cout<<"Press 3 to peek"<<endl;
        cout<<"Press 4 to print"<<endl;
        cout<<"Press 5 to check size"<<endl;
        int ch;
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch){
            case 1: ss.push(); break;

            case 2: ss.pop(); break;

            case 3: ss.peek(); break; 
            
            case 4: ss.print(); break;

            case 5: ss.stack_size(); break;
            
            default:  cout<<"Invalid choice"<<endl;
        }
    }
}