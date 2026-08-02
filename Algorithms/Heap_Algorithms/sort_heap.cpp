// sort_heap() sorts the elements of a heap into ascending order.

// sort_heap(start_iterator, end_iterator);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& v)
{
    for(int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {30, 10, 50, 20, 40};

    // Convert into Max Heap
    make_heap(v.begin(), v.end());

    cout << "Heap: ";
    print(v);

    // Sort the heap
    sort_heap(v.begin(), v.end());

    cout << "After sort_heap(): ";
    print(v);

    return 0;
}