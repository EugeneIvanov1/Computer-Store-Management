#include <iostream>
#include <vector>
#include <memory>

class ComputerType {
public:
    void dailySummary() const;

private:
    struct Node {
        int receiptNumber{};
        std::string customerName;
        std::string date;
        std::vector<std::string> types;
        std::vector<std::string> computerNames;
        std::vector<int> quantities;
        std::vector<int> amounts;
        int total{};
        std::unique_ptr<Node> next;
    };
    std::unique_ptr<Node> startPtr;
};

void ComputerType::dailySummary() const {
    constexpr char separator[] = "\t\t===========================================\n";
    const Node* temp = startPtr.get();

    if (!temp) {
        std::cout << "\n" << separator;
        std::cout << "\t\t\tThere is no Order to show!!!\n\t\t\tThe List is Empty\n";
        std::cout << separator << "\n";
        return;
    }

    std::cout << "\n================================================================================================\n";
    std::cout << " \t\t\tHere is the Daily Summary of All Orders \n";
    std::cout << "================================================================================================\n\n";

    while (temp) {
        std::cout << "Receipt Number : " << temp->receiptNumber << "\n";
        std::cout << "Customer Name  : " << temp->customerName << "\n";
        std::cout << "Order Date     : " << temp->date << "\n\n";

        std::cout << "+===================+==============================+====================+=======================+\n";
        std::cout << "|   Computer Type   |         Computer Name        |      Quantity      |     Total Price (Rs.) |\n";
        std::cout << "+===================+==============================+====================+=======================+\n";

        size_t orderSize = temp->quantities.size();
        for (size_t i = 0; i < orderSize; ++i) {
            std::cout << "\t" << temp->types[i] << "  \t\t"
                      << " " << temp->computerNames[i] << "\t  "
                      << "\t    " << temp->quantities[i] << "\t"
                      << "\t\t" << temp->amounts[i] << ".00" << "\n";
            std::cout << "+-------------------+------------------------------+--------------------+-----------------------+\n";
        }

        temp->total = 0;
        for (int amount : temp->amounts) {
            temp->total += amount;
        }
        
        std::cout << "\nTotal Bill is : Rs. " << temp->total << ".00/-\n";
        std::cout << "\n=================================================================================================\n" << "\n";

        temp = temp->next.get();
    }
}