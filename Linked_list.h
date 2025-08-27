#pragma once
#include "Employee.h"
#include <sstream>
#include <string>


struct Node
{
    Employee data;
    Node* next;
};


Node* createNode(Employee emp)
{
    Node* p = new Node;
    if (p == NULL)
        return NULL;
    p->data = emp;
    p->next = NULL;
    return p;
}

//kich thuoc của node
int Size(Node* a){
	int cnt = 0;
	while(a != NULL){
		++cnt;
		a = a->next; // gan dia chi cua not tiep theo cho node hien tai
		//cho node hien tai nhay sang not tiep theo
	}
	return cnt;
}
//in dl ra m�n h�nh
void display_an_empoyee(Employee emp)
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
              display_an_empoyee(p->data);
              p = p->next;
       }
}

//chuẩn hóa chuỗi ký tự
void standardize(string& s) {
    stringstream ss(s);
    string word;
    s.clear(); //xóa chuỗi s -> s trống

    while (ss >> word) {           // stringstream ss tự động bỏ qua 'tất cả' khoảng trống (space) và lấy ra từng từ liên tiếp.
        word[0] = toupper(word[0]);
        if (!s.empty()) {
            s += ' '; // kiểm tra s có trống? Nếu không, nghĩa là s không phải đầu chuỗi -> thêm khoảng trắng
        }
        s += word;
    }
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

/* (10). Thêm mới nhân viên
   10.1. Hàm ktra dl
   10.2. Hàm thêm ptu vào đầu, cuối, giữa
   10.3. Hàm nhập thông tin nhân viên
   10.4. Thêm nhân viên vào danh sách */

//10.1.a Ktra mã nv trùng kh?
bool checkID(Node *a, const string &id)
{
       Node* p = a;
       while(p != NULL)
       {
              if(p->data.employeeID == id)
              {
                     return false; //Tìm ra mã trùng
              }
              p = p->next;
       }
       return true; // kh trùng
}
//10.1.b ktra ngày tháng năm đúng định dạng
bool LeapYear(int year) //ktra năm nhuận?
{
       return (year % 400 == 0) || ( year%4 == 0 && year%100 != 0 );
}
bool checkDate(const string &date)
{
       int day, month, year;
       char sep1, sep2;

       stringstream ss(date);
       ss >> day >> sep1 >> month >> sep2 >> year;

       // Kiểm tra tách thành công và đúng định dạng dd/mm/yyyy
       if (!ss || sep1 != '/' || sep2 != '/') return false;

       if (year <= 0) return false;
       if (month < 1 || month > 12) return false;

       int daysInMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
       if (LeapYear(year)) daysInMonth[2] = 29;

       if (day < 1 || day > daysInMonth[month]) return false;

       return true;

}
//10.1.c Ktra sdt phù hợp kh?
bool checkPhone(const string &numberPhone)
{
       //ktra kí tự đầu tiên phải là '0' và độ dài = 10
       if (numberPhone.length() != 10) return false;
       if (numberPhone[0] != '0') return false;

       //ktra tất cả kí tự là số kh?
       for( char c : numberPhone)
       {
              if (!isdigit(static_cast<unsigned char>(c)))
              {
                     return false;
              }
       }
       return true; // hợp lệ
}
//10.1.d Ktra các gtri: số ngày công trong tháng, lương
bool checkWage(int workingDays, double dailySalary)
{
       // ngày công [0,31]
       if(workingDays < 0 || workingDays > 31)
       {
              return false;
       }
       if(dailySalary <= 0)
       {
              return false;
       }
       return true;
}
//10.2.a Thêm vào đầu danh sách liên kết
void insertFirst(Node* &a, Employee x){
	Node* tmp = createNode(x);
	if(a == NULL){
		a = tmp;
	}
	else{
		tmp->next = a; //cho nút mới (tmp) trỏ tới nút đầu hiện tại (a).
		a = tmp; //Cập nhật lại đầu danh sách thành nút mới tmp
	}
}
//10.2.b Thêm vào cuối danh sách liên kết
void insertLast(Node* &a, Employee x){
	Node* tmp = createNode(x);
	if(a == NULL){
		a = tmp;
	}
	else{
		Node* p = a;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = tmp;
	}
}
//10.2.c Thêm vào giữa danh sách liên kết
void insertMiddle(Node* &a, Employee x, int pos){
	int n = Size(a);
	if(pos <= 0 || pos > n + 1){
		cout << "Vi tri them khong hop le !\n";
	}
	if(pos == 1){
		insertFirst(a, x); return;
	}
	else if(pos == n +1 ){
		insertLast(a, x); return;
	}
	Node* p = a;
	for(int i = 1; i < pos - 1; i++){
		p = p->next;
	}
	Node* tmp = createNode(x);
	tmp->next = p->next;
	p->next = tmp;
}
//10.3 Nhap nhan vien
Employee inputEmp(Node * head)
{
       Employee e;

       //Nhap ma
       do{
              cout << "Enter employee code: "; getline(cin, e.employeeID);
              if(!checkID(head, e.employeeID))
              {
                     cout << "Error: Employee code already exists!\n";
              }
       } while (!checkID(head, e.employeeID));
       //Nhap ho ten
              cout << "Enter full name: ";getline(cin, e.name);
       //Nhap ngay sinh
       string birth;
       do {
        cout << "Enter birthdate (dd/mm/yyyy): ";
        getline(cin, birth);

       if (!checkDate(birth)) {
        cout << "Error: Invalid!\n";
            }
       } while (!checkDate(birth));

       sscanf(birth.c_str(), "%d/%d/%d", &e.birthDate.day, &e.birthDate.month, &e.birthDate.year);

       //Nhap email
       cout << "Enter email: "; getline(cin, e.email);
       //Nhap dia chi
       cout << "Enter address: "; getline(cin, e.address);
       //Nhap sdt
       do{
              cout << "Enter phone number: "; getline(cin, e.phone);
              if(!checkPhone(e.phone))
              {
                     cout << "Error: Invalid!\n";
              }
       } while(!checkPhone(e.phone));
       //Nhap ngay cong va luong
       do{
              cout << "Enter working days: "; cin >> e.workingDays;
              cout << "Enter daily salary: "; cin >> e.dailySalary;
              if(!checkWage(e.workingDays, e.dailySalary))
              {
                     cout << "Error: Invalid!\n";
              }
       } while(!checkWage(e.workingDays, e.dailySalary));

       cin.ignore();
       cout << "Total income: " << e.workingDays * e.dailySalary << endl;

       return e;
}
//10.4. Thêm nhân viên vào danh sách
void addEmp(Node* &head)
{
       Employee e = inputEmp(head);
       //menu vtri chen
       while(1){
              cout << "\nWHERE DO YOU WANT TO INSERT THE NEW EMPLOYEE ?\n";
              cout << "1. Beginning of the list\n";
              cout << "2. End of the list\n";
              cout << "3. After a specific employee\n";

              int choice; cin >> choice;
              cin.ignore();

              if(choice == 1)
              {
                     insertFirst(head, e);
                     break;
              }
               else if(choice == 2)
              {
                     insertLast(head, e);
                     break;
              }
              else if(choice == 3)
              {
                     int pos; cout << "Enter the position to insert: "; cin >> pos;
                     insertMiddle(head, e, pos);
                     break;
              }
              else {
                     cout << "Invalid choice. Try again.\n";
              }
       }

}
