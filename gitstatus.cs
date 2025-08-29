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
NODE* initializelist(Employee x)
{
    NODE* p = new NODE;
    if (p == NULL)
    {
        cout << "\n allocation failed  !";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
void readEmployee(ifstream &filein, Employee &employee)
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
void readDate(ifstream &filein, Date &date)
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
    cout << "Enter full name: ";
    getline(cin, emp.name)
    cout << "Enter birth date (dd mm yyyy): ";
    cin >> emp.birthDate.day >> emp.birthDate.month >> emp.birthDate.year;
    cin.ignore();
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














