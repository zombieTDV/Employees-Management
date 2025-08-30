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
