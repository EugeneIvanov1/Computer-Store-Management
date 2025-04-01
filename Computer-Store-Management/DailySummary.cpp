#include <iostream>
#include <vector>
using namespace std;

class ComputerType {
public:
    void daily_summary();

private:
    struct Node {
        int receipt_number;
        string customerName;
        string date;
        vector<string> type;
        vector<string> computerName;
        vector<int> quantity;
        vector<int> amount;
        int total = 0;
        Node* next = nullptr;
    };
    Node* start_ptr = nullptr;
};

void ComputerType::daily_summary() {
    const string separator = "\t\t===========================================\n";
    Node* temp = start_ptr;

    if (temp == nullptr) {
        cout << endl << separator;
        cout << "\t\t\tThere is no Order to show!!!\n\t\t\tThe List is Empty\n";
        cout << separator << endl;
        return;
    }

    cout << "\n";
    cout << "================================================================================================" << endl;
    cout << " \t\t\tHere is the Daily Summary of All Orders \n";
    cout << "================================================================================================\n" << endl;

    while (temp != nullptr) {
        cout << "Receipt Number : " << temp->receipt_number << endl;
        cout << "Customer Name  : " << temp->customerName << endl;
        cout << "Order Date     : " << temp->date << "\n" << endl;

        cout << "+===================+==============================+====================+=======================+" << endl;
        cout << "|   Computer Type   |         Computer Name        |      Quantity      |     Total Price (Rs.) |" << endl;
        cout << "+===================+==============================+====================+=======================+" << endl;

        for (size_t i = 0; i < temp->quantity.size(); i++) {
            cout << "\t" << temp->type[temp->menu2[i] - 1] << "  \t\t"
                 << " " << temp->computerName[temp->menu2[i] - 1] << "\t  "
                 << "\t    " << temp->quantity[i] << "\t"
                 << "\t\t" << temp->amount[i] << ".00" << endl;
            cout << "+-------------------+------------------------------+--------------------+-----------------------+" << endl;
        }

        temp->total = 0;
        for (int amount : temp->amount) {
            temp->total += amount;
        }
        
        cout << "\nTotal Bill is : Rs. " << temp->total << ".00/-\n";
        cout << "\n=================================================================================================\n" << endl;

        temp = temp->next;
    }
}