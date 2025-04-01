#include "Class.cpp"
#include "Structure.cpp"
#include "TakeOrder.cpp"
#include "DeleteOrder.cpp"
#include "DisplayReceipt.cpp"
#include "ModifyOrder.cpp"
#include "DailySummary.cpp"
#include "Exit.cpp"

#include <iostream>

void displayMenu() {
    std::cout << "\t\t==================================================\n";
    std::cout << "\t\t\t Computer Store Management System \n";
    std::cout << "\t\t==================================================\n\n";
    std::cout << "\t\t---------------------------------------------------\n";
    std::cout << "\t\t||\t1. Take New Computer Order \t\t ||\n";
    std::cout << "\t\t||\t2. Delete Latest Order\t\t ||\n";
    std::cout << "\t\t||\t3. Modify Order List \t\t ||\n";
    std::cout << "\t\t||\t4. Print the Receipt \t\t ||\n";
    std::cout << "\t\t||\t5. Daily Summary of Total Sale \t ||\n";
    std::cout << "\t\t||\t6. Exit\t\t\t\t ||\n";
    std::cout << "\t\t---------------------------------------------------\n";
}

int main() {
    computerType computer;
    int menu = 0;
    
    do {
        displayMenu();
        std::cout << "\nEnter Choice: ";
        std::cin >> menu;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 6.\n";
            continue;
        }

        switch (menu) {
            case 1:
                computer.take_order();
                break;
            case 2:
                computer.delete_order();
                break;
            case 3:
                computer.modify();
                break;
            case 4:
                computer.order_list();
                break;
            case 5:
                computer.daily_summary();
                break;
            case 6:
                std::cout << "\t\t===========================\n";
                std::cout << "\t\t\tThank You!!!\n";
                std::cout << "\t\t===========================\n\n";
                break;
            default:
                std::cout << "Invalid input. Please enter a number between 1 and 6.\n";
        }
    } while (menu != 6);

    return 0;
}