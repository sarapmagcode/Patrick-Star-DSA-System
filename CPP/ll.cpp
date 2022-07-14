#include <iostream>
using namespace std;

struct Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        head = n;
    }

    // Checker if node exist
    Node *nodeExists(int k)
    {
        Node *temp = NULL;

        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // Append a node to the list
    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "\nNode already exist. Choose different key value to append" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended!!" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node Appended!!" << endl;
            }
        }
    }
    // Delete Data of a Node
    void deleteNode(int k)
    {
        if (head == NULL)
        {
            cout << "\nLinked List already Empty. Nothing to delete" << endl;
        }
        else if (head != NULL)
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node with element of '" << k << "' has been deleted!!!" << endl;
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout << "\nNode has been Deleted with an element of  : " << k << endl;
                }
                else
                {
                    cout << "\nNode Doesn't exist with an element of : " << k << endl;
                }
            }
        }
    }

    // Delete Node at Given Position
    void deleteNodeGivenPosition(int d)
    {
        if (head == NULL)
        {
            cout << "\nLinked List already Empty. Nothing to delete" << endl;
        }
        else if (head != NULL)
        {
            if (head->data == d)
            {
                head = head->next;
                cout << "Node with position of '" << d << "' has been deleted" << endl;
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->data == d)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout << "\nNode Deleted with a position of  : " << d << endl;
                }
                else
                {
                    cout << "\nNode Doesn't exist with a position of : " << d << endl;
                }
            }
        }
    }

    // Display the Node List
    void printList()
    {
        if (head == NULL)
        {
            cout << "\nNo Node in the List!! Append Node to display nodes in the list";
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "[" << temp->key << "," << temp->data << "]"
                     << " -- ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "\n\n---------LINKED LIST MENU---------" << endl;
        cout << "\n1. Append Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Delete Node At Given Position" << endl;
        cout << "4. Display" << endl;
        cout << "5. Go Back" << endl;
        cout << "----------------------------------" << endl;
        cout << "\nEnter your choice here : ";
        cin >> option;
        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "\n----Append Node Operation----\nEnter the data value and position : ";
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);

            break;
        case 2:
            cout << "\nDelete Node with an Element of : ";
            cin >> k1;
            s.deleteNode(k1);
            break;

        case 3:
            cout << "\nDelete Node at Given Position of : ";
            cin >> k1;
            s.deleteNodeGivenPosition(k1);
            break;

        case 4:
            cout << "\nCurrent Nodes in the List : ";
            s.printList();
            break;

        case 5:
            system("cls");
            break;
        default:
            cout << "\nInvalid Input " << endl;
        }

    } while (option != 0);
    return 0;
};