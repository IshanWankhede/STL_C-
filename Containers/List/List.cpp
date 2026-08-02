#include <iostream>
#include <list>

using namespace std;

int main() {

    //========================================================
    // 1. Creating Lists
    //========================================================

    list<int> l1;                 // Empty list
    list<int> l2(5);              // 5 elements initialized to 0
    list<int> l3(5, 100);         // 5 elements initialized to 100

    cout << "List l3: ";

    for (int x : l3)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 2. push_back()
    //========================================================

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);

    cout << "After push_back(): ";

    for (int x : l1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 3. push_front()
    //========================================================

    l1.push_front(5);

    cout << "After push_front(): ";

    for (int x : l1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 4. pop_back()
    //========================================================

    l1.pop_back();

    cout << "After pop_back(): ";

    for (int x : l1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 5. pop_front()
    //========================================================

    l1.pop_front();

    cout << "After pop_front(): ";

    for (int x : l1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 6. front() and back()
    //========================================================

    cout << "Front Element : " << l1.front() << endl;
    cout << "Back Element  : " << l1.back() << endl;

    cout << "\n";


    //========================================================
    // 7. size()
    //========================================================

    cout << "Size : " << l1.size() << endl;

    cout << "\n";


    //========================================================
    // 8. empty()
    //========================================================

    if (l1.empty())
        cout << "List is Empty\n";
    else
        cout << "List is NOT Empty\n";

    cout << "\n";


    //========================================================
    // 9. insert()
    //========================================================

    list<int>::iterator it = l1.begin();

    ++it; // Move to second position

    l1.insert(it, 15);

    cout << "After insert(): ";

    for (int x : l1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 10. erase()
    //========================================================

    it = l1.begin();

    ++it;

    l1.erase(it);

    cout << "After erase(): ";

    for (int x : l1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 11. remove()
    //========================================================

    l1.push_back(20);
    l1.push_back(20);

    cout << "Before remove(): ";

    for (int x : l1)
        cout << x << " ";

    cout << endl;

    l1.remove(20);

    cout << "After remove(20): ";

    for (int x : l1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 12. reverse()
    //========================================================

    l1.reverse();

    cout << "After reverse(): ";

    for (int x : l1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 13. sort()
    //========================================================

    l1.push_back(25);
    l1.push_back(5);
    l1.push_back(100);

    cout << "Before sort(): ";

    for (int x : l1)
        cout << x << " ";

    cout << endl;

    l1.sort();

    cout << "After sort(): ";

    for (int x : l1)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 14. unique()
    //========================================================

    list<int> duplicateList = {10,10,20,20,20,30,30,40};

    cout << "Before unique(): ";

    for (int x : duplicateList)
        cout << x << " ";

    cout << endl;

    duplicateList.unique();

    cout << "After unique(): ";

    for (int x : duplicateList)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 15. swap()
    //========================================================

    list<int> first = {1,2,3};
    list<int> second = {100,200,300};

    first.swap(second);

    cout << "First List : ";

    for (int x : first)
        cout << x << " ";

    cout << endl;

    cout << "Second List : ";

    for (int x : second)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 16. clear()
    //========================================================

    first.clear();

    cout << "After clear(), Size = "
         << first.size() << endl;

    cout << "\n";


    //========================================================
    // 17. Iterator Traversal
    //========================================================

    cout << "Iterator Traversal: ";

    list<int>::iterator itr;

    for (itr = second.begin(); itr != second.end(); itr++)
    {
        cout << *itr << " ";
    }

    cout << "\n\n";


    //========================================================
    // 18. Reverse Iterator Traversal
    //========================================================

    cout << "Reverse Traversal: ";

    list<int>::reverse_iterator ritr;

    for (ritr = second.rbegin(); ritr != second.rend(); ritr++)
    {
        cout << *ritr << " ";
    }

    cout << endl;

    return 0;
}