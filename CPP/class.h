// Header file for DSA

#ifndef CLASS_H
#define CLASS_H
#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void show_algorithms_menu();
void show_data_structures_menu();
void generate_menu_header(string title, vector < string>);

// Class for Array Data Structure
struct Array
{
	int size = 0;	// Array Global Variable Declaration
	int *arr = new int[size];
	int *arr_sorted = new int[size];
	bool created = false;	// Check if array is already created

	void arrayMenu()
	{
		system("clear");
		int choice;
		generate_menu_header("Array",
		{ "Create array", "Show original",
			"Show sorted", "Search element", "Go back" });
		while (true)
		{
			cout << "Enter choice: ";
			cin >> choice;
			switch (choice)
			{
				case 1:
					createArray();
					break;
				case 2:
					if (!created)
						cout << "Create an array first." << endl;
					else
						showOriginal();
					break;
				case 3:
					if (!created)
						cout << "Create an array first." << endl;
					else
						showSorted();
					break;
				case 4:
					if (!created)
						cout << "Create an array first." << endl;
					else
						findElement();
					break;
				case 5:
					{
						generate_menu_header("Data Structures",
						{ 				"Array", "Queue", "Linked List", "Binary Tree", "Graph Theory" });
						show_data_structures_menu();
						break;
					}
				default:
					cout << "Invalid. Please try again." << endl;
			}
		}
	}

	void createArray()
	{
		system("clear");
		cout << "Enter the size of the array: ";
		cin >> size;
		delete[] arr;
		arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cout << "Enter the no." << i + 1 << " element: ";
			cin >> arr[i];
		}

		created = true;

		cout << "\nArray successfully created.\n";
		system("read -p 'Press any key to continue... '");
		arrayMenu();
	}

	void showOriginal()
	{
		cout << "   ===== Original Array =====\n" << endl;
		cout << "\t[ ";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "]\n" << endl;
		system("read -p 'Press any key to continue... '");
		arrayMenu();
	}

	void sortArray(int arr_sorted[], int size)
	{
		int i, j, min, temp;
		for (i = 0; i < size - 1; i++)
		{
			min = i;
			for (j = i + 1; j < size; j++)
				if (arr_sorted[j] < arr_sorted[min]) min = j;
			temp = arr_sorted[i];
			arr_sorted[i] = arr_sorted[min];
			arr_sorted[min] = temp;
		}
	}

	void showSorted()
	{
		// Sort and copy array
		arr_sorted = new int[size];
		for (int i = 0; i < size; i++) arr_sorted[i] = arr[i];

		sortArray(arr_sorted, size);

		cout << "   ===== Sorted Array =====\n" << endl;
		cout << "\t[ ";

		for (int i = 0; i < size; i++)
		{
			cout << arr_sorted[i] << " ";
		}
		cout << "]\n" << endl;
		system("read -p 'Press any key to continue... '");
		arrayMenu();
	}

	void findElement()
	{
		int element;
		cout << "   ===== Find an element =====\n" << endl;
		cout << "Enter the element: ";
		cin >> element;

		cout << "Searching the element in the unsorted array..." << endl;
		for (int i = 0; i < size; i++)
		{
			if (element == arr[i])
			{
				cout << "The element " << element << " is at index[" << i << "]\n";
				break;
			}
			else if ((i + 1) == size && element != arr[i])
				cout << "The element is not in the array.\n";
			else
				continue;
		}

		cout << "Searching the element in the sorted array..." << endl;
		for (int i = 0; i < size; i++)
		{
			if (element == arr_sorted[i])
			{
				cout << "The element " << element << " is at index[" << i << "]\n";
				break;
			}
			else if ((i + 1) == size && element != arr_sorted[i])
				cout << "The element is not in the array.\n";
			else
				continue;
		}
		system("read -p 'Press any key to continue... '");
		arrayMenu();
	}
};

