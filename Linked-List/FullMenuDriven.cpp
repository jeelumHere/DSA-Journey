#include <iostream>
using namespace std;

class Node
{
public:
    int data;
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

    void deleteSpecificNode(int key)
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

        while (temp->next->data != key)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "Key Not found.Enter a valid data to delete" << endl;
                return;
            }
        }

        temp->next = temp->next->next;
        temp = temp->next;
        delete temp;
        cout << "<<<<<<<<<<<---------Deleted Succussfully--------->>>>>>>>>>>>>" << endl;
    }

    void searchNode(int key)
    {
        Node *temp = head;
        int pos = 0;
        while (temp != NULL)
        {
            pos++;
            if (temp->data == key)
            {
                cout << "Address : " << temp << endl;
                cout << "Value : " << key << endl;
                cout << "Value is present at position " << pos << " in linked list" << endl;
            }
            temp = temp->next;
        }
    }

    void countNodes()
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (count == 0)
            cout << "No Nodes present.The Linked List is empty" << endl;
        else
            cout << "Total Nodes:  " << count << endl;
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

    void insertAfterNode(int key, int val)
    {
        if (head == NULL)
        {
            cout << "The linked list is empty" << endl;
            return;
        }

        // Case 1: Key is at the tail, reuse insertBack to maintain tail pointer
        if (tail->data == key)
        {
            insertBack(val);
            return;
        }

        // Case 2: Search for the key safely
        Node *temp = head;
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }

        // If we reached the end and didn't find the key
        if (temp == NULL)
        {
            cout << "Invalid data.\nEnter correct nodes data to insert right after that node" << endl;
            return;
        }

        // Case 3: Insert the new node right after temp
        Node *newNode = new Node(val);
        newNode->next = temp->next; // Point new node to temp's next node
        temp->next = newNode;       // Link temp to the new node

        cout << "Inserted Successfully" << endl;
    }

    void insertBeforeNode(int key, int val)
    {
        if (head == NULL)
        {
            cout << "Invalid Input.\nLinked List is empty." << endl;
            return;
        }
        if (head->data == key)
        {
            insertFront(val);
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->next->data != key)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "No node has matched for your input data." << endl;
            return;
        }
        Node *newNode = new Node(val); // craeted that new node
        newNode->next = temp->next;    // add address of before node to newnode
        temp->next = newNode;          // add address of newNode to it's previous node
        return;
    }
};
    int main()
    {
        int val;
        LinkedList List01;

        int afterNode;
        int beforeNode;
        int node;
        do
        {
            cout << "\nPress 1 to insert at front in linked List" << endl;
            cout << "Press 2 to insert at bottom in linked List" << endl;
            cout << "Press 3 to delete at front in linked List" << endl;
            cout << "Press 4 to delete at back in linked List" << endl;
            cout << "Press 5 to delete Specific node" << endl;
            cout << "Press 6 to display linked list" << endl;
            cout << "Press 7 to search a node" << endl;
            cout << "Press 8 to count nodes" << endl;
            cout << "Press 9 to insert after node" << endl;
            cout << "Press 10 to insert before node" << endl;
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

            case 5:
                int key;
                cout << "Enter data of the node youwantto delete: ";
                cin >> key;
                List01.deleteSpecificNode(key);
                break;

            case 6:
                List01.displayList();
                break;

            case 7:
                int sNode;
                cout << "Enter nodes data you want to search: ";
                cin >> sNode;
                List01.searchNode(sNode);
                break;

            case 8:
                List01.countNodes();
                break;
            case 9:
                cout << "Enter the node data where you want the new node to come after: ";
                cin >> afterNode;
                cout << "Enter the node data : ";
                cin >> node;
                List01.insertAfterNode(afterNode, node);
                break;
            case 10:
                cout << "Enter the node data where you want the new node to come before: ";
                cin >> beforeNode;
                cout << "Enter the node data : ";
                cin >> node;
                List01.insertBeforeNode(beforeNode,node);
                break;
            default:
                cout << "Invalid choice";
            }
        } 
        while (true);
    }
