// Header file for DSA 
#ifndef CLASS_H
#define CLASS_H
#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void show_algorithms_menu();
void show_data_structures_menu();
void generate_menu_header(string title, vector<string>);

// Class for Array Data Structure
struct Array{
    int size = 0; // Array Global Variable Declaration
    int *arr = new int[size];
    int *arr_sorted = new int[size];
    bool created = false; // Check if array is already created

    void arrayMenu(){
        system("clear");
        int choice;
        generate_menu_header("Array",{"Create array", "Show original", "Show sorted", "Search element", "Go back"});
        while(true){
            cout << "Enter choice: ";
            cin >> choice;
            switch(choice){
                case 1:
                    createArray();
                    break;
                case 2:
                    if(!created)
                        cout << "Create an array first." << endl;
                    else
                        showOriginal();
                    break;
                case 3:
                    if(!created)
                        cout << "Create an array first." << endl;
                    else
                        showSorted();
                    break;
                case 4:
                    if(!created)
                        cout << "Create an array first." << endl;
                    else
                        findElement();
                    break;
                case 5:{
                    generate_menu_header("Data Structures",{"Array", "Queue", "Linked List", "Binary Tree"});
                    show_data_structures_menu();
                    break;
                }  
                default:
                    cout << "Invalid. Please try again." << endl;
            }
        }
    }    

    void createArray(){ 
        cout << "Enter the size of the array: ";
        cin >> size;
        delete [] arr;
        arr = new int[size];

        for(int i=0; i < size; i++){
            cout << "Enter the no." << i+1 << " element: ";
            cin >> arr[i];
        }

        created = true;
        system("clear");
        cout << "Array successfully created.\n";
        system("read -p 'Press any key to continue... '");
        arrayMenu();
    }

    void showOriginal(){
        cout << "   ===== Original Array =====\n" << endl;
        cout << "\t[ ";
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << "]\n" << endl;
        system("read -p 'Press any key to continue... '");
        arrayMenu();
    }

    void sortArray(int arr_sorted[], int size){
           int i, j, min, temp;
            for (i = 0; i < size - 1; i++) {
                min = i;
                for (j = i + 1; j < size; j++)
                if (arr_sorted[j] < arr_sorted[min])
                min = j;
                temp = arr_sorted[i];
                arr_sorted[i] = arr_sorted[min];
                arr_sorted[min] = temp;
             }
    }

    void showSorted(){ 
        // Sort and copy array
        arr_sorted = new int[size];
        for(int i = 0; i < size; i++)
            arr_sorted[i] = arr[i];

        sortArray(arr_sorted,size);

        cout << "   ===== Sorted Array =====\n" << endl;
        cout << "\t[ ";
        
        for(int i = 0; i < size; i++){
            cout << arr_sorted[i] << " ";
        }
        cout << "]\n" << endl;
        system("read -p 'Press any key to continue... '");
        arrayMenu();
    }    
        
    void findElement(){
        int element;
        cout << "   ===== Find an element =====\n" << endl;
        cout << "Enter the element: ";
        cin >> element;

        cout << "Searching the element in the unsorted array..." << endl;
        for(int i = 0; i < size; i++){
            if(element == arr[i]){
                cout << "The element " << element << " is at index[" << i << "]\n";  
                break;              
            }
            else if( (i+1) == size && element != arr[i])
                cout << "The element is not in the array.\n";
            else 
                continue;
        }

        cout << "Searching the element in the sorted array..." << endl;
        for(int i = 0; i < size; i++){
            if(element == arr_sorted[i]){
                cout << "The element " << element << " is at index[" << i << "]\n";  
                break;              
            }
            else if( (i+1) == size && element != arr_sorted[i])
                cout << "The element is not in the array.\n";
            else 
                continue;
        }
        system("read -p 'Press any key to continue... '");
        arrayMenu();
    }
};

// Class for Queue Data Structure
struct Queue{
    bool created = false;
    int size = 0;
    int *queue = new int[size];
    int front = 99;
    int rear = 99;
    int numItems = 0;