// Class for Queue Data Structure
struct Queue
{
	bool created = false;
	int size = 0;
	int *queue = new int[size];
	int front = -1;
	int rear = -1;
	int numItems = -1;
	vector<int> displayArray;
	void queueMenu()
	{
		system("clear");
		int choice;
		generate_menu_header("Queue",
		{ "Create queue", "Check if full", "Check if empty",
			"Enqueue/Insert", "Dequeue/Remove", "Get front/first element",
			"Get rear/last element", "Display", "Go back" });
		while (true)
		{
			cout << "Enter choice: ";
			cin >> choice;
			switch (choice)
			{
				case 1:
					createQueue();
					break;
				case 2:
					if (!created)
					{
						cout << "Create a queue first." << endl;
					}
					else
					{
						if (isFull())
						{
							cout << "The queue is full\n";
							cout << "Max queue size is " << size << endl;
						}
						else
						{
							cout << "The queue is NOT full\n";
							cout << "Max queue size is " << size << endl;
						}
					}
					break;
				case 3:
					if (!created)
						cout << "Create a queue first." << endl;
					else
					{
						if (checkEmpty())
						{
							cout << "The queue is empty\n";
						}
						else
						{
							cout << "The queue is NOT empty\n";
						}
					}
					break;
				case 4:
					if (!created)
						cout << "Create a queue first." << endl;
					else
						enqueue();
					break;
				case 5:
					if (!created)
						cout << "Create a queue first." << endl;
					else
						dequeue();
					break;
				case 6:
					if (!created)
						cout << "Create a queue first." << endl;
					else
						showFront();
					break;
				case 7:
					if (!created)
						cout << "Create a queue first." << endl;
					else
						showRear();
					break;
				case 8:
					if (!created)
						cout << "Create a queue first." << endl;
					else
						display();
					break;
				case 9:
					{
						generate_menu_header("Data Structures",
						{ 				"Array", "Queue", "Linked List", "Binary Tree", "Graph Theory" });
						show_data_structures_menu();
						break;
					}
				default:
					cout << "Invalid. Please try again." << endl;
			}
		}
	}

	void createQueue()
	{
		cout << "Enter the size of the queue: ";
		cin >> size;
		queue = new int[size];	// Load new size to queue
		int val;
		for (int i = 0; i < size; i++)
		{
			if (isFull())
			{
				cout << "The queue is now full.\n";
				cout << "Max queue size is " << size;
			}
			else
			{
				cout << "Enter the element to be pushed: ";
				cin >> val;
				rear = (rear + 1) % size;
				queue[rear] = val;
				numItems++;
			}
		}
		// implementation of vector for displaying the resized array
		vector<int> tempArray(queue, queue + size);
		displayArray.assign(tempArray.begin(), tempArray.end());

		created = true;
		system("clear");
		cout << "Queue successfully created.\n";
		system("read -p 'Press any key to continue... '");
		queueMenu();
	}

	bool checkEmpty()
	{
		bool status;
		if (numItems)
		{
			status = false;
		}
		else
		{
			status = true;
		}
		return status;
	}

	bool isFull()
	{
		bool status;
		if (numItems <= size)
		{
			status = false;
		}
		else
		{
			status = true;
		}
		return status;
	}

	void enqueue()
	{
		int val;
		if (isFull())
		{
			cout << "The queue is now full.\n";
		}
		else
		{
			cout << "Enter the element to be pushed: ";
			cin >> val;
			rear = (rear + 1) % size;
			queue[rear] = val;
			numItems++;
			displayArray.insert(displayArray.begin(), val);
		}
	}

	void dequeue()
	{
		if (checkEmpty())
		{
			cout << "The queue is empty.\n";
		}
		else
		{
			front = (front + 1) % size;
			numItems--;
			cout << "Popped front value" << endl;
			displayArray.pop_back();
		}
	}

	void showFront()
	{
		if (checkEmpty())
		{
			cout << "The queue is empty" << endl;
		}
		else
		{
			cout << "The front of the queue is the value: " << queue[numItems] <<
				endl;
		}
	}

	void showRear()
	{
		if (checkEmpty())
		{
			cout << "The queue is empty" << endl;
		}
		else
		{
			cout << "The rear of the queue is the value: " << queue[0] << endl;
		}
	}

	void display()
	{
		if (checkEmpty())
		{
			cout << "The queue is empty" << endl;
		}
		else
		{
			system("clear");
			cout << "===== Queue Elements =====" << endl;
			cout << "[ ";
			for (int i: displayArray)
			{
				cout << i << " ";
			}

			cout << "]\n" << endl;
			system("read -p 'Press any key to continue... '");
			queueMenu();
		}
	}
};

// Class for Stack Data Structure
struct Stack
{

	//Global variable declarations
	int size = 0;
	int *stackArray = new int[size];
	int top = -1;
	bool created = false;

