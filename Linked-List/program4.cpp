#include <iostream>
using namespace std;

class Node
{
public:
    float data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
    Node *head, *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    void insertFront(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        return;
    }

    void insertBack(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = NULL;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFront()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "The linked list is empty" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            cout << "Deleted Successfully" << endl;
            return;
        }
        else
        {
            head = head->next;
            delete temp;
            cout << "Deleted Successfully" << endl;
        }
        return;
    }

    void deleteBack()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }

        // If there is only one node in the list
        if (head == tail)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            cout << "Deleted Successfully" << endl;
            return;
        }

        // Traverse to the second-to-last node
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        // Delete the tail node
        delete tail;
        tail = temp;
        tail->next = NULL;
        cout << "Deleted Successfully" << endl;
    }

    void displayList()
    {
        Node *temp = head;
        cout << "<<<<<<<<-------Displaying Linked List----------->>>>>>>>>>" << endl;
        if (head == NULL)
        {
            cout << "<<<<<<<----------Linked List is empty------------->>>>>>>>>>>>" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    int val;
    LinkedList List01;
    do
    {
        cout << "\nPress 1 to insert at front in linked List" << endl;
        cout << "Press 2 to insert at bottom in linked List" << endl;
        cout << "Press 3 to delete at front in linked List" << endl;
        cout << "Press 4 to delete at back in linked List" << endl;
        cout << "Press 6 to display linked list" << endl;
        int ch;
        cout << "Enter Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value to insert at front: ";
            cin >> val;
            List01.insertFront(val);
            break;

        case 2:
            cout << "Enter value to insert at back: ";
            cin >> val;
            List01.insertBack(val);
            break;

        case 3:
            List01.deleteFront();
            break;

        case 4:
            List01.deleteBack();
            break;

        case 6:
            List01.displayList();
            break;

        default:
            cout << "Invalid choice";
        }
    } while (true);
}