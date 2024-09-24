#include <iostream>
#include <string.h>

using namespace std;

struct Student {
    char regno[20];
    char name[50];
    char proctor[20];
    int cse1001;
    int cse1002;
};

Student students[100];
int student_count = 0;

void addNewStudents() {
    cout << "Enter the registration number: ";
    cin >> students[student_count].regno;

    cout << "Enter the name: ";
    cin >> students[student_count].name;

    cout << "Enter the proctor ID: ";
    cin >> students[student_count].proctor;

    // Initially setting marks to 0
    students[student_count].cse1001 = 0;
    students[student_count].cse1002 = 0;

    student_count++;
}

void studentLogin() {
    char regno[20];
    cout << "Enter the registration number: ";
    cin >> regno;

    bool found = false;
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].regno, regno) == 0) {
            cout << "Name: " << students[i].name << endl;
            cout << "CSE1001 marks: " << students[i].cse1001 << endl;
            cout << "CSE1002 marks: " << students[i].cse1002 << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Registration number not found!" << endl;
    }
}

void addMarks() {
    char regno[20];
    cout << "Enter the registration number: ";
    cin >> regno;

    bool found = false;
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].regno, regno) == 0) {
            cout << "Enter CSE1001 marks: ";
            cin >> students[i].cse1001;
            cout << "Enter CSE1002 marks: ";
            cin >> students[i].cse1002;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Registration number not found!" << endl;
    }
}

void viewAllStudents() {
    for (int i = 0; i < student_count; i++) {
        cout << "Reg No: " << students[i].regno << ", Name: " << students[i].name
             << ", CSE1001: " << students[i].cse1001 << ", CSE1002: " << students[i].cse1002 << endl;
    }
}

int main() {
    int option;

    while (true) {
        cout << "\n1. Add New Student\n2. Student Login\n3. Add Marks\n4. View All Students\n5. Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        if (option == 1) {
            addNewStudents();
        } else if (option == 2) {
            studentLogin();
        } else if (option == 3) {
            addMarks();
        } else if (option == 4) {
            viewAllStudents();
        } else if (option == 5) {
            break;
        } else {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}
