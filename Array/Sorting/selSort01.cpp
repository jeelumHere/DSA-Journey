#include<iostream>
using namespace std;

void print_array(int size,int arr[]){
    cout<<"<<<<--------Printing Array------->>>>>>>>>>"<<endl;
    for(int n=0;n<size;n++){
        cout<<arr[n]<<" ";
    }
    cout<<endl;
}

void selection_sort(int size,int arr[]){
    for(int i=0; i<size-1; i++){
        int minIndex = i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main(){
    cout<<"Enter Array Size: ";
    int size; cin>>size;
    int arr[size];
    for(int n=0;n<size;n++){
        cout<<"Enter value "<<n+1<<" : ";
        cin>>arr[n];
    }

    while(true){
        cout<<"Press 1 to print array"<<endl;
        cout<<"Press 2 to sort array"<<endl;
        cout<<"Enter Choice: ";
        int ch;
        cin>>ch;

        if(ch==1)
        print_array(size,arr);
        else if(ch==2)
        selection_sort(size,arr);
        else
        cout<<"Invalid Choice"<<endl;
    }
}