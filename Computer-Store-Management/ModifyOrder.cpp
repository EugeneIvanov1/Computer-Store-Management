#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

class ComputerType {
private:
    struct Order {
        int receipt_number;
        string customerName;
        string date;
        int x;
        int menu2[10];
        int quantity[10];
        double amount[10];
        double computer[10];
        string computerName[10];
        Order* next;
    } *start_ptr;

public:
    ComputerType() : start_ptr(nullptr) {}
    void modify();
};

void ComputerType::modify() {
    system("cls");
    if (!start_ptr) {
        cout << "\n\t\t============================="
             << "\n\t\t    NO RECORD TO MODIFY...!"
             << "\n\t\t=============================\n\n";
        return;
    }

    int sid;
    cout << "\nEnter Receipt Number To Modify: ";
    if (!(cin >> sid)) {
        cout << "\nInvalid input. Please enter a valid receipt number.";
        clearInputBuffer();
        return;
    }

    Order* temp = start_ptr;
    bool found = false;

    while (temp) {
        if (temp->receipt_number == sid) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "\n\t\t===============================\n"
             << "\t\t   Invalid Receipt Number...!\n"
             << "\t\t===============================\n\n";
        return;
    }

    cout << "Change Order Number: ";
    if (!(cin >> temp->receipt_number)) {
        cout << "Invalid input. Order number not changed.";
        clearInputBuffer();
    }

    cout << "Change Customer Name: ";
    cin.ignore();
    getline(cin, temp->customerName);

    cout << "Change Date: ";
    getline(cin, temp->date);

    cout << "\nHow many new laptops would you like to change (Maximum is 10): ";
    if (!(cin >> temp->x) || temp->x < 1 || temp->x > 10) {
        cout << "Invalid input. The number of laptops must be between 1 and 10.";
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < temp->x; i++) {
        cout << "-----------------------------------------\n";
        cout << "\nPlease Enter your selection to Change: ";
        if (!(cin >> temp->menu2[i]) || temp->menu2[i] < 1 || temp->menu2[i] > 10) {
            cout << "Invalid input. Selection ignored.";
            clearInputBuffer();
            continue;
        }

        cout << "Change Laptop Name: " << temp->computerName[temp->menu2[i] - 1] << endl;
        cout << "\nHow many New laptops do you want: ";
        if (!(cin >> temp->quantity[i]) || temp->quantity[i] < 1) {
            cout << "Invalid input. Quantity ignored.";
            clearInputBuffer();
            continue;
        }
        cout << "\n-----------------------------------------\n";

        temp->amount[i] = temp->quantity[i] * temp->computer[temp->menu2[i] - 1];
        cout << "\n----------------------------------------------------------------\n";
        cout << "The amount you need to pay after modification is: Rs. " << temp->amount[i] << ".00/-\n";
        cout << "----------------------------------------------------------------\n\n";
        system("PAUSE");
    }

    system("cls");
    cout << "\n\t\t=============================\n"
         << "\t\t     RECORD MODIFIED....!\n"
         << "\t\t=============================\n\n";
}
