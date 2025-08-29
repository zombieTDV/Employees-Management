#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct Date
{
    int day, month, year;
};

struct Employee
{
    string employeeID;
    string name;
    Date birthDate;
    string email;
    string address;
    string phone;
    int workingDays;
    float dailySalary;
};
struct NODE
{
    Employee data;
    struct NODE *pNext;
};
struct list
{
    NODE* pHead;
    NODE* pTail;
};
typedef struct list List;
NODE* initialize the list(Employee x)
{
    NODE* p = new NODE;
    if (p == NULL)
    {
        cout << "\n allocation failed  !";
        return NULL;
    }
    p->data = x;
    p->pNEXT = NULL;
    return p;
}
void read Employee(ifstream &filein, Employee &employee)
{
    filein >> employee.employeeID;
    filein >> emplyee.lastName;
    filein >> emplyee.firstName;
    filein >> emplyee.email;
    filein >> emplyee.address;
    filein >> emplyee.phoneNumber;
    filein >> emplyee.workingDays;
    filein >> emplyee.dailySalary;
    filein >> emplyee.netSalary;
}
void date(ifstream &filein, date Date)
{
    filein >> Date.day;
    filein.seekg(1, 1);
    filein >> Date.month;
    filein.seekg(1, 1);
    filein >> Date.year;
}
Employee InputEmployee()
{
    Employee emp;
    cout << "Enter employee ID: ";
    getline(cin, emp.employeeID);
    cout << "Enter last name: ";
    getline(cin, emp.lastName);
    cout << "Enter first name: ";
    getline(cin, emp.firstName);
    cout << "Enter birth date: ";
    getline(cin, emp.birthDate);
    cout << "Enter email: ";
    getline(cin, emp.email);
    cout << "Enter address: ";
    getline(cin, emp.address);
    cout << "Enter phone number: ";
    cin >> emp.phoneNumber;
    cout << "Enter number of working days: ";
    cin >> emp.workingDays;
    cout << "Enter daily salary: ";
    cin >> emp.dailySalary;
    cin.ignore();

    emp.calculateNetSalary();
    return emp;
};














