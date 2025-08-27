#pragma once;
#include "Employee.h"

struct Node
{
    Employee data;
    Node* next;
};

typedef Node* node;

node createNode(Employee emp)
{
    node p = new Node;
    if (p == NULL)
        return NULL;
    p->data = emp;
    p->next = NULL;
    return p;
}
//in dl ra màn hình
void display_an_empoyee(Empoyee emp)
{
       cout << "Employee code: " << emp.employeeID << endl;
       cout << "Employee name: " << emp.name << endl;
       cout << "Date of birth: " << emp.birthDate << endl;
       cout << "Email: " << emp.email << endl;
       cout << "Contact address: " << emp.address << endl;
       cout << "Phone number: " << emp.phone << endl;
       cout << "Number of working days per month: " << emp.workingDays << endl;
       cout << "Daily wage: " << emp.dailySalary << endl;
       cout << "Total income: " << emp.workingDays*emp.dailySalary << endl;
}
void display(node head)
{
       node p = head;
       while( p != NULL)
       {
              display_an_empoyee(p->data);
              p = p->next;
       }
}


int main()
{
     node head = NULL;

}
