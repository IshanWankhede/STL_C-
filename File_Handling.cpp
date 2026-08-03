#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void create();
void read();
void update(unsigned int searchId);
void deleteData(unsigned int deleteId);

int main()
{
    unsigned int choice, id;

    while (true)
    {
        cout << "\n1. Create\n";
        cout << "2. Read\n";
        cout << "3. Update\n";
        cout << "4. Delete\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            create();
            break;

        case 2:
            read();
            break;

        case 3:
            cout << "Enter ID to Update: ";
            cin >> id;
            update(id);
            break;

        case 4:
            cout << "Enter ID to Delete: ";
            cin >> id;
            deleteData(id);
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid Choice\n";
        }
    }
}

void create()
{
    ofstream file("data.txt", ios::app);

    unsigned int id;
    string name;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    file << id << " " << name << endl;

    file.close();
}

void read()
{
    ifstream file("data.txt");

    unsigned int id;
    string name;

    cout << "\n----- RECORDS -----\n";

    while (file >> id >> name)
    {
        cout << "ID: " << id << " Name: " << name << endl;
    }

    file.close();
}

void update(unsigned int searchId)
{
    ifstream file("data.txt");
    ofstream temp("temp.txt");

    unsigned int id;
    string name;

    while (file >> id >> name)
    {
        if (id == searchId)
        {
            cout << "Enter New Name: ";
            cin >> name;
        }

        temp << id << " " << name << endl;
    }

    file.close();
    temp.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");
}

void deleteData(unsigned int deleteId)
{
    ifstream file("data.txt");
    ofstream temp("temp.txt");

    unsigned int id;
    string name;

    while (file >> id >> name)
    {
        if (id != deleteId)
        {
            temp << id << " " << name << endl;
        }
    }

    file.close();
    temp.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");
}