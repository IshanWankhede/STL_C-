#include <iostream>
#include <vector>

using namespace std;

int main() {

    //========================================================
    // 1. Creating Vectors
    //========================================================

    vector<int> v1;                 // Empty vector
    vector<int> v2(5);              // Size = 5, all values = 0
    vector<int> v3(5, 100);         // Size = 5, all values = 100

    cout << "Vector v3: ";
    for (int x : v3)
        cout << x << " ";
    cout << endl << endl;


    //========================================================
    // 2. push_back()
    //========================================================

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    cout << "After push_back(): ";
    for (int x : v1)
        cout << x << " ";
    cout << endl << endl;


    //========================================================
    // 3. Size and Capacity
    //========================================================

    cout << "Size     : " << v1.size() << endl;
    cout << "Capacity : " << v1.capacity() << endl;
    cout << endl;


    //========================================================
    // 4. front() and back()
    //========================================================

    cout << "Front Element : " << v1.front() << endl;
    cout << "Back Element  : " << v1.back() << endl;
    cout << endl;


    //========================================================
    // 5. Accessing Elements
    //========================================================

    cout << "Using [] Operator" << endl;

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    cout << endl;

    cout << "Using at()" << endl;

    for (int i = 0; i < v1.size(); i++)
        cout << v1.at(i) << " ";

    cout << endl << endl;


    //========================================================
    // 6. empty()
    //========================================================

    if (v1.empty())
        cout << "Vector is Empty\n";
    else
        cout << "Vector is NOT Empty\n";

    cout << endl;


    //========================================================
    // 7. pop_back()
    //========================================================

    v1.pop_back();

    cout << "After pop_back(): ";

    for (int x : v1)
        cout << x << " ";

    cout << endl << endl;


    //========================================================
    // 8. insert()
    //========================================================

    v1.insert(v1.begin(), 5);              // Beginning

    v1.insert(v1.begin() + 2, 15);         // Middle

    v1.insert(v1.end(), 100);              // End

    cout << "After insert(): ";

    for (int x : v1)
        cout << x << " ";

    cout << endl << endl;


    //========================================================
    // 9. erase()
    //========================================================

    v1.erase(v1.begin());          // Remove first element

    cout << "After erase(begin()): ";

    for (int x : v1)
        cout << x << " ";

    cout << endl;

    // Erase Range

    v1.erase(v1.begin() + 1, v1.begin() + 3);

    cout << "After erase(range): ";

    for (int x : v1)
        cout << x << " ";

    cout << endl << endl;


    //========================================================
    // 10. clear()
    //========================================================

    vector<int> temp = {1,2,3,4,5};

    cout << "Before clear(), Size = "
         << temp.size() << endl;

    temp.clear();

    cout << "After clear(), Size = "
         << temp.size() << endl;

    cout << endl;


    //========================================================
    // 11. swap()
    //========================================================

    vector<int> first = {10,20,30};
    vector<int> second = {100,200,300};

    first.swap(second);

    cout << "First Vector : ";

    for(int x : first)
        cout << x << " ";

    cout << endl;

    cout << "Second Vector : ";

    for(int x : second)
        cout << x << " ";

    cout << endl << endl;


    //========================================================
    // 12. Range-Based For Loop
    //========================================================

    cout << "Range Based Loop: ";

    for(int x : first)
        cout << x << " ";

    cout << endl << endl;


    //========================================================
    // 13. Iterator
    //========================================================

    cout << "Iterator Traversal: ";

    vector<int>::iterator it;

    for(it = first.begin(); it != first.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl << endl;


    //========================================================
    // 14. Reverse Iterator
    //========================================================

    cout << "Reverse Traversal: ";

    vector<int>::reverse_iterator rit;

    for(rit = first.rbegin(); rit != first.rend(); rit++)
    {
        cout << *rit << " ";
    }

    cout << endl << endl;


    //========================================================
    // 15. begin() and end()
    //========================================================

    cout << "First Element : " << *first.begin() << endl;

    cout << "Last Element  : " << *(first.end()-1) << endl;

    cout << endl;


    //========================================================
    // 16. resize()
    //========================================================

    vector<int> marks = {10,20,30};

    marks.resize(5);

    cout << "After resize(5): ";

    for(int x : marks)
        cout << x << " ";

    cout << endl;

    marks.resize(2);

    cout << "After resize(2): ";

    for(int x : marks)
        cout << x << " ";

    cout << endl << endl;


    //========================================================
    // 17. assign()
    //========================================================

    vector<int> nums;

    nums.assign(4,50);

    cout << "After assign(): ";

    for(int x : nums)
        cout << x << " ";

    cout << endl << endl;


    //========================================================
    // 18. Copying Vectors
    //========================================================

    vector<int> copy = nums;

    cout << "Copied Vector: ";

    for(int x : copy)
        cout << x << " ";

    cout << endl << endl;


    //========================================================
    // 19. Capacity Growth Example
    //========================================================

    vector<int> demo;

    cout << "Capacity Growth\n";

    for(int i=1;i<=10;i++)
    {
        demo.push_back(i);

        cout << "Inserted "
             << i
             << " -> Size: "
             << demo.size()
             << " Capacity: "
             << demo.capacity()
             << endl;
    }

    return 0;
}