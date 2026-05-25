#include <bits/stdc++.h>
using namespace std;

class Student {

public:
    int id;
    string name;
    int age;
    string course;
    float cgpa;
    int attendance;
    float marks;
};

vector<Student> students;

void addStudent() {

    Student s;

    cout << "\nEnter ID: ";
    cin >> s.id;
    for(int i = 0; i < students.size(); i++) {

        if(students[i].id == s.id) {

            cout << "\nID Already Exists\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;

    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, s.course);

    cout << "Enter CGPA: ";
    cin >> s.cgpa;

    cout << "Enter Attendance Percentage: ";
    cin >> s.attendance;

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);

    cout << "\nStudent Added Successfully!\n";
}

void viewStudents() {

    if(students.empty()) {

        cout << "\nNo Students Found\n";
        return;
    }

    cout << "\n========== STUDENT RECORDS ==========\n";

    for(int i = 0; i < students.size(); i++) {

        cout << "\nStudent " << i + 1 << endl;

        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Course: " << students[i].course << endl;
        cout << "CGPA: " << students[i].cgpa << endl;
        cout << "Attendance: " << students[i].attendance << "%" << endl;
        cout << "Marks: " << students[i].marks << endl;
    }
}

void searchStudent() {

    int searchID;
    bool found = false;

    cout << "\nEnter Student ID to Search: ";
    cin >> searchID;

    for(int i = 0; i < students.size(); i++) {

        if(students[i].id == searchID) {

            cout << "\n========== STUDENT FOUND ==========\n";

            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course: " << students[i].course << endl;
            cout << "CGPA: " << students[i].cgpa << endl;
            cout << "Attendance: " << students[i].attendance << "%" << endl;
            cout << "Marks: " << students[i].marks << endl;

            found = true;
            break;
        }
    }

    if(found == false) {

        cout << "\nStudent Not Found\n";
    }
}

void updateStudent() {

    int updateID;
    bool found = false;

    cout << "\nEnter Student ID to Update: ";
    cin >> updateID;

    for(int i = 0; i < students.size(); i++) {

        if(students[i].id == updateID) {

            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, students[i].name);

            cout << "Enter New Age: ";
            cin >> students[i].age;

            cin.ignore();

            cout << "Enter New Course: ";
            getline(cin, students[i].course);

            cout << "Enter New CGPA: ";
            cin >> students[i].cgpa;

            cout << "Enter New Attendance: ";
            cin >> students[i].attendance;

            cout << "Enter New Marks: ";
            cin >> students[i].marks;

            cout << "\nStudent Updated Successfully!\n";

            found = true;
            break;
        }
    }

    if(found == false) {

        cout << "\nStudent Not Found\n";
    }
}

void deleteStudent() {

    int deleteID;
    bool found = false;

    cout << "\nEnter Student ID to Delete: ";
    cin >> deleteID;

    for(int i = 0; i < students.size(); i++) {

        if(students[i].id == deleteID) {

            students.erase(students.begin() + i);

            cout << "\nStudent Deleted Successfully!\n";

            found = true;
            break;
        }
    }

    if(found == false) {

        cout << "\nStudent Not Found\n";
    }
}

void sortStudents() {

    sort(students.begin(), students.end(),

    [](Student a, Student b) {

        return a.id < b.id;
    });

    cout << "\nStudents Sorted Successfully!\n";
}

void saveToFile() {

    ofstream file("students.txt");

    for(int i = 0; i < students.size(); i++) {

        file << students[i].id << endl;
        file << students[i].name << endl;
        file << students[i].age << endl;
        file << students[i].course << endl;
        file << students[i].cgpa << endl;
        file << students[i].attendance << endl;
        file << students[i].marks << endl;
    }
    file.close();
    cout << "\nData Saved Successfully!\n";
}

void loadFromFile() {

    ifstream file("students.txt");

    if(!file) {

        return;
    }

    Student s;

    while(file >> s.id) {

        file.ignore();

        getline(file, s.name);

        file >> s.age;

        file.ignore();

        getline(file, s.course);

        file >> s.cgpa;
        file >> s.attendance;
        file >> s.marks;

        file.ignore();

        students.push_back(s);
    }

    file.close();
}

int main() {

    string username, password;

    cout << "====================================\n";
    cout << "     STUDENT MANAGEMENT SYSTEM\n";
    cout << "====================================\n";

    cout << "\n=========== LOGIN ===========\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    if(username != "admin" || password != "1234") {

        cout << "\nInvalid Username or Password\n";
        return 0;
    }

    loadFromFile();

    int choice;

    while(true) {

        cout << "\n====================================\n";
        cout << "     STUDENT MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Sort Students By ID\n";
        cout << "7. Save Data\n";
        cout << "8. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                sortStudents();
                break;

            case 7:
                saveToFile();
                break;

            case 8:
                saveToFile();
                cout << "\nThank You For Using The System!\n";
                return 0;

            default:
                cout << "\nInvalid Choice\n";
        }
    }

    return 0;
}