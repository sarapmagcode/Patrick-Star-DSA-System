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
void generate_menu_header(string title, vector<string>);

// Class for Array Data Structure
struct Array {
  int size = 0;  // Array Global Variable Declaration
  int *arr = new int[size];
  int *arr_sorted = new int[size];
  bool created = false;  // Check if array is already created

  void arrayMenu() {
    system("clear");
    int choice;
    generate_menu_header("Array", {"Create array", "Show original",
                                   "Show sorted", "Search element", "Go back"});
    while (true) {
      cout << "Enter choice: ";
      cin >> choice;
      switch (choice) {
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
        case 5: {
          generate_menu_header(
              "Data Structures",
              {"Array", "Queue", "Linked List", "Binary Tree"});
          show_data_structures_menu();
          break;
        }
        default:
          cout << "Invalid. Please try again." << endl;
      }
    }
  }

  void createArray() {
    cout << "Enter the size of the array: ";
    cin >> size;
    delete[] arr;
    arr = new int[size];

    for (int i = 0; i < size; i++) {
      cout << "Enter the no." << i + 1 << " element: ";
      cin >> arr[i];
    }

    created = true;
    system("clear");
    cout << "Array successfully created.\n";
    system("read -p 'Press any key to continue... '");
    arrayMenu();
  }

  void showOriginal() {
    cout << "   ===== Original Array =====\n" << endl;
    cout << "\t[ ";
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << "]\n" << endl;
    system("read -p 'Press any key to continue... '");
    arrayMenu();
  }

  void sortArray(int arr_sorted[], int size) {
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++) {
      min = i;
      for (j = i + 1; j < size; j++)
        if (arr_sorted[j] < arr_sorted[min]) min = j;
      temp = arr_sorted[i];
      arr_sorted[i] = arr_sorted[min];
      arr_sorted[min] = temp;
    }
  }

  void showSorted() {
    // Sort and copy array
    arr_sorted = new int[size];
    for (int i = 0; i < size; i++) arr_sorted[i] = arr[i];

    sortArray(arr_sorted, size);

    cout << "   ===== Sorted Array =====\n" << endl;
    cout << "\t[ ";

    for (int i = 0; i < size; i++) {
      cout << arr_sorted[i] << " ";
    }
    cout << "]\n" << endl;
    system("read -p 'Press any key to continue... '");
    arrayMenu();
  }

  void findElement() {
    int element;
    cout << "   ===== Find an element =====\n" << endl;
    cout << "Enter the element: ";
    cin >> element;

    cout << "Searching the element in the unsorted array..." << endl;
    for (int i = 0; i < size; i++) {
      if (element == arr[i]) {
        cout << "The element " << element << " is at index[" << i << "]\n";
        break;
      } else if ((i + 1) == size && element != arr[i])
        cout << "The element is not in the array.\n";
      else
        continue;
    }

    cout << "Searching the element in the sorted array..." << endl;
    for (int i = 0; i < size; i++) {
      if (element == arr_sorted[i]) {
        cout << "The element " << element << " is at index[" << i << "]\n";
        break;
      } else if ((i + 1) == size && element != arr_sorted[i])
        cout << "The element is not in the array.\n";
      else
        continue;
    }
    system("read -p 'Press any key to continue... '");
    arrayMenu();
  }
};

