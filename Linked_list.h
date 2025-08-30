#pragma once
#include "Employee.h"
#include <sstream>
#include <string>
#include <iomanip>

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


//kich thuoc của node
int Size(node a){
	int cnt = 0;
	while(a != NULL){
		++cnt;
		a = a->next; // gan dia chi cua not tiep theo cho node hien tai
		//cho node hien tai nhay sang not tiep theo
	}
	return cnt;
}



//in dl ra màn hình cua 1 nv
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

void display(node &head) {
    if (head == NULL) {
        cout << "Employee list is empty." << endl;
        return;
    }
    cout << left << setw(10) << "Emp ID"
         << left << setw(25) << "Full Name"
         << left << setw(15) << "Birthdate"
         << left << setw(25) << "Email"
         << left << setw(25) << "Address"
         << left << setw(15) << "Phone"
         << left << setw(15) << "Work Days"
         << left << setw(15) << "Daily wage"
         << left << setw(15) << "Total income" << endl;
    cout << setfill('-') << setw(165) << "" << setfill(' ') << endl;

    node p = head;
    while (p != NULL) {
        cout << left << setw(10) << p->data.employeeID
             << left << setw(25) << p->data.name
             << left << setw(2) << p->data.birthDate.day << "/"
             << left << setw(2) << p->data.birthDate.month << "/"
             << left << setw(7) << p->data.birthDate.year
             << left << setw(25) << p->data.email
             << left << setw(25) << p->data.address
             << left << setw(15) << p->data.phone
             << left << setw(20) << p->data.workingDays
             << left << setw(15) << p->data.dailySalary
             << left << setw(15) << p->data.workingDays * p->data.dailySalary << endl;
        p = p->next;
    }
}

