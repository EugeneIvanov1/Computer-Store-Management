#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Node {
public:
    int receipt_number;
    string customerName;
    string date;
    int x;
    vector<int> menu2;
    vector<int> quantity;
    vector<double> amount;
    vector<string> computerName;
    vector<double> computer;
    shared_ptr<Node> next;
};

class ComputerType {
public:
    void take_order();

private:
    shared_ptr<Node> start_ptr = nullptr;
    void display_menu() const;
};

void ComputerType::display_menu() const {
    cout << "********************************************************************************************************************\n";
    cout << " ID \t   COMPUTER TYPE\t COMPUTER SPECS\t	 COMPUTER NAME\t	COMPUTER PRICE (RS.)\n";
    cout << "********************************************************************************************************************\n";
    vector<tuple<int, string, string, string, double>> computers = {
        {1, "8GB", "Intel Core i5(10th Gen)", "Dell Inspiron 15 5590", 66490.00},
        {2, "4GB", "Intel Core i3(10th Gen)", "Asus X412FA-EK361T", 40000.00},
        {3, "4GB", "Intel Core i5(8th Gen)", "Lenovo Ideapad 330", 44000.00},
        {4, "8GB", "Intel Core i5 (8th Gen)", "Huawei Mach-W19B", 77899.00},
        {5, "8GB", "macOS Catalina", "Apple MacBook Air", 118990.00},
        {6, "8GB", "Intel Core i5(10th Gen)", "HP 15s-du1034tu", 53999.00},
        {7, "4GB", "Intel Core i3(5th Gen)", "Acer Aspire ES1-571", 25655.00},
        {8, "4GB", "Intel Core i3(7th Gen)", "HP 15-DA0070TX", 49279.00},
        {9, "4GB", "Intel Core i5(6th Gen)", "Lenovo Ideapad 300", 43000.00},
        {10, "8GB", "Intel Core i7(5th Gen)", "HP Pavilion 15-ac028TX", 64000.00}
    };

    for (const auto& comp : computers) {
        cout << get<0>(comp) << "\t" << get<1>(comp) << "\t\t" << get<2>(comp) << "\t" << get<3>(comp) << "\t" << get<4>(comp) << "\n";
    }
    cout << "********************************************************************************************************************\n";
}

void ComputerType::take_order() {
    system("cls");
    cout << "-----------------\nAdd Order Details\n-----------------\n\n";

    auto temp = make_shared<Node>();
    display_menu();

    cout << "-------------------------------------------\n";
    cout << "Type Order No: ";
    cin >> temp->receipt_number;

    cout << "Enter Customer Name: ";
    cin >> temp->customerName;

    cout << "Enter Date: ";
    cin >> temp->date;

    cout << "-------------------------------------------\n";
    cout << "\nHow many different laptops would you like to order? (Maximum 10 per transaction): ";
    cin >> temp->x;

    if (temp->x <= 0 || temp->x > 10) {
        cout << "\nInvalid order! Maximum order is 10.\n";
        system("pause");
        return;
    }

    temp->menu2.resize(temp->x);
    temp->quantity.resize(temp->x);
    temp->amount.resize(temp->x);
    
    for (int i = 0; i < temp->x; i++) {
        cout << "-------------------------------------------\n";
        cout << "Please Enter Computer ID: ";
        cin >> temp->menu2[i];

        if (temp->menu2[i] < 1 || temp->menu2[i] > 10) {
            cout << "Invalid Computer ID. Try again.\n";
            --i;
            continue;
        }

        cout << "\nHow many laptops do you want?: ";
        cin >> temp->quantity[i];

        vector<double> prices = {66490.00, 40000.00, 44000.00, 77899.00, 118990.00, 53999.00, 25655.00, 49279.00, 43000.00, 64000.00};
        temp->amount[i] = temp->quantity[i] * prices[temp->menu2[i] - 1];
        cout << "\nThe amount you need to pay is: Rs. " << temp->amount[i] << "/-\n";

        cout << "-------------------------------------------\n";
        system("PAUSE");
    }

    cout << "===========================================================================" << endl;
    cout << "                     Order Taken Successfully..." << endl;
    cout << "===========================================================================" << endl;
    cout << "                Go to Receipt Menu to Pay The Bill" << endl;
    cout << "===========================================================================\n" << endl;

    system("PAUSE");

    temp->next = start_ptr;
    start_ptr = temp;
    system("cls");
}
