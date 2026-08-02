// Important: lower_bound() works only on sorted data.
//It returns an iterator pointing to the first element that is greater than or equal to (>=) the given value.

// lower_bound(start_iterator, end_iterator, value);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    auto it = lower_bound(v.begin(), v.end(), 25);

    cout << "Value : " << *it << endl;
    cout << "Index : " << it - v.begin() << endl;

    return 0;
}