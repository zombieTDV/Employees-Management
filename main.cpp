#include "Linked_list.h"
#include "menu.h"

int main(){
    Node *head = NULL;
    menu(head);
    // head = new Node{{"E001","Alice",{1,1,1990},"alice@mail.com","123 Street","0123456789",20,100.0f}, nullptr};
    // string S = "  nguyen  VAN   aN   ";
    // S = standardize(S);
    // cout << S << '\n';
    // cout << "   THEM MOI NV" << endl;
    clean(head);
    return 0;
}
