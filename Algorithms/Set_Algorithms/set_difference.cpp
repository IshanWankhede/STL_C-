// Returns elements present in the first set but not in the second.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> A = {1,2,3,4};
    vector<int> B = {3,4,5,6};

    vector<int> result;

    set_difference(A.begin(), A.end(),
                   B.begin(), B.end(),
                   back_inserter(result));

    cout << "Difference: ";

    for(int x : result)
        cout << x << " ";

    return 0;
}