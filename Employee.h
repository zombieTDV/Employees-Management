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
    //float netSalary: t bỏ cái này nha, biến này chỉ dùng để tính kh cần khai báo
};
struct Node
{
    Employee data;
    Node* next;
};
// thêm List để quản lý danh sách
struct LIST
{
       Node *head; //con trỏ đầu danh sách
};
