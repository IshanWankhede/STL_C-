#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Student Class
class Student
{
public:
    string name;
    int marks;

    Student(string n, int m)
    {
        name = n;
        marks = m;
    }
};

// Functor Class
class CompareMarks
{
public:
    bool operator()(Student s1, Student s2)
    {
        return s1.marks > s2.marks;   // Descending Order
    }
};

int main()
{
    vector<Student> students;

    students.push_back(Student("Rahul", 75));
    students.push_back(Student("Aman", 92));
    students.push_back(Student("Riya", 85));
    students.push_back(Student("Neha", 68));

    // Sort using Functor
    sort(students.begin(), students.end(), CompareMarks());

    cout << "Students Sorted by Marks (Descending)\n\n";

    for(Student s : students)
    {
        cout << s.name << " : " << s.marks << endl;
    }

    return 0;
}