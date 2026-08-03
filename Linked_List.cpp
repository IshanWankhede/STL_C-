#include <iostream>
#include <string>

using namespace std;

class StudentInfo
{
public:
    unsigned int rollNo;
    string name;
    string email;

    StudentInfo *next;
};

StudentInfo *syc = NULL;

void createStudents();
void displayStudents();
void updateStudent(unsigned int searchRollNo);
void deleteStudent(unsigned int deleteRollNo);
void freeStudents();

int main()
{
    int choice;
    unsigned int roll;

    while(true)
    {
        cout << "\n========== STUDENT MENU ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";

        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                createStudents();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                cout << "Enter Roll Number to Update : ";
                cin >> roll;
                updateStudent(roll);
                break;

            case 4:
                cout << "Enter Roll Number to Delete : ";
                cin >> roll;
                deleteStudent(roll);
                break;

            case 5:
                freeStudents();
                return 0;

            default:
                cout << "Invalid Choice\n";
        }
    }
}

void createStudents()
{
    StudentInfo *student;
    StudentInfo *last;

    student = new StudentInfo;

    cout << "\nEnter Roll Number : ";
    cin >> (*student).rollNo;

    cout << "Enter Name : ";
    cin >> (*student).name;

    cout << "Enter Email : ";
    cin >> (*student).email;

    (*student).next = NULL;

    if(syc == NULL)
    {
        syc = student;
    }
    else
    {
        last = syc;

        while((*last).next != NULL)
        {
            last = (*last).next;
        }

        (*last).next = student;
    }

    cout << "\nStudent Added Successfully.\n";
}

void displayStudents()
{
    StudentInfo *last;

    if(syc == NULL)
    {
        cout << "\nNo Student Found.\n";
        return;
    }

    last = syc;

    cout << "\n========== STUDENT LIST ==========\n";

    while(last != NULL)
    {
        cout << "\nRoll Number : " << (*last).rollNo;
        cout << "\nName        : " << (*last).name;
        cout << "\nEmail       : " << (*last).email << endl;

        last = (*last).next;
    }
}

void updateStudent(unsigned int searchRollNo)
{
    StudentInfo *last;

    if(syc == NULL)
    {
        cout << "\nNo Student Found.\n";
        return;
    }

    last = syc;

    while(last != NULL)
    {
        if((*last).rollNo == searchRollNo)
        {
            cout << "\nEnter New Name : ";
            cin >> (*last).name;

            cout << "Enter New Email : ";
            cin >> (*last).email;

            cout << "\nStudent Updated Successfully.\n";
            return;
        }

        last = (*last).next;
    }

    cout << "\nStudent Not Found.\n";
}

void deleteStudent(unsigned int deleteRollNo)
{
    StudentInfo *current;
    StudentInfo *previous;

    if(syc == NULL)
    {
        cout << "\nNo Student Found.\n";
        return;
    }

    current = syc;
    previous = NULL;

    while(current != NULL)
    {
        if((*current).rollNo == deleteRollNo)
        {
            if(previous == NULL)
            {
                syc = (*current).next;
            }
            else
            {
                (*previous).next = (*current).next;
            }

            delete current;

            cout << "\nStudent Deleted Successfully.\n";
            return;
        }

        previous = current;
        current = (*current).next;
    }

    cout << "\nStudent Not Found.\n";
}

void freeStudents()
{
    StudentInfo *current = syc;
    StudentInfo *next;

    while(current != NULL)
    {
        next = (*current).next;
        delete current;
        current = next;
    }

    syc = NULL;

    cout << "\nAll Student Records Freed From Memory.\n";
}