// Class for Queue Data Structure
struct Queue {
  bool created = false;
  int size = 0;
  int *queue = new int[size];
  int front = -1;
  int rear = -1;
  int numItems = -1;
  vector<int> displayArray;
  void queueMenu() {
    system("clear");
    int choice;
    generate_menu_header(
        "Queue", {"Create queue", "Check if full", "Check if empty",
                  "Enqueue/Insert", "Dequeue/Remove", "Get front/first element",
                  "Get rear/last element", "Display", "Go back"});
    while (true) {
      cout << "Enter choice: ";
      cin >> choice;
      switch (choice) {
        case 1:
          createQueue();
          break;
        case 2:
          if (!created) {
            cout << "Create a queue first." << endl;
          } else {
            if (isFull()) {
              cout << "The queue is full\n";
              cout << "Max queue size is " << size << endl;
            } else {
              cout << "The queue is NOT full\n";
              cout << "Max queue size is " << size << endl;
            }
          }
          break;
        case 3:
          if (!created)
            cout << "Create a queue first." << endl;
          else {
            if (checkEmpty()) {
              cout << "The queue is empty\n";
            } else {
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
            if(!created)
                cout << "Create a queue first." << endl;
            else
                display();
            break;
        case 9: {
          generate_menu_header(
              "Data Structures",
              {"Array", "Queue", "Linked List", "Binary Tree"});
          show_data_structures_menu();
          break;
        }
        default:
          cout << "Invalid. Please try again." << endl;
      }
    }
  }
 
  void createQueue() {
    cout << "Enter the size of the queue: ";
    cin >> size;
    queue = new int[size];  // Load new size to queue
    int val;
    for (int i = 0; i < size; i++) {
      if (isFull()) {
        cout << "The queue is now full.\n";
        cout << "Max queue size is " << size;
      } else {
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

  bool checkEmpty() {
    bool status;
    if (numItems) {
      status = false;
    } else {
      status = true;
    }
    return status;
  }

  bool isFull() {
    bool status;
    if (numItems <= size) {
      status = false;
    } else {
      status = true;
    }
    return status;
  }

  void enqueue() {
    int val;
    if (isFull()) {
      cout << "The queue is now full.\n";
    } else {
      cout << "Enter the element to be pushed: ";
      cin >> val;
      rear = (rear + 1) % size;
      queue[rear] = val;
      numItems++;
      displayArray.insert(displayArray.begin(), val);
    }
  }

  void dequeue() {
    if (checkEmpty()) {
      cout << "The queue is empty.\n";
    } else {
      front = (front + 1) % size;
      numItems--;
      cout << "Popped front value" << endl;
      displayArray.pop_back();
    }
  }

  void showFront() {
    if (checkEmpty()) {
      cout << "The queue is empty" << endl;
    } else {
      cout << "The front of the queue is the value: " << queue[numItems]
           << endl;
    }
  }

  void showRear() {
    if (checkEmpty()) {
      cout << "The queue is empty" << endl;
    } else {
      cout << "The rear of the queue is the value: " << queue[0] << endl;
    }
  }

    void display(){
        if(checkEmpty()){
            cout << "The queue is empty" << endl;
        }else{
            system("clear");
            cout << "===== Queue Elements =====" << endl;
            cout << "[ ";
            for(int i : displayArray){
                cout << i << " ";
            }

            cout << "]\n" << endl;
            system("read -p 'Press any key to continue... '");
            queueMenu();
        }
    }
};

// Class for Stack Data Structure
struct Stack {

    //Global variable declarations
    int size = 0;
    int *stackArray = new int[size];
    int top = -1;
    bool created = false;


    void stackMenu() {
    if(!created)
        askSize();

    system("clear");
    created = true;
    int choice;
    generate_menu_header("Stack", {"Push", "Pop", "Peek", "Check if empty",
                                   "Display", "Go back"});

    while (true) {
      cout << "Enter choice: ";
      cin >> choice;
      switch (choice) {
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
            if(checkEmpty()){
                cout << "The stack is empty. \n";
            }else{
                cout << "The stack is not empty. \n";
            }
          break;
        case 5:
          display();
          break;
        case 6:
            generate_menu_header(
              "Data Structures",
              {"Array", "Queue", "Linked List", "Binary Tree"});
          show_data_structures_menu();
          break;
        default:
            cout << "Invalid. Please try again." << endl;
      }
    }
  }

    void askSize(){
        system("clear");
        cout << "Enter the size of the stack: ";
        cin >> size;
        stackArray = new int[size];
    }

    void push(){
        int val;

        if(checkFull()){
            cout << "The stack is full.\n";
        }else {
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

    void pop(){
        if(checkEmpty()){
            cout << "The stack is empty. \n";
        }else {
            system("clear");
            cout << "Successfully popped top value " << stackArray[top] << " from the stack." << endl;
            top--;
            system("read -p 'Press any key to continue... '");
            stackMenu();
        }
    }

    void peek(){
        if(checkEmpty()){
            cout << "The stack is empty. \n";
        }else {
            cout << "The top value of the stack is " << stackArray[top] << endl;
            system("read -p 'Press any key to continue... '");
            stackMenu();
        }
    }

    void display(){
        if(checkEmpty()){
            cout << "The stack is empty. \n";
        }else{
            system("clear");
            cout << "   ===== Stack Values =====\n" << endl;
            cout << "\t[ ";
            for (int i = 0; i <= top; i++) {
                
                cout << stackArray[i] << " ";
            }
            cout << "]\n" << endl;
            system("read -p 'Press any key to continue... '");
            stackMenu();
        }
    }

    bool checkEmpty(){
        bool status;
        if (top == -1){
            status = true;
        } else {
            status = false;
        }
        return status;
    }

    bool checkFull(){
        bool status;
        if(top == size - 1){
            status = true;
        } else {
            status = false;
        }
        return status;
    }


};

// Class for Binary Search Tree
struct BinaryTree{
    bool created = false;

    struct TreeNode{
        int value;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *root;
    
    BinaryTree(){       // Constructor for instantiating root
        root = NULL;
    }

    void binaryMenu() {
        // Generate data in nodes
        if(!created){
            for(int i=100; i < 108 ; i++)
                insertNode(i*4); 
            created = true;           
        }
        system("clear");
        created = true;
        int choice;
        generate_menu_header("Binary Tree", {"Display tree", "In order traversal", "Pre order traversal", "Post order traversal", "Go back"});

        while (true) {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "[ ";
                displayInOrder(root);
                cout << " ]";
                break;
            case 2:
                cout << "=== Displaying with In Order traversal ===" << endl;
                cout << "[ ";
                displayInOrder(root);
                cout << " ]" << endl;               
                break;
            case 3:
                cout << "=== Displaying with Pre Order traversal ===" << endl;
                cout << "[ ";
                displayPreOrder(root);
                cout << " ]" << endl; 
                break;
            case 4:
                cout << "=== Displaying with Post Order traversal ===" << endl;
                cout << "[ ";
                displayPostOrder(root);
                cout << " ]" << endl; 
                break;
            case 5:
                generate_menu_header(
                "Data Structures",
                {"Array", "Queue", "Linked List", "Binary Tree"});
            show_data_structures_menu();
                break;
            default:
                cout << "Invalid. Please try again." << endl;
        }
        }
  }

    void insertNode(int val){
        TreeNode *newNode, *nodePtr;
        newNode = new TreeNode;
        newNode->value = val;
        newNode->left = newNode->right = NULL;

        if (!root){
            root = newNode;
        }else{

            nodePtr = root;
            while (nodePtr != NULL) {
                if (val < nodePtr->value) {
                    if (nodePtr->left) {
                        nodePtr = nodePtr->left;
                    } else {
                        nodePtr->left = newNode;
                        break;
                    }
                } else if (val > nodePtr->value) {
                    if (nodePtr->right) {
                        nodePtr = nodePtr->right;
                    } else {
                        nodePtr->right = newNode;
                        break;
                    }
                } else {
                    cout << "Duplicate value found in tree.\n";
                    break;
                }
            } 
        }
    }

    void displayInOrder(TreeNode *nodePtr){
        if (nodePtr) {
            displayInOrder(nodePtr->left);
            cout << nodePtr->value << " ";
            displayInOrder(nodePtr->right);
        }
    }

    void displayPreOrder(TreeNode *nodePtr){
        if(nodePtr){
            cout << nodePtr->value << " ";
            displayPreOrder(nodePtr->left);
            displayPreOrder(nodePtr->right);
        }
    }

    void displayPostOrder(TreeNode *nodePtr){
        if (nodePtr){
            displayPostOrder(nodePtr->left);
            displayPostOrder(nodePtr->right);
            cout << nodePtr->value << " ";
        }
    }

};

void show_data_structures_menu() {
  vector<string> choices = {"Array", "Queue", "Stack", "Linked List", "Binary Tree"};
  generate_menu_header("Data Structures", choices);

  // Menu Loop
  int choice;
  while (true) {
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice) {
      case 1: {
        Array array_obj;
        array_obj.arrayMenu();
        break;
      }
      case 2: {
        Queue queue_obj;
        queue_obj.queueMenu();
        break;
      }
      case 3:{
        Stack stack_obj;
        stack_obj.stackMenu();
        break;        
      }

      case 4:
        // Binary Tree
        break;
      case 5:{
        BinaryTree binarytree_obj;
        binarytree_obj.binaryMenu();
        break;        
      }


      default:
        cout << "Invalid. Please try again." << endl;
    }
  }
}

void generate_menu_header(string title, vector<string> choices) {
  system("clear");
  cout << "<<Patrick Star DSA Program>>" << endl;
  cout << "===== " << title << " ======" << endl;
  cout << "Choose:\n";
  for (int i = 0; i < choices.size(); i++) {
    cout << i + 1 << ". " << choices[i] << endl;
  }
}

#endif