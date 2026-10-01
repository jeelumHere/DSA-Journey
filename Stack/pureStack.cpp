#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s1;
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
            s1.push1(val);
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