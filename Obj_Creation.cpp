#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
    string name;

    void display() {
        cout << "Roll: " << rollNo << ", Name: " << name << endl;
    }
};

int main() {
    // Object on the stack
    Student s1;
    s1.rollNo = 1;
    s1.name = "Alice";
    s1.display();

    // Object on the heap (pointer)
    Student* s2 = new Student;
    s2->rollNo = 2;
    s2->name = "Bob";
    s2->display();

    delete s2; // free heap memory
    return 0;
}