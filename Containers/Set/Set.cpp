#include <iostream>
#include <set>

using namespace std;

int main()
{
    //========================================================
    // 1. Creating Sets
    //========================================================

    set<int> s1;                 // Empty Set
    set<int> s2 = {10, 20, 30};  // Initializer List

    //========================================================
    // 2. insert()
    //========================================================

    s1.insert(40);
    s1.insert(10);
    s1.insert(20);
    s1.insert(50);
    s1.insert(30);
    s1.insert(20);   // Duplicate (Ignored)
    s1.insert(10);   // Duplicate (Ignored)

    cout << "After insert()" << endl;

    for(auto x : s1)
    {
        cout << x << " ";
    }

    cout << "\n\n";


    //========================================================
    // 3. size()
    //========================================================

    cout << "Size : " << s1.size() << endl;

    cout << "\n";


    //========================================================
    // 4. empty()
    //========================================================

    if(s1.empty())
        cout << "Set is Empty" << endl;
    else
        cout << "Set is NOT Empty" << endl;

    cout << "\n";


    //========================================================
    // 5. find()
    //========================================================

    if(s1.find(20) != s1.end())
        cout << "20 Found" << endl;
    else
        cout << "20 Not Found" << endl;

    cout << "\n";


    //========================================================
    // 6. count()
    //========================================================

    cout << "Count of 20 : " << s1.count(20) << endl;
    cout << "Count of 100 : " << s1.count(100) << endl;

    cout << "\n";


    //========================================================
    // 7. erase()
    //========================================================

    s1.erase(30);

    cout << "After erase(30)" << endl;

    for(auto x : s1)
    {
        cout << x << " ";
    }

    cout << "\n\n";


    //========================================================
    // 8. lower_bound()
    //========================================================

    auto lb = s1.lower_bound(25);

    if(lb != s1.end())
        cout << "Lower Bound of 25 : " << *lb << endl;

    cout << "\n";


    //========================================================
    // 9. upper_bound()
    //========================================================

    auto ub = s1.upper_bound(20);

    if(ub != s1.end())
        cout << "Upper Bound of 20 : " << *ub << endl;

    cout << "\n";


    //========================================================
    // 10. Iterator Traversal
    //========================================================

    cout << "Iterator Traversal" << endl;

    set<int>::iterator it;

    for(it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }

    cout << "\n\n";


    //========================================================
    // 11. Reverse Iterator Traversal
    //========================================================

    cout << "Reverse Traversal" << endl;

    set<int>::reverse_iterator rit;

    for(rit = s1.rbegin(); rit != s1.rend(); rit++)
    {
        cout << *rit << " ";
    }

    cout << "\n\n";


    //========================================================
    // 12. swap()
    //========================================================

    set<int> first = {1,2,3};
    set<int> second = {100,200,300};

    first.swap(second);

    cout << "First Set : ";

    for(auto x : first)
        cout << x << " ";

    cout << endl;

    cout << "Second Set : ";

    for(auto x : second)
        cout << x << " ";

    cout << "\n\n";


    //========================================================
    // 13. clear()
    //========================================================

    s1.clear();

    cout << "After clear()" << endl;

    cout << "Size : " << s1.size() << endl;

    if(s1.empty())
        cout << "Set is Empty" << endl;
    else
        cout << "Set is NOT Empty" << endl;

    return 0;
}