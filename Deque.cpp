#include <iostream>
#include <deque>

using namespace std;

int main() {

    //========================================================
    // 1. Creating Deques
    //========================================================

    deque<int> dq1;                 // Empty deque
    deque<int> dq2(5);              // 5 elements initialized to 0
    deque<int> dq3(5, 100);         // 5 elements initialized to 100

    cout << "Deque dq3: ";

    for (int x : dq3)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 2. push_back()
    //========================================================

    dq1.push_back(10);
    dq1.push_back(20);
    dq1.push_back(30);

    cout << "After push_back(): ";

    for (int x : dq1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 3. push_front()
    //========================================================

    dq1.push_front(5);
    dq1.push_front(1);

    cout << "After push_front(): ";

    for (int x : dq1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 4. pop_back()
    //========================================================

    dq1.pop_back();

    cout << "After pop_back(): ";

    for (int x : dq1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 5. pop_front()
    //========================================================

    dq1.pop_front();

    cout << "After pop_front(): ";

    for (int x : dq1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 6. front() and back()
    //========================================================

    cout << "Front Element : " << dq1.front() << endl;
    cout << "Back Element  : " << dq1.back() << endl;

    cout << "\n";


    //========================================================
    // 7. size() and capacity check
    //========================================================

    cout << "Size : " << dq1.size() << endl;

    cout << "\n";


    //========================================================
    // 8. empty()
    //========================================================

    if (dq1.empty())
        cout << "Deque is Empty\n";
    else
        cout << "Deque is NOT Empty\n";

    cout << "\n";


    //========================================================
    // 9. Accessing Elements
    //========================================================

    cout << "Using [] Operator" << endl;

    for (int i = 0; i < dq1.size(); i++)
        cout << dq1[i] << " ";

    cout << endl;

    cout << "Using at()" << endl;

    for (int i = 0; i < dq1.size(); i++)
        cout << dq1.at(i) << " ";

    cout << "\n\n";


    //========================================================
    // 10. insert()
    //========================================================

    dq1.insert(dq1.begin() + 1, 15);

    cout << "After insert(): ";

    for (int x : dq1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 11. erase()
    //========================================================

    dq1.erase(dq1.begin() + 1);

    cout << "After erase(): ";

    for (int x : dq1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 12. resize()
    //========================================================

    dq1.resize(6);

    cout << "After resize(6): ";

    for (int x : dq1)
        cout << x << " ";

    cout << endl;

    dq1.resize(3);

    cout << "After resize(3): ";

    for (int x : dq1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 13. swap()
    //========================================================

    deque<int> first = {10,20,30};
    deque<int> second = {100,200,300};

    first.swap(second);

    cout << "First Deque : ";

    for (int x : first)
        cout << x << " ";

    cout << endl;

    cout << "Second Deque : ";

    for (int x : second)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 14. Iterator Traversal
    //========================================================

    cout << "Iterator Traversal: ";

    deque<int>::iterator it;

    for (it = first.begin(); it != first.end(); it++)
    {
        cout << *it << " ";
    }

    cout << "\n\n";


    //========================================================
    // 15. Reverse Iterator Traversal
    //========================================================

    cout << "Reverse Traversal: ";

    deque<int>::reverse_iterator rit;

    for (rit = first.rbegin(); rit != first.rend(); rit++)
    {
        cout << *rit << " ";
    }

    cout << "\n\n";


    //========================================================
    // 16. clear()
    //========================================================

    first.clear();

    cout << "After clear()" << endl;
    cout << "Size : " << first.size() << endl;

    if (first.empty())
        cout << "Deque is Empty" << endl;
    else
        cout << "Deque is NOT Empty" << endl;

    return 0;
}