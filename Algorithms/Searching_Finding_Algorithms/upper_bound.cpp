// Returns an iterator to the first element that is strictly greater (>) than the given value.

// upper_bound(begin, end, value);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 20, 20, 30, 40, 50};

    auto it = upper_bound(v.begin(), v.end(), 20);

    if(it != v.end())
    {
        cout << "Value : " << *it << endl;
        cout << "Index : " << it - v.begin() << endl;
    }
    else
    {
        cout << "No element greater than 20";
    }

    return 0;
}