#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    auto it = find(v.begin(), v.end(), 30);

    if(it != v.end())
        cout << "Element Found: " << *it << endl;
    else
        cout << "Element Not Found" << endl;

    return 0;
}


// Find Position of an Element

#include <iostream>
#include <vector>
#include <algorithm>
// #include <list>
// #include <iterator>

using namespace std;

int main()
{
    vector<int> v = {10,20,30,40,50};

    auto it = find(v.begin(), v.end(), 40);

    if(it != v.end())
    {
        int index = it - v.begin();
        cout << "Element Found at Index: " << index;
    }
    else
    {
        cout << "Element Not Found";
    }

    // list<int> l = {10,20,30,40};
    // auto it = find(l.begin(), l.end(), 30);
    // int index = distance(l.begin(), it);

    return 0;
}