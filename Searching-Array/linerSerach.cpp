#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int value)
{
    cout << "Linear search started..." << endl;

    for (int n = 0; n < size; n++)
    {
        if (value == arr[n])
        {
            return n;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter Array Size : ";
    cin >> size;

    int arr[size];

    for (int n = 0; n < size; n++)
    {
        cout << "Enter value " << n + 1 << " : ";
        cin >> arr[n];
    }

    cout << "Enter value you want to search : ";
    int value;
    cin >> value;

    cout << "Key present at index : " << linearSearch(arr, size, value);
}