#pragma once;
#include "Employee.h"

struct Node
{
    Employee data;
    Node* next;
};

typedef Node* LinkedList;

Node* createNode(Employee emp)
{
    Node* p = new Node;
    if (p == NULL)
        return NULL;
    p->data = emp;
    p->next = NULL;
    return p;
}

void createList(LinkedList &list)
{
    list = NULL;
}