	void stackMenu()
	{
		if (!created)
			askSize();

		system("clear");
		created = true;
		int choice;
		generate_menu_header("Stack",
		{ "Push", "Pop", "Peek", "Check if empty",
			"Display", "Go back" });

		while (true)
		{
			cout << "Enter choice: ";
			cin >> choice;
			switch (choice)
			{
				case 1:
					push();
					break;
				case 2:
					pop();
					break;
				case 3:
					peek();
					break;
				case 4:
					if (checkEmpty())
					{
						cout << "The stack is empty. \n";
					}
					else
					{
						cout << "The stack is not empty. \n";
					}
					break;
				case 5:
					display();
					break;
				case 6:
					generate_menu_header("Data Structures",
					{ 			"Array", "Queue", "Linked List", "Binary Tree", "Graph Theory" });
					show_data_structures_menu();
					break;
				default:
					cout << "Invalid. Please try again." << endl;
			}
		}
	}

	void askSize()
	{
		system("clear");
		cout << "Enter the size of the stack: ";
		cin >> size;
		stackArray = new int[size];
	}

	void push()
	{
		int val;

		if (checkFull())
		{
			cout << "The stack is full.\n";
		}
		else
		{
			cout << "Enter a value to push: ";
			cin >> val;
			top++;
			stackArray[top] = val;
			system("clear");
			cout << "Successfully pushed " << val << " to the stack." << endl;
			system("read -p 'Press any key to continue... '");
			stackMenu();
		}
	}

	void pop()
	{
		if (checkEmpty())
		{
			cout << "The stack is empty. \n";
		}
		else
		{
			system("clear");
			cout << "Successfully popped top value " << stackArray[top] << " from the stack." << endl;
			top--;
			system("read -p 'Press any key to continue... '");
			stackMenu();
		}
	}

	void peek()
	{
		if (checkEmpty())
		{
			cout << "The stack is empty. \n";
		}
		else
		{
			cout << "The top value of the stack is " << stackArray[top] << endl;
			system("read -p 'Press any key to continue... '");
			stackMenu();
		}
	}

	void display()
	{
		if (checkEmpty())
		{
			cout << "The stack is empty. \n";
		}
		else
		{
			system("clear");
			cout << "   ===== Stack Values =====\n" << endl;
			cout << "\t[ ";
			for (int i = 0; i <= top; i++)
			{

				cout << stackArray[i] << " ";
			}
			cout << "]\n" << endl;
			system("read -p 'Press any key to continue... '");
			stackMenu();
		}
	}

	bool checkEmpty()
	{
		bool status;
		if (top == -1)
		{
			status = true;
		}
		else
		{
			status = false;
		}
		return status;
	}

	bool checkFull()
	{
		bool status;
		if (top == size - 1)
		{
			status = true;
		}
		else
		{
			status = false;
		}
		return status;
	}
};

// Class for linked list
struct LinkedList{
	struct Node{
		int key;
		int data;
		Node *next;

		Node(){
			key = 0;
			data = 0;
			next = NULL;
		}
	};

	Node *head;

	LinkedList(){
		head = NULL;
	}

	LinkedList(Node *n){
		head = n;
	}
	Node *n1 = new Node();
	void linkedListMenu(){
		int choice, key1, k1, data1;
		generate_menu_header("Linked List",
		{ "Append Node", "Delete Node", "Delete Node at given position", "Display",
			"Go back" });

		while (true)
		{
			cout << "Enter choice: ";
			cin >> choice;
			switch (choice)
			{
				case 1:
					cout << "\n----Append Node Operation----\nEnter the data value and position : ";
					cin >> key1;
					cin >> data1;
					n1->key = key1;
					n1->data = data1;
					appendNode(n1);					
					break;
				case 2:
					cout << "\nDelete Node with an Element of : ";
					cin >> k1;
					deleteNode(k1);
					break;
				case 3:
					cout << "\nDelete Node at Given Position of : ";
					cin >> k1;
					deleteNodeGivenPosition(k1);
					break;
				case 4:
					cout << "\nCurrent Nodes in the List : ";
					printList();
					break;
				case 5:
					generate_menu_header("Data Structures",
					{ 			"Array", "Queue", "Linked List", "Binary Tree", "Graph Theory" });
					show_data_structures_menu();
					break;
				default:
					cout << "Invalid. Please try again." << endl;
			}
		}
	}
	

