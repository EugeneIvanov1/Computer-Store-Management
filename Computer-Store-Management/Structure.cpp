#include "Header.cpp"
#include <array>
#include <string>

// Node structure definition
struct Node {
    int receiptNumber{};
    std::string customerName;
    std::string date;
    std::array<int, 10> quantity{};
    std::array<int, 10> menu2{};
    std::array<int, 10> amount{};
    int total{};
    
    static constexpr std::array<const char*, 10> type = {"8GB", "4GB", "4GB", "8GB", "8GB", "8GB", "4GB", "8GB", "4GB", "8GB"};
    static constexpr std::array<const char*, 10> specifications = {"Intel Core i5(10th Gen)", "Intel Core i3 (10th Gen)", "Intel Core i5(8th Gen)", "Intel Core i5 (8th Gen)", "macOS Catalina", "Intel Core i5(10th Gen)", "Intel Core i3(5th Gen)", "Intel Core i3(7th Gen)", "Intel Core i5(6th Gen)", "Intel Core i7(10th Gen)"};
    static constexpr std::array<const char*, 10> computerName = {"Dell Inspiron 15 5590", "Asus X412FA-EK361T", "Lenovo Ideapad 330", "Huawei Mach-W19B", "Apple MacBook Air", "HP 15s-du1034tu", "Acer Aspire ES1-571", "HP 15-DA0070TX", "Lenovo Ideapad 300", "HP Pavilion 15-ac028TX"};
    static constexpr std::array<int, 10> computerPrices = {66490, 40000, 44000, 77899, 118990, 53999, 25655, 49279, 43000, 64000};
    
    Node* next = nullptr;
};

// Pointer declarations
Node* startPtr = nullptr;
Node* head = nullptr;
Node* last = nullptr;