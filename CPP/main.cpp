#include <iostream>
#include <vector>
#include "class.h"
#include "menu.h"
using namespace std;


int main() {

    // print Banner
    generate_menu_header("Main Menu", {"Data Structures", "Algorithms", "Exit"});
    
    // Menu Loop
    int choice;
    while(true){
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:{
                show_data_structures_menu();
                break;
            }
            case 2:{
                show_algorithms_menu();
                break;
            }
            case 3:
                cout << "Exitting.." << endl;
                exit(0);
            default:
                cout << "Invalid. Please try again." << endl;
        }
    }
    return 0;
}







