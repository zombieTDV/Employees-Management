#include "Linked_list.h"

int main(){
    // Node* head = new Node{
    //     {"E001","Alice",{1,1,1990},"alice@mail.com","123 Street","0123456789",20,100.0f}, nullptr
    // };
    // head->next = new Node{
    //     {"E002","Bob",{2,2,1992},"bob@mail.com","456 Avenue","0987654321",18,120.0f}, nullptr
    // };

    // writeListToFile(head, "employees.txt");

    // Node* listFromFile = readListFromFile("employees.txt");

    // cout << listFromFile->data.employeeID << '\n';
    // cout << listFromFile->next->data.employeeID << '\n';
    Node* head = NULL;
    string S = "  nuyeng  VAN   aH   ";
    standardize(S);
    cout << S << '\n';
    addEmp(head);
    return 0;
}