	Node *nodeExists(int k){
		Node *temp = NULL;
		Node *ptr = head;
		while (ptr != NULL){
			if(ptr->key == k){
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	}

	void appendNode(Node *n){
		if (nodeExists(n->key) != NULL){
			cout << "\nNode alreay exist. Choose different key value to append" << endl;
		}
		else{
			if(head == NULL){
				head = n;
				cout << "Node appended" << endl;
			}else{
				Node *ptr = head;
				while(ptr->next != NULL){
					ptr = ptr->next;
				}
				ptr->next = n;
				cout << "Node appended" << endl;
			}
		}
	}

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

    void printList()
    {
        if (head == NULL)
        {
            cout << "\nNo Node in the List!! Append Node to display nodes in the list\n";
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

// Class for Binary Search Tree
struct BinaryTree
{
	bool created = false;

	struct TreeNode
	{
		int value;
		TreeNode *left;
		TreeNode *right;
	};
	TreeNode *root;

	BinaryTree()
	{
		// Constructor for instantiating root
		root = NULL;
	}

	void binaryMenu()
	{
		// Generate data in nodes
		if (!created)
		{
			insertNode(5);
			insertNode(8);
			insertNode(3);
			insertNode(12);
			insertNode(9);
			insertNode(7);
			created = true;
		}
		system("clear");
		int choice;
		generate_menu_header("Binary Tree",
		{ "In order traversal", "Pre order traversal", "Post order traversal", "Go back" });

		while (true)
		{
			cout << "Enter choice: ";
			cin >> choice;
			switch (choice)
			{
				case 1:{
					cout << "=== Displaying with In Order traversal ===" << endl;
					cout << "[ ";
					displayInOrder(root);
					cout << " ]" << endl;
					break;					
				}
				case 2:{
					cout << "=== Displaying with Pre Order traversal ===" << endl;
					cout << "[ ";
					displayPreOrder(root);
					cout << " ]" << endl;
					break;
				}
				case 3:{
					cout << "=== Displaying with Post Order traversal ===" << endl;
					cout << "[ ";
					displayPostOrder(root);
					cout << " ]" << endl;
					break;					
				}
				case 4:
					generate_menu_header("Data Structures",
					{ 			"Array", "Queue", "Linked List", "Binary Tree", "Graph Theory" });
					show_data_structures_menu();
					break;
				default:
					cout << "Invalid. Please try again." << endl;
			}
		}
	}

	void insertNode(int val)
	{
		TreeNode *newNode, *nodePtr;
		newNode = new TreeNode;
		newNode->value = val;
		newNode->left = newNode->right = NULL;

		if (!root)
		{
			root = newNode;
		}
		else
		{

			nodePtr = root;
			while (nodePtr != NULL)
			{
				if (val < nodePtr->value)
				{
					if (nodePtr->left)
					{
						nodePtr = nodePtr->left;
					}
					else
					{
						nodePtr->left = newNode;
						break;
					}
				}
				else if (val > nodePtr->value)
				{
					if (nodePtr->right)
					{
						nodePtr = nodePtr->right;
					}
					else
					{
						nodePtr->right = newNode;
						break;
					}
				}
				else
				{
					cout << "Duplicate value found in tree.\n";
					break;
				}
			}
		}
	}

	void displayInOrder(TreeNode *nodePtr)
	{
		if (nodePtr)
		{
			displayInOrder(nodePtr->left);
			cout << nodePtr->value << " ";
			displayInOrder(nodePtr->right);
		}
	}

	void displayPreOrder(TreeNode *nodePtr)
	{
		if (nodePtr)
		{
			cout << nodePtr->value << " ";
			displayPreOrder(nodePtr->left);
			displayPreOrder(nodePtr->right);
		}
	}

	void displayPostOrder(TreeNode *nodePtr)
	{
		if (nodePtr)
		{
			displayPostOrder(nodePtr->left);
			displayPostOrder(nodePtr->right);
			cout << nodePtr->value << " ";
		}
	}
};

// Class for GraphTheory
struct GraphTheory
{
	int vertices;
	int u, v;
	int edges;
	vector<vector < int>> matrix;	// Dynamic Multidimensional Array
	vector<vector < int>> graph;
	bool created = false;

	void graphMenu()
	{
		// Generate data in nodes
		system("clear");
		int choice;
		generate_menu_header("Graph Theory",
		{ "Create graph", "Show adjacency list", "Show adjacency matrix", "Go back" });

		while (true)
		{
			cout << "Enter choice: ";
			cin >> choice;
			switch (choice)
			{
				case 1:
					createGraph();
					break;
				case 2:
					show_adjacency_list();
					break;
				case 3:
					show_adjacency_matrix();
					break;
				case 4:
					generate_menu_header("Data Structures",
					{ 			"Array", "Queue", "Linked List", "Binary Tree", "Graph Theory" });
					show_data_structures_menu();
					break;
				default:
					cout << "Invalid. Please try again." << endl;
			}
		}
	}

	void createGraph()
	{
		vector<int> u_stored;
		vector<int> v_stored;

		int flag;
		cout << "Enter number of vertices: ";
		cin >> vertices;
		matrix.resize(vertices);
		// Input 0 to all[i][j]
		for (int i = 0; i < vertices; i++)
		{
			matrix[i].resize(vertices);
		}

		graph.resize(vertices);
		// Input 0 to all[i][j]
		for (int i = 0; i < vertices; i++)
		{
			graph[i].resize(vertices);
			for (int j = 0; j < vertices; j++)
			{
				graph[i][j] = INT_MAX;
			}
		}

		cout << "Enter number of edges: ";
		cin >> edges;
		int i = 0;
		while (i < edges)
		{
			cout << "\n For edge " << i + 1 << endl;
			cout << "Enter origin: ";
			cin >> u;
			cout << "Enter destination: ";
			cin >> v;

			if (u - 1 >= 0 && u - 1 < vertices && v - 1 >= 0 && v - 1 < vertices)
			{
				flag = 1;
				for (int i = 0; i > u_stored.size(); i++)
				{
					if (u_stored[i] == u && v == v_stored[i])
					{
						flag = 0;
						break;
					}
				}

				if (flag == 1)
				{
					add_edge(u - 1, v - 1);
					u_stored.push_back(u);
					v_stored.push_back(v);
					cout << "Edge " << i + 1 << " added!" << endl;
					i++;
				}
				else
				{
					cout << "\nThis edge already exists. Please try again.";
				}
			}
			else
			{
				cout << "\nVertices are out of range. Please try again.";
			}
		}

		created = true;
		system("clear");
		cout << "\nGraph created successfully" << endl;
		system("read -p 'Press any key to continue... '");
		graphMenu();

	}

	void add_edge(int u, int v)
	{
		for (int i = 0; i < graph[u].size(); i++)
		{
			if (graph[u][i] == INT_MAX)
			{
				graph[u][i] = v;
				break;
			}
			else
			{
				continue;
			}
		}
		matrix[u][v] = 1;
		created = true;
	}

	void show_adjacency_list()
	{
		for (int u = 0; u < vertices; u++)
		{
			cout << u + 1 << " ";
			for (int v = 0; v < (int) graph[u].size(); v++)
			{
				if (graph[u][v] != INT_MAX)
				{
					cout << "-> " << graph[u][v] + 1 << " ";
				}
				else
				{
					continue;
				}
			}
			cout << endl;
		}
	}

	void show_adjacency_matrix()
	{
		for (int u = 0; u < vertices; u++)
		{
			if (u == 0)
			{
				cout << "  ";
			}
			cout << u + 1 << " ";
		}
		cout << endl;

		for (int u = 0; u < vertices; u++)
		{
			cout << u + 1 << " ";
			for (int i = 0; i < vertices; i++)
			{
				cout << matrix[u][i] << " ";
			}
			cout << endl;
		}
	}
};

					
void show_data_structures_menu()
{
	vector<string> choices = { "Array", "Queue", "Stack", "Linked List", "Binary Tree", "Graph Theory", "Exit" };
	generate_menu_header("Data Structures", choices);

	// Menu Loop
	int choice;
	while (true)
	{
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				{
					Array array_obj;
					array_obj.arrayMenu();
					break;
				}
			case 2:
				{
					Queue queue_obj;
					queue_obj.queueMenu();
					break;
				}
			case 3:
				{
					Stack stack_obj;
					stack_obj.stackMenu();
					break;
				}

			case 4:{
				LinkedList linkedlist_obj;
				linkedlist_obj.linkedListMenu();
				break;
			}
			case 5:
				{
					BinaryTree binarytree_obj;
					binarytree_obj.binaryMenu();
					break;
				}
			case 6:
				{
					GraphTheory graph_obj;
					graph_obj.graphMenu();
					break;
				}
			case 7:
				{
					exit(0);
				}

			default:
				cout << "Invalid. Please try again." << endl;
		}
	}
}

void generate_menu_header(string title, vector<string> choices)
{
	system("clear");
	cout << "<<Patrick Star DS Program>>" << endl;
	cout << "===== " << title << " ======" << endl;
	cout << "Choose:\n";
	for (int i = 0; i < choices.size(); i++)
	{
		cout << i + 1 << ". " << choices[i] << endl;
	}
}

#endif