#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[],int size)
{
    cout << "Here is the sorted array";
    for (int n= 0; n < size; n++){
        cout<<arr[n]<<" ";
    }
}

int main()
{
    cout << "Enter array size : ";
    int size;
    cin >> size;
    int arr[size];
    for (int n = 0; n < size; n++)
    {
        cout << "Enter Value " << n + 1 << " : ";
        cin >> arr[n];
    }

    cout << "Select Choice" << endl;
    cout << "Press 1 for ascending sorting" << endl;
    cout << "Press 1 for descending sorting" << endl;
    int ch;
    cin >> ch;
    if (ch == 1)
    {
        sort(arr, arr + size);
        printArray(arr,size);
    }
    else if (ch == 2)
    {
        sort(arr, arr + size, greater<int>());
        printArray(arr,size);
    }
    else
    {
        cout<<"Invaid Choice"<<endl;
    }
}