    void queueMenu(){
        system("clear");
        int choice;
        generate_menu_header("Queue",{"Create queue", "Check if full", "Check if empty", "Enqueue/Insert", "Dequeue/Remove", "Get front/first element", "Get rear/last element", "Go back"});
        while(true){
            cout << "Enter choice: ";
            cin >> choice;
            switch(choice){
                case 1:
                    createQueue();
                    break;
                case 2:
                    if(!created){
                        cout << "Create a queue first." << endl;
                    }
                    else{
                        if(isFull()){
                            cout << "The queue is full\n";
                            cout << "Max queue size is " << size << endl;
                        }else{
                            cout << "The queue is NOT full\n";
                            cout << "Max queue size is " << size << endl;
                        }
                    }
                    break;
                case 3:
                    if(!created)
                        cout << "Create a queue first." << endl;
                    else{
                        if(checkEmpty()){
                            cout << "The queue is empty\n";
                        }else{
                            cout << "The queue is NOT empty\n";
                        }
                    }
                    break;
                case 4:
                    if(!created)
                        cout << "Create a queue first." << endl;
                    else
                       enqueue();
                    break;
                case 5:
                    if(!created)
                        cout << "Create a queue first." << endl;
                    else
                        dequeue();
                    break;
                case 6:
                    if(!created)
                        cout << "Create a queue first." << endl;
                    else
                        showFront();
                    break;
                case 7:
                    if(!created)
                        cout << "Create a queue first." << endl;
                    else
                        showRear();
                    break;
                case 8:{
                    if(!created)
                        cout << "Create a queue first." << endl;
                    else{          
                        generate_menu_header("Data Structures",{"Array", "Queue", "Linked List", "Binary Tree"});
                        show_data_structures_menu();
                    }
                    break;
                }
                default:
                    cout << "Invalid. Please try again." << endl;
            }
        }
    }  
    
    void createQueue(){
        cout << "Enter the size of the queue: ";
        cin >> size;
        queue = new int[size]; // Load new size to queue
        int val;
        for(int i = 0; i < size; i++){
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

        created = true;
        system("clear");
        cout << "Queue successfully created.\n";
        system("read -p 'Press any key to continue... '");
        queueMenu();
    }

    bool checkEmpty(){
        bool status;
        if(numItems){
            status = false;
        } else {
            status = true;
        }
        return status;
    }

    bool isFull(){
        bool status;
        if (numItems < size) {
            status = false;
        } else {
            status = true;
        }
        return status;
    }

    void enqueue(){
        int val;
        if (isFull()) {
            cout << "The queue is now full.\n";
        } else {
            cout << "Enter the element to be pushed: ";
            cin >> val;
            rear = (rear + 1) % size;
            queue[rear] = val;
            numItems++;
        }
    
    }

    void dequeue(){
        int num;
        if (checkEmpty()) {
		cout << "The queue is empty.\n";
    	} else {
            front = (front + 1) % size;
            num = queue[front];
            numItems--;
            cout << "Popped front value" << endl;
	    }
    }

    void showFront(){
        if(checkEmpty()){
            cout << "The queue is empty" << endl;
        }else{
            cout << "The front of the queue is the value: "<< queue[numItems - 1] << endl;
        }

        for(int i = 0; i < size; i++){
            cout << "[" << queue[i] << "]" << endl;
        }
    }

    void showRear(){
        cout << "The rear of the queue is the value: " << queue[0] << endl;
    }

};



void show_data_structures_menu(){
    vector<string> choices = {"Array", "Queue", "Linked List", "Binary Tree"};
    generate_menu_header("Data Structures", choices);

    // Menu Loop
    int choice;
    while(true){
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:{
                Array array_obj;
                array_obj.arrayMenu();
                break;
            }
            case 2:{
                Queue queue_obj;
                queue_obj.queueMenu();
                break;
            }
            case 3:
                // Linked List
                break;
            case 4:
                // Binary Tree
                break;
            default:
                cout << "Invalid. Please try again." << endl;
        }
    }
}

void show_algorithms_menu(){
    vector<string> choices = {"Searching Algorithms", "Sorting Algorithms", "Graph Algorithms"};
    generate_menu_header("Algorithms", choices);
    
    // Menu Loop
    int choice;
    while(true){
        cout << "Enter choice: ";
        cin >> choice;            
        switch(choice){
            case 1:
                // Search Algo
                break;
            case 2:
                // Sorting Algo 
                break;
            case 3:
                // Graph Algo
                break;
            default:
                cout << "Invalid. Please try again." << endl;
        }
    }
}

void generate_menu_header(string title, vector<string> choices){
        system("clear");
        cout << "<<Patrick Star DSA Program>>" << endl;
        cout << "===== " << title << " ======" << endl;
        cout << "Choose:\n";
        for(int i = 0; i < choices.size(); i++){
                cout << i+1 << ". " << choices[i] << endl;         
    }
}


#endif