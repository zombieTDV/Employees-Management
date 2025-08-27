#include "Linked_list.h"

int main(){
    // Create some test data
    Node* head = new Node{
        {"E001","Alice",{1,1,1990},"alice@mail.com","123 Street","0123456789",20,100.0f}, nullptr
    };
    head->next = new Node{
        {"E002","Bob",{2,2,1992},"bob@mail.com","456 Avenue","0987654321",18,120.0f}, nullptr
    };

    writeListToFile(head, "employees.txt");

    Node* listFromFile = readListFromFile("employees.txt");
    // You can print the loaded list here to verify

    return 0;
}