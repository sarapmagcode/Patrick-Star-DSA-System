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

        cout << "Array successfully created.\n";
        created = true;
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

    void showSorted(){ 
        // Sort and copy array
        arr_sorted = new int[size];
        for(int i = 0; i < size; i++)
            arr_sorted[i] = arr[i];
        sort(arr_sorted,arr_sorted+size);

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
                Array obj;
                obj.arrayMenu();
                break;
            }
            case 2:
                // Queue
                break;
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