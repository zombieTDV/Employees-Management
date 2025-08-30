#include "Linked_list.h"
// Khung menu chính
void menu(node &head)
{
    int choice;
    do {
        cout << "\n========== EMPLOYEE MANAGEMENT MENU ==========\n";
        cout << "1. Enter employee list from keyboard\n";
        cout << "2. Read employee list from file\n";
        cout << "3. Display employee list on screen\n";
        cout << "4. Save employee list to file\n";
        cout << "5. Find employee by ID\n";
        cout << "6. Find employee by name (case-insensitive)\n";
        cout << "7. Display employee with the lowest net salary\n";
        cout << "8. Sort list in descending order by net salary\n";
        cout << "9. Delete employee by ID\n";
        cout << "10. Add new employee\n";
        cout << "11. Edit employee information\n";
        cout << "0. Exit\n";
        cout << "==============================================\n";
        cout << "Select a function: ";
        cin >> choice;
        cin.ignore();

switch (choice) {
    case 1: {
        int n;
        cout << "Enter number of employees: ";
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            cout << "\n--- Employee " << i + 1 << " ---\n";
            addEmp(head);
        }
        break;
    }
    case 2: {
        string filename;
        cout << "Enter filename to read: ";
        getline(cin, filename);
        head = readListFromFile(filename);
        break;
    }
    case 3:
        display(head);
        break;
    case 4: {
        string filename;
        cout << "Enter filename to write: ";
        getline(cin, filename);
        writeListToFile(head, filename);
        cout << "File written successfully!\n";
        break;
    }
    case 5: {
        string id;
        cout << "Enter employee ID to search: ";
        getline(cin, id);
        node p = findByID(head, id);
        if (p != NULL)
            display_an_employee(p->data);
        else
            cout << "Not found!\n";
        break;
    }
    case 6: {
        string name;
        cout << "Enter employee name to search: ";
        getline(cin, name);
        findByName(head, name);
        break;
    }
    case 7:
        displayLowestSalary(head);
        break;
    case 8:
        sortBySalaryDesc(head);
        cout << "Sorted in descending order by net salary.\n";
        break;
    case 9:
        deleteID(head);
        break;
    case 10:
        addEmp(head);
        break;
    case 11:
        editEmp(head);
        break;
    case 0:
        cout << "Exiting program.\n";
        break;
    default:
        cout << "Invalid choice, please try again.\n";
        }
    }while (choice != 0);
}