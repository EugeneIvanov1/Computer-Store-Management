#include <iostream>
#include <memory>

using namespace std;

class ComputerType {
private:
    struct Node {
        int receipt_number;
        unique_ptr<Node> next;
    };
    
    unique_ptr<Node> start_ptr;
    Node* last = nullptr;
    int count = 0;

public:
    void delete_order();
};

void ComputerType::delete_order() {
    system("cls");
    const string separator = "\t===========================================\n";

    if (!start_ptr) {
        cerr << endl << separator;
        cerr << "\t     Cannot delete from an empty list\n";
        cerr << separator << endl;
        return;
    }

    int num;
    cout << "\nEnter the receipt number you want to delete: ";
    cin >> num;
    
    if (!cin) {
        cerr << "Invalid input. Please enter a valid number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (start_ptr->receipt_number == num) {
        start_ptr = move(start_ptr->next);
        count--;
        if (!start_ptr) {
            last = nullptr;
        }

        cout << "\n\t\t========================================\n";
        cout << "\t\t The Receipt is Deleted Successfully!!!\n";
        cout << "\t\t========================================\n\n";
        return;
    }

    Node* temp = start_ptr.get();
    Node* prev = nullptr;
    
    while (temp->next && temp->next->receipt_number != num) {
        prev = temp;
        temp = temp->next.get();
    }
    
    if (temp->next) {
        unique_ptr<Node> to_delete = move(temp->next);
        temp->next = move(to_delete->next);
        count--;
        if (!temp->next) {
            last = temp;
        }

        cout << "\n\t\t========================================\n";
        cout << "\t\t The Receipt is Deleted Successfully!!!\n";
        cout << "\t\t========================================\n\n";
    } else {
        cout << "\n\t\t==========================================\n";
        cout << "\t\t Item to be deleted is not in the list!!!\n";
        cout << "\t\t==========================================\n\n";
    }
}