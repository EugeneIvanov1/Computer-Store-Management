#include <iostream>
#include <vector>

using namespace std;

class ComputerType {
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
    
    void printReceipt(Node* temp) const {
        const string separator = "================================================================================================";
        cout << separator << endl;
        cout << "\t\t\t\t  Here is the Ordered list\n";
        cout << separator << "\n" << endl;
        
        cout << "Receipt Number : " << temp->receipt_number << endl;
        cout << "Customer Name  : " << temp->customerName << endl;
        cout << "Order Date     : " << temp->date << "\n" << endl;
        
        cout << "+===================+==============================+====================+=======================+" << endl;
        cout << "|   Computer Type   |         Computer Name        |      Quantity      |     Total Price (Rs.) |" << endl;
        cout << "+===================+==============================+====================+=======================+" << endl;
        
        for (size_t i = 0; i < temp->quantity.size(); ++i) {
            cout << "\t" << temp->type[i] << "  \t\t";
            cout << " " << temp->computerName[i] << "\t  ";
            cout << "\t    " << temp->quantity[i] << "\t";
            cout << "\t\t" << temp->amount[i] << ".00" << endl;
            cout << "+-------------------+------------------------------+--------------------+-----------------------+" << endl;
        }
        
        temp->total = 0;
        for (int amt : temp->amount) {
            temp->total += amt;
        }
        
        cout << "\nTotal Bill: " << temp->total << ".00/- Rs.\n\n";
        cout << "Thank You!!!\n------------\n";
        cout << separator << "\n\n";
    }

public:
    void orderList() {
        system("cls");
        if (!start_ptr) {
            cout << "\n\t\t===========================================\n";
            cout << "\t\t\tThere is no Order to show!!!\n\t\t\tThe List is Empty\n";
            cout << "\t\t===========================================\n\n";
            return;
        }

        int num;
        cout << "\nEnter the Receipt Number To Print The Receipt: ";
        cin >> num;
        
        Node* temp = start_ptr;
        while (temp) {
            if (temp->receipt_number == num) {
                printReceipt(temp);
                return;
            }
            temp = temp->next;
        }
        
        cout << "\n\t\t===========================================\n";
        cout << "\t\t\t  Invalid Receipt Number!\n";
        cout << "\t\t===========================================\n\n";
    }
};