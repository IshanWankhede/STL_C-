// A heap is just that vector arranged so the largest element is always at the front (for max-heap).

// STL creates a Max Heap by default.

// make_heap(start_iterator, end_iterator);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {30, 10, 50, 20, 40};

    cout << "Before make_heap(): ";
    for(int x : v)
        cout << x << " ";

    cout << endl;

    // Convert vector into Max Heap
    make_heap(v.begin(), v.end());

    cout << "After make_heap(): ";
    for(int x : v)
        cout << x << " ";

    cout << endl;

    // Largest element
    cout << "Top Element : " << v.front() << endl;

    return 0;
}