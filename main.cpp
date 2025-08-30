#include "Linked_list.h"


int main(){
    Node *head = NULL;
    menu(head);


    head = new Node{{"E001","Alice",{1,1,1990},"alice@mail.com","123 Street","0123456789",20,100.0f}, nullptr};
    cout << "   THEM MOI NV" << endl;
    addEmp(head);

    //cout << "   XOA NV THEO ID" << endl;
    //deleteID(head);

    //cout << "   SUA INFO NHAN VIEN" << endl;
    editEmp(head);

    display(head);

    clean(head);
    return 0;
}
