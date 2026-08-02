/*

It returns a pair of iterators:

first → lower_bound()
second → upper_bound()

Important: equal_range() works only on sorted data.

*/

// equal_range(start_iterator, end_iterator, value);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 20, 20, 30, 40, 50};

    auto p = equal_range(v.begin(), v.end(), 20);

    cout << "Lower Bound Value : " << *p.first << endl;
    cout << "Upper Bound Value : " << *p.second << endl;

    cout << "Lower Bound Index : " << p.first - v.begin() << endl;
    cout << "Upper Bound Index : " << p.second - v.begin() << endl;

    return 0;
}