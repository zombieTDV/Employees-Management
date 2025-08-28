#include "Linked_list.h"


int main(){
    Node* head = NULL;
    LIST l1;
    l1.head = NULL;
    //menu(head);
    string S = "  nguyen  VAN   aN   ";
    S = standardize(S);
    cout << S << '\n';
    addEmp(l1);
    deleteID(l1);
    display(l1);
    return 0;
}
