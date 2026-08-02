// Important: binary_search() works only on sorted data. O(logn)

// binary_search(start_iterator, end_iterator, value);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    if(binary_search(v.begin(), v.end(), 30))
    {
        cout << "Element Found" << endl;
    }
    else
    {
        cout << "Element Not Found" << endl;
    }

    return 0;
}