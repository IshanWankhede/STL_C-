#include <iostream>
#include<map>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    // Create Iterator
    vector<int>::iterator it = v.begin();

    cout << "Current Element: " << *it << endl;

    // Move Forward
    it++;
    cout << "After it++ : " << *it << endl;

    // Move Backward
    it--;
    cout << "After it-- : " << *it << endl;

    // Move 2 Positions Forward
    it = it + 2;
    cout << "After it + 2 : " << *it << endl;

    // Move 1 Position Backward
    it = it - 1;
    cout << "After it - 1 : " << *it << endl;

    // Access using Offset
    cout << "it[2] : " << it[2] << endl;

    // Compare Iterators
    if(it == v.begin() + 1)
        cout << "Iterator is at Index 1" << endl;
    else
        cout << "Iterator is NOT at Index 1" << endl;

    // Distance Between Two Iterators
    cout << "Distance = " << v.end() - v.begin() << endl;


    // itr->first
    map<string, int> marks;

    marks["Aman"] = 90;
    marks["Riya"] = 85;
    marks["Rahul"] = 95;

    map<string, int>::iterator it1;

    for(it1 = marks.begin(); it1 != marks.end(); it1++)
    {
        cout << it1->first << " : " << it1->second << endl;
    }


    return 0;
}