#include <iostream>
#include <vector>
#include "class.h"

using namespace std;

// Banner Function
void generate_menu_header(string title, vector<string> choices);

// Menu Functions
void show_algorithms_menu();
void show_data_structures_menu();


int main() {
    // print Banner
    generate_menu_header("Main Menu", {"Data Structures", "Algorithms", "Exit"});
    
    // Menu Loop
    int choice;
    while(true){
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                show_data_structures_menu();
                break;
            case 2:
                show_algorithms_menu();
                break;
            case 3:
                cout << "Exitting.." << endl;
                exit(0);
            default:
                cout << "Invalid. Please try again." << endl;
        }
    }
    return 0;
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
            case 1:
                array obj;
                    obj.printMsg();
                break;
            case 2:
                // Queue menu
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