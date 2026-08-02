// Returns all unique elements from both sorted ranges.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};

    vector<int> result;

    set_union(A.begin(), A.end(),
              B.begin(), B.end(),
              back_inserter(result));

    cout << "Union: ";

    for(int x : result)
        cout << x << " ";

    return 0;
}