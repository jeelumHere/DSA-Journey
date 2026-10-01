#include<iostream>
#include<list>
using namespace std;

class Stack{
    list<int> ll;
    public : 
    void push(int val){
        // Write function with complexity of Big O of 1 => O(1)    
        ll.push_front(val);
    }

    void pop(){
        // Write function with complexity of Big O of 1 => O(1)
        ll.pop_front();  
    }


    int top(){
        // Write function with complexity of Big O of 1 => O(1)
        return ll.front();    
    }

    bool empty(){
        // v.size()==0 ?   return true : return false;
        if(ll.size()==0)
        return true;
        else
        return false;
    }
};

int main(){
    Stack s1;
    do{
        cout<<"Press 1 to insert a value into stack: "<<endl;;
        cout<<"Press 2 to pop a value from stack: "<<endl;;
        cout<<"Press 3 for the top value: "<<endl;;
        cout<<"Press 4 to delete and see the whole stack: "<<endl;;
        cout<<"Enter choice: ";
        int ch;cin>>ch;
        if(ch==1){
            int val;
            cout<<"Enter value : ";
            cin>>val;
            s1.push(val);
            cout<<"<<<<<<<<<----------Value pushed-------->>>>>>>>>>>>>>"<<endl;
        }
        else if(ch==2){
            s1.pop();
            cout<<"<<<<<<<---------Value Poped--------->>>>>>>>>>>>"<<endl;
        }
        else if(ch==3){
            cout<<"Top Value : "<<s1.top()<<endl;
        }
        else if(ch==4){
            while(!s1.empty()){
                cout<<"Value : "<<s1.top()<<endl;
                s1.pop();
            }
        }
        else{
            cout<<"Invalid Choice"<<endl;
        }
    }
    while(true);
}