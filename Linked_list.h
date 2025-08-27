#pragma once
#include "Employee.h"
#include <sstream>
#include <string>

using namespace std;

struct Node
{
    Employee data;
    Node* next;
};
typedef Node* node;

Node* createNode(Employee emp)
{
    Node* p = new Node;
    if (p == NULL)
        return NULL;
    p->data = emp;
    p->next = NULL;
    return p;
}
//in dl ra màn hình
void display_an_employee(Employee emp)
{
       cout << "Employee code: " << emp.employeeID << endl;
       cout << "Employee name: " << emp.name << endl;
       cout << "Date of birth: " << emp.birthDate.day << "/" << emp.birthDate.month << "/" << emp.birthDate.year << endl;
       cout << "Email: " << emp.email << endl;
       cout << "Contact address: " << emp.address << endl;
       cout << "Phone number: " << emp.phone << endl;
       cout << "Number of working days per month: " << emp.workingDays << endl;
       cout << "Daily wage: " << emp.dailySalary << endl;
       cout << "Total income: " << emp.workingDays*emp.dailySalary << endl;
}
void display(Node* head)
{
       Node* p = head;
       while( p != NULL)
       {
              display_an_employee(p->data);
              p = p->next;
       }
}


// chuẩn hoá
string standardize(string s) {
    stringstream ss(s);
    string word;
    s.clear(); //xóa chuỗi s -> s trống

    while (ss >> word) {           // stringstream ss tự động bỏ qua 'tất cả' khoảng trống (space) và lấy ra từng từ liên tiếp.
        word[0] = toupper(word[0]);
        for (size_t i = 1; i < word.size(); i++) {
        word[i] = tolower(word[i]); 
        }
        if (!s.empty()) {
            s += ' '; // kiểm tra s có trống? Nếu không, nghĩa là s không phải đầu chuỗi -> thêm khoảng trắng
        }
        s += word;
    }
    return s;
}

//Ghi toàn bộ danh sách liên kết nhân viên ra file
void writeListToFile(Node* head, const string& filename) {
    ofstream out(filename);
    if (!out) {
        cerr << "Cannot open file for writing\n";
        return;
    }
    for (Node* cur = head; cur != nullptr; cur = cur->next) { //Lần lượt đọc các thuộc tính của Các Node và viết vào các dòng của file txt
        out << cur->data.employeeID << '\n'
            << cur->data.name << '\n'
            << cur->data.birthDate.day << ' '
            << cur->data.birthDate.month << ' '
            << cur->data.birthDate.year << '\n'
            << cur->data.email << '\n'
            << cur->data.address << '\n'
            << cur->data.phone << '\n'
            << cur->data.workingDays << '\n'
            << cur->data.dailySalary << '\n';
    }
    out.close();
}


//Đọc dữ liệu từ file
Node* readListFromFile(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Cannot open file for reading\n";
        return nullptr;
    }
    Node* head = nullptr; //Khởi tạo con trỏ vào Node đầu tiên
    Node* pNode = nullptr; //Khởi tạo con trỏ cho để truy cập các Node dữ liệu.

    while (true) { //Khởi tạo dữ liệu Nhân Viên, đọc lần lượt các dòng từ file .txt và đặc các thuộc tính cho nhân viên
        Employee emp;
        if (!getline(in, emp.employeeID)){
            cout << "Error when read from file." << '\n';
            break;
        };
        getline(in, emp.name);
        in >> emp.birthDate.day >> emp.birthDate.month >> emp.birthDate.year;
        in.ignore();
        getline(in, emp.email);
        getline(in, emp.address);
        getline(in, emp.phone);
        in >> emp.workingDays;
        in >> emp.dailySalary;
        in.ignore();

        Node* newNode = new Node{emp, nullptr}; //Tạo Node mới với dữ liệu nhân viên vừa đọc.
        if (head == nullptr){
            head = newNode;
            pNode = newNode;
        }
        else{ //Đặt node->next = newNode và chuyển pNode = newNode
            pNode->next = newNode;
            pNode = newNode;
        }

    }
    in.close();
    return head;
}
// Tìm theo ID
void findByID(node head, const string& employeeId) {
    node p = head;
    bool found = false;
    while (p != NULL) {
        if (p->data.employeeID == employeeId) {
            cout << "Employee:\n";
            display_an_employee(p->data);
            found = true;
            break;
        }
        p = p->next;
    }
    if (!found) {
        cout << "There is no employee with that ID: " << employeeId << endl;
    }
}
// Tìm theo tên
void findByName(node head, string name) {
    string target = standardize(name);
    node p = head;
    bool found = false;
    while (p != NULL) {
        if (p->data.name == target) {  // so sánh tên chuẩn hoá
            display_an_employee(p->data);
            found = true;
        }
        p = p->next;
    }
    if (!found) {
        cout << "There is no employee with that name: " << target << endl;
    }
}