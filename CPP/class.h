// Header file for DSA 
#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <vector>

using namespace std;

void show_algorithms_menu();
void show_data_structures_menu();
void generate_menu_header(string title, vector<string>);


struct Array{
        bool created = false; // Check if array is already created

        void arrayMenu(){
            system("clear");
            int choice;
            cout << "<<Patrick Star DSA Program>>" << endl;
            cout << "===== Array ======" << endl;
            cout << "Choose:\n";
            cout << "1. Create array\n";
            cout << "2. Show original\n";
            cout << "3. Show sorted\n";
            cout << "4. Search element\n";
            cout << "5. Go back\n";
            

            while(true){
                cout << "Enter choice: ";
                cin >> choice;
                switch(choice){
                    case 1:
                        createArray();
                        break;
                    case 2:
                        if(!created){
                            cout << "Create an array first." << endl;
                        }else{}
                        break;
                    case 3:
                        // Show sorted
                        break;
                    case 4:
                        // show_data_structures_menu();
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
            int size; 
            cout << "Enter the size of the array: ";
            cin >> size;
            int arr[size];

            for(int i=0; i < size; i++){
                cout << "Enter the no." << i+1 << " element: ";
                cin >> arr[i];
            }
            cout << "Array successfully created.\n";
            created = true;
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
                cout << "Invalid. Please try again. DSA MENU--" << endl;
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