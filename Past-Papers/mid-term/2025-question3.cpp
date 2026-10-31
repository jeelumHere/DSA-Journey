#include<iostream>
using namespace std;

int binary_search(int arr[],int size, int tar_id){
    int s = 0;
    int e = size - 1;

    while(s <= e){
        int mid = (s+e)/2;
        if(arr[mid]==tar_id){
            return tar_id;
        }
        else if(arr[mid]>tar_id){
            e = e - 1;
        }
        else{
            s = s + 1;
        }
    }
    return -1;
}

int main(){
    
    int arr[10]={1,2,3,4,5,6,7,8,9,10};

    while(true){
        cout<<"Press 1 to search book id: ";
        cout<<"Enter choice: ";
        int ch;cin>>ch;
        if(ch==1){
            cout<<"Enter Targeted book id to search: ";
            int id; cin>>id;
            cout<<"Book Id:"<<binary_search(arr,10,id);
        }
        else{
            cout<<"Invalid choice"<<endl;
        }
    }
}