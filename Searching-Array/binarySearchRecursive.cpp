#include<iostream>
#include<algorithm>
using namespace std;

int binarySearchRecursive(int arr[],int s,int e,int value){
    if(s>e)
    return -1;

    int mid = (s+e)/2;
    if(arr[mid]==value)
    return mid;
    else if(arr[mid]>value)
    return binarySearchRecursive(arr,s,mid-1,value);
    else
    return binarySearchRecursive(arr,mid+1,e,value);
}

int main(){
    cout<<"Enter Aray size : ";
    int size;int value;cin>>size;
    int arr[size];
    for(int n=0;n<size;n++){
        cout<<"Enter Value "<<n+1<<" : ";
        cin>>arr[n];
    }

    sort(arr,arr+size);

    cout<<"Enter value to search : ";
    cin>>value;
    cout<<"Valuefound at index "<<binarySearchRecursive(arr,0,size-1,value)<<endl;
}