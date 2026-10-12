#include <iostream>
#include <conio.h>
using namespace std;

int size;

void print(int arr[])
{
    for (int n = 0; n < size; n++)
    {
        cout << arr[n] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[]){
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    cout << "Enter Array Size: ";
    cin >> size;
    int arr[size];
    for (int n = 0; n < size; n++)
    {
        cout << "Enter value " << n + 1<<": ";
        cin >> arr[n];
    }

    cout << endl;

    while (true)
    {
        int ch;
        cout << "Press 1 to print array: "<<endl;
        cout << "Press 2 to sort array: "<<endl;
        cout<<"Choose option: ";cin >> ch;
        if (ch == 1)
            print(arr);
        else if(ch==2)
            selectionSort(arr);
        else
            cout << "invalid choice" << endl;
    }
}