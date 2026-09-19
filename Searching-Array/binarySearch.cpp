#include <iostream>
using namespace std;

int binarySearch(int arr[],int size,int value)
{
    int s = 0;
    int e = size;
    // here is how binary search is working
    // [1,2,3,4,5,6,7,8,9,10]
    // 
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == value)
        {
            return mid;
        }

        else if (arr[mid] > value)
        {
            s = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int size;
    cout << "Enter array size : ";
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

    cout << "Value is at index : " << binarySearch(arr, size, value) << endl;
}
