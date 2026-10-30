#include <iostream>
using namespace std;

class CircularQueue
{
    int cap, currSize, front, rear;
    int *arr;

public:
    CircularQueue()
    {
        cout << "Enter Queue capacity: ";
        cin >> cap;
        arr = new int[cap];
        currSize = 0;
        rear = -1;
        front = 0;
    }

    void enqueue()
    {
        if (currSize == cap)
        {
            cout << "Queue is full\n";
            return;
        }

        cout << "Enter value: ";
        int val;
        cin >> val;

        rear = (rear + 1) % cap;
        arr[rear] = val;
        currSize++;
    }

    void dequeue()
    {
        if (currSize == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front: " << arr[front] << endl;
        front = (front + 1) % cap;
        currSize--;
    }

    void printFront()
    {
        cout << "Front: " << arr[front] << endl;
    }
};

int main()
{
    CircularQueue cq;
    while (true)
    {
        cout << "Enter 1 to enqueue" << endl;
        cout << "Enter 2 to dequeue" << endl;
        cout << "Enter 3 to print front" << endl;
        cout << "Enter choice: ";
        int ch;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cq.enqueue();
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.printFront();
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}