// chuẩn hoá
string standardize(string s) {
    stringstream ss(s);
    string word;
    s.clear(); //xóa chuỗi s -> s trống

    while (ss >> word) {           // stringstream ss tự động bỏ qua 'tất cả' khoảng trống (space) và lấy ra từng từ liên tiếp.
        for (size_t i = 1; i < word.size(); i++) {
            word[i] = tolower(word[i]);
        }
        word[0] = toupper(word[0]); //Viết hoa chữ cái đầu của họ tên, CHỈ THÍCH HỢP KHI DÙNG ĐỂ CHUẨN HÓA HỌ VÀ TÊN!
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
            cout << "Ends of file." << '\n';
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
node findByID(node a, const string& id) {
    node p = a;
    while (p != NULL) {
        if (p->data.employeeID == id) {
            return p; //Trả về con trỏ
        }
        p = p->next;
    }
    return NULL;//kh tìm thấy
}
/*(9). XÓA 1 NHÂN VIÊN THEO MÃ
   9.1. Hàm trả về thêm thông tin node đứng trước node cần tìm( hỗ trợ thao tác xóa )
   9.2. Hàm xóa nv */
node searchID2(node head, node &q, string id)
{
    node p = head;
    q = NULL;
    while(p != NULL)
    {
        if(p->data.employeeID == id)
            break;
        q = p; // Lưu nút đứng trước
        p = p->next; // Nhảy tới nút tiếp theo
    }
    return p;
}
void deleteID(node &head)
{
    string x;
    cout << "Enter the employee ID to search: "; getline(cin, x);
    node q = NULL;
    node p = searchID2(head, q, x);
    if(p == NULL)
    {
        cout << "Not found!\n";
        return;
    }

    if(q != NULL){
        q->next = p->next;
    } else {
        head = p->next; // Cập nhật head nếu xóa nút đầu tiên
    }

    delete p;

    cout << "Successfully deleted!\n";

    display(head);
}
/* (10). Thêm mới nhân viên
   10.1. Hàm ktra dl
   10.2. Hàm thêm ptu vào đầu, cuối, giữa
   10.3. Hàm nhập thông tin nhân viên
   10.4. Thêm nhân viên vào danh sách */

//10.1.a Ktra mã nv trùng kh?
bool checkID(node a, const string &id)
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
//10.1.d Ktra các gtri: số ngày công trong tháng
bool checkWage(int workingDays)
{
       // ngày công [0,31]
       return !(workingDays < 0 || workingDays > 31);
}
bool checkWage(double dailySalary)
{
       return dailySalary > 0;
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
Employee inputEmp(node a)
{
       Employee e;

       //Nhap ma
       do{
              cout << "Enter employee code: "; getline(cin, e.employeeID);
              if(!checkID(a, e.employeeID))
              {
                     cout << "Error: Employee code already exists!\n";
              }
       } while (!checkID(a, e.employeeID));
       //Nhap ho ten
       cout << "Enter full name: ";
       getline(cin, e.name);
       e.name = standardize(e.name);
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
       e.address = standardize(e.address);
       //Nhap sdt
       do{
              cout << "Enter phone number: "; getline(cin, e.phone);
              if(!checkPhone(e.phone))
              {
                     cout << "Error: Invalid!\n";
              }
       } while(!checkPhone(e.phone));
       //Nhap ngay cong
       do {
              cout << "Enter working days: ";
              cin >> e.workingDays;
              if (!checkWage(e.workingDays)) {
                     cout << "Error: Working days must be between 0 and 31!\n";
              }
         } while (!checkWage(e.workingDays));
       //Nhap ngay luong
       do {
             cout << "Enter daily salary: ";
             cin >> e.dailySalary;
             if (!checkWage(e.dailySalary)) {
                    cout << "Error: Daily salary must be greater than 0!\n";
             }
       } while (!checkWage(e.dailySalary));


       cin.ignore(); // Xóa \n còn trong bộ đệm
       cout << "Total income: " << e.workingDays * e.dailySalary << endl;
       return e;

}
//10.4. Thêm nhân viên vào danh sách
void addEmp(node &head)
{
       Employee e = inputEmp(head);
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
                     cin.ignore();
                     insertMiddle(head, e, pos);
                     break;
              }
              else {
                     cout << "Invalid choice. Try again.\n"; break;
              }
       }

}
/* (11). SỬA THÔNG TIN 1 NHÂN VIÊN
          +Tìm nhân viên theo mã - findByID(node head, const string& id)
          +Thấy-> Gọi lại hàm nhập (bỏ qua nhập id), cập nhật lại dl */
//Hàm nhập lại thông tin nhân viên bỏ qua nhập id
Employee inputEmpNOID(node &a)
{
       Employee e = a->data;
       //Nhap ho ten
       cout << "Enter full name: ";
       getline(cin, e.name);
       e.name = standardize(e.name);
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
       e.address = standardize(e.address);
       //Nhap sdt
       do{
              cout << "Enter phone number: "; getline(cin, e.phone);
              if(!checkPhone(e.phone))
              {
                     cout << "Error: Invalid!\n";
              }
       } while(!checkPhone(e.phone));
       //Nhap ngay cong
       do {
              cout << "Enter working days: ";
              cin >> e.workingDays;
              if (!checkWage(e.workingDays)) {
                     cout << "Error: Working days must be between 0 and 31!\n";
              }
         } while (!checkWage(e.workingDays));
       //Nhap ngay luong
       do {
             cout << "Enter daily salary: ";
             cin >> e.dailySalary;
             if (!checkWage(e.dailySalary)) {
                    cout << "Error: Daily salary must be greater than 0!\n";
             }
       } while (!checkWage(e.dailySalary));



       cin.ignore(); // Xóa \n còn trong bộ đệm
       cout << "Total income: " << e.workingDays * e.dailySalary << endl;
       return e;
}
void editEmp(node &head)
{
       string id;
       cout << "Enter employee code to edit: "; getline(cin, id);

       node p = findByID(head, id);
       if(p == NULL)
       {
              cout << "Not found!\n";
              return;
       }

       //-NHẬP LẠI THÔNG TIN(bỏ qua id)
       cout << "EDITTING EMPLOYEE WITH ID: " << id << endl;
       Employee newData = inputEmpNOID(head);
       newData.employeeID = p->data.employeeID; // giữ id cũ
       p->data = newData; //gán lại dữ liệu
       display_an_employee(newData);
       cout << "Updated successfully!\n";
}



// Tìm theo tên
void findByName(node &head, string name) {
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

// Xuất danh sách nhân viên có thực lĩnh thấp nhất
void displayLowestSalary(node &head) {
    if (head == NULL) {
        cout << "Empty list\n";
        return;
    }

    float minSalary = head->data.workingDays * head->data.dailySalary;
    Node* p = head->next;

    // Tìm mức lương thấp nhất
    while (p != NULL) {
        float salary = p->data.workingDays * p->data.dailySalary;
        if (salary < minSalary) {
            minSalary = salary;
        }
        p = p->next;
    }

    // In ra các nhân viên có mức lương thấp nhất
    cout << "\nEmployees with the lowest net salary::\n";
    p = head;
    while (p != NULL) {
        float salary = p->data.workingDays * p->data.dailySalary;
        if (salary == minSalary) {
            display_an_employee(p->data);
            cout << "----------------------\n";
        }
        p = p->next;
    }
}

// Sắp xếp danh sách nhân viên giảm dần theo thực lĩnh -- Dùng Bubble Sort
void sortBySalaryDesc(node &head)
{
	if (head == NULL || head->next == NULL) {
		return; // Danh sách rỗng hoặc chỉ có một phần tử
	}
	for (Node* i = head; i != NULL; i = i->next) {
		for (Node* j = i->next; j != NULL; j = j->next) {
			float salaryI = i->data.workingDays * i->data.dailySalary;
			float salaryJ = j->data.workingDays * j->data.dailySalary;

            if (salaryI < salaryJ) {
                Employee temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
		}
	}
}

//giải phóng bộ nhớ
void deleteFirst(node& a) {
    if (a == NULL) return;
    Node* temp = a;      // lưu node đầu
    a = a->next;         // up mới head
    delete temp;         
}

void clean(node& a) {
    while (a != NULL) 
    {
        deleteFirst(a);   // dùng lại hàm deleteFirst luôn 
    }
}


