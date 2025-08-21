#pragma once;

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Employee
{
    string employeeID;

    string lastName;
    string firstName;

    string birthDate;

    string email;

    string address;
    
    int phoneNumber;
    
    int workingDays;
    float dailySalary;
    float netSalary;

    void calculateNetSalary() {
        netSalary = workingDays * dailySalary;
    }
};