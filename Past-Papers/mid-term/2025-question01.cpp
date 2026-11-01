// implement selection sort

#include<iostream>
using namespace std;

void selection_sort(int arr[], int size){
    for(int n=0; n<size; n++){
        int min = n;
        for(int j=n+1; j<size; j++){
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        // swapping
        int temp = arr[n];
        arr[n] = arr[min];
        arr[min] = temp;
    }
}

int main(){
    int arr[10] = {43,01,28,39,46,12,93,45,29,17};
    for(int n=0; n<10; n++){
        cout<<arr[n]<<" ";
    }
    cout<<endl;
    selection_sort(arr,10);

    for(int n=0; n<10; n++){
        cout<<arr[n]<<" ";
    }
    cout<<endl;
}