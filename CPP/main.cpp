#include <iostream>
#include <vector>

using namespace std;

// Banner Function
void generate_menu_header(string title, vector<string> choices){
    system("clear");
    cout << "<<Patrick Star DSA Program>>" << endl;
    cout << "===== " << title << " ======" << endl;
    cout << "Choose:\n";
    for(int i = 0; i < choices.size(); i++){
        cout << i+1 << ". " << choices[i] << endl; 
    } 
}


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
                // Call Data Structures Menu
                break;
            case 2:
                // Call Algorithms Menu
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