#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const char* fileName = "Employee.txt";

class Employee {
private:
    int EmpID;
    string EmpName;
    string Post;
    string Department;
    float Salary;

public:
    void ReadData();
    int GetID() const;
    void DisplayRecord() const;
    string GetDepartment() const;
};

void Employee::ReadData() {
    cout << "\nEmployee ID: ";
    cin >> EmpID;
    cin.ignore(); // Clear newline from buffer

    cout << "Employee Name: ";
    getline(cin, EmpName);

    cout << "Employee's Post: ";
    getline(cin, Post);

    cout << "Employee's Department: ";
    getline(cin, Department);

    cout << "Salary: ";
    cin >> Salary;
}

void Employee::DisplayRecord() const {
    cout << endl << "----------------------------------------------";
    cout << endl << setw(5) << EmpID << setw(15) << EmpName << setw(15) << Post
         << setw(15) << Department << setw(10) << Salary;
}

int Employee::GetID() const {
    return EmpID;
}

string Employee::GetDepartment() const {
    return Department;
}

int main() {
    Employee emp, e;
    char option, ch;
    string Dept;
    int ID, isFound;
    fstream file;

    file.open(fileName, ios::in | ios::out | ios::binary | ios::app);
    if (!file) {
        cout << "Error opening file. Creating a new file..." << endl;
        file.open(fileName, ios::out | ios::binary);
        file.close();
        file.open(fileName, ios::in | ios::out | ios::binary | ios::app);
    }

    do {
        cout << "\n******* Menu *******";
        cout << "\n1 => Add a new record";
        cout << "\n2 => Search record by employee ID";
        cout << "\n3 => List employees of a department";
        cout << "\n4 => Display all employees";
        cout << "\n5 => Update employee record";
        cout << "\n6 => Delete employee record";
        cout << "\n7 => Exit";
        cout << "\n*********************";
        cout << "\nEnter your option: ";
        cin >> option;
        cin.ignore(); // Clear newline

        switch (option) {
        case '1': {
            emp.ReadData();
            fstream checkFile(fileName, ios::in | ios::binary);
            isFound = 0;

            while (checkFile.read((char*)&e, sizeof(Employee))) {
                if (e.GetID() == emp.GetID()) {
                    cout << "This ID already exists. Try another.\n";
                    isFound = 1;
                    break;
                }
            }
            checkFile.close();

            if (!isFound) {
                file.write((char*)&emp, sizeof(Employee));
                cout << "\nNew record added successfully.";
            }
            break;
        }

        case '2': {
            cout << "\nEnter Employee ID to search: ";
            cin >> ID;
            isFound = 0;
            file.clear();
            file.seekg(0, ios::beg);

            while (file.read((char*)&e, sizeof(Employee))) {
                if (e.GetID() == ID) {
                    cout << "\nRecord Found:\n";
                    cout << setw(5) << "ID" << setw(15) << "Name" << setw(15)
                         << "Post" << setw(15) << "Department" << setw(10) << "Salary";
                    e.DisplayRecord();
                    isFound = 1;
                    break;
                }
            }
            if (!isFound)
                cout << "\nNo record found for ID #" << ID;
            break;
        }

        case '3': {
            cout << "Enter Department name: ";
            getline(cin, Dept);
            isFound = 0;
            file.clear();
            file.seekg(0, ios::beg);

            while (file.read((char*)&e, sizeof(Employee))) {
                if (e.GetDepartment() == Dept) {
                    if (!isFound) {
                        cout << setw(5) << "ID" << setw(15) << "Name" << setw(15)
                             << "Post" << setw(15) << "Department" << setw(10) << "Salary";
                    }
                    e.DisplayRecord();
                    isFound = 1;
                }
            }
            if (!isFound)
                cout << "\nNo employees found in department " << Dept;
            break;
        }

        case '4': {
            cout << "\nAll Employee Records:\n";
            file.clear();
            file.seekg(0, ios::beg);
            int count = 0;
            while (file.read((char*)&e, sizeof(Employee))) {
                if (count == 0) {
                    cout << setw(5) << "ID" << setw(15) << "Name" << setw(15)
                         << "Post" << setw(15) << "Department" << setw(10) << "Salary";
                }
                e.DisplayRecord();
                count++;
            }
            if (count == 0)
                cout << "\nNo records found.";
            else
                cout << "\n\n" << count << " record(s) found.";
            break;
        }

        case '5': {
            cout << "\nEnter Employee ID to update: ";
            cin >> ID;
            isFound = 0;
            fstream temp("temp.txt", ios::out | ios::binary);
            file.clear();
            file.seekg(0, ios::beg);

            while (file.read((char*)&e, sizeof(Employee))) {
                if (e.GetID() == ID) {
                    cout << "\nOld Record:";
                    e.DisplayRecord();
                    cout << "\nEnter New Details:";
                    emp.ReadData();
                    temp.write((char*)&emp, sizeof(Employee));
                    isFound = 1;
                } else {
                    temp.write((char*)&e, sizeof(Employee));
                }
            }
            file.close();
            temp.close();
            remove(fileName);
            rename("temp.txt", fileName);
            file.open(fileName, ios::in | ios::out | ios::binary | ios::app);
            if (isFound)
                cout << "\nRecord updated successfully.";
            else
                cout << "\nRecord not found.";
            break;
        }

        case '6': {
            cout << "\nEnter Employee ID to delete: ";
            cin >> ID;
            isFound = 0;
            fstream temp("temp.txt", ios::out | ios::binary);
            file.clear();
            file.seekg(0, ios::beg);

            while (file.read((char*)&e, sizeof(Employee))) {
                if (e.GetID() != ID) {
                    temp.write((char*)&e, sizeof(Employee));
                } else {
                    cout << "\nDeleted Record:";
                    e.DisplayRecord();
                    isFound = 1;
                }
            }
            file.close();
            temp.close();
            remove(fileName);
            rename("temp.txt", fileName);
            file.open(fileName, ios::in | ios::out | ios::binary | ios::app);
            if (isFound)
                cout << "\nRecord deleted successfully.";
            else
                cout << "\nRecord not found.";
            break;
        }

        case '7':
            cout << "\nExiting the program.";
            return 0;

        default:
            cout << "\nInvalid option. Try again.";
        }

        cout << "\nDo you want to continue (y/n)? ";
        cin >> ch;
        cin.ignore(); // Clear newline

    } while (ch != 'n' && ch != 'N');

    file.close();
    return 0;
}


// ******* Menu *******
// 1 => Add a new record
// 2 => Search record by employee ID
// 3 => List employees of a department
// 4 => Display all employees
// 5 => Update employee record
// 6 => Delete employee record
// 7 => Exit
// *********************
// Enter your option: 1

// Employee ID: 101
// Employee Name: Vinayak
// Employee's Post: Java Developer
// Employee's Department: IT
// Salary: 45000
// This ID already exists. Try another.

// Do you want to continue (y/n)? y

// ******* Menu *******
// 1 => Add a new record
// 2 => Search record by employee ID
// 3 => List employees of a department
// 4 => Display all employees
// 5 => Update employee record
// 6 => Delete employee record
// 7 => Exit
// *********************
// Enter your option: 1

// Employee ID: 102
// Employee Name: Trushant
// Employee's Post: SAP Engineer
// Employee's Department: IT
// Salary: 50000

// New record added successfully.
// Do you want to continue (y/n)? y

// ******* Menu *******
// 1 => Add a new record
// 2 => Search record by employee ID
// 3 => List employees of a department
// 4 => Display all employees
// 5 => Update employee record
// 6 => Delete employee record
// 7 => Exit
// *********************
// Enter your option: 5

// Enter Employee ID to update: 102

// Old Record:
// ----------------------------------------------
//   102       Trushant   SAP Engineer             IT     50000
// Enter New Details:
// Employee ID: 102
// Employee Name: Soham
// Employee's Post: SAP Engineer
// Employee's Department: SAP
// Salary: 51000

// Record updated successfully.
// Do you want to continue (y/n)? y

// ******* Menu *******
// 1 => Add a new record
// 2 => Search record by employee ID
// 3 => List employees of a department
// 4 => Display all employees
// 5 => Update employee record
// 6 => Delete employee record
// 7 => Exit
// *********************
// Enter your option: 6

// Enter Employee ID to delete: 102

// Deleted Record:
// ----------------------------------------------
//   102          Soham   SAP Engineer            SAP     51000
// Record deleted successfully.
// Do you want to continue (y/n)? y

// ******* Menu *******
// 1 => Add a new record
// 2 => Search record by employee ID
// 3 => List employees of a department
// 4 => Display all employees
// 5 => Update employee record
// 6 => Delete employee record
// 7 => Exit
// *********************
// Enter your option: 7

// Exiting the program.% 