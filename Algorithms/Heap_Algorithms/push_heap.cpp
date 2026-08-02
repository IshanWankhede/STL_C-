// push_heap() adds a newly inserted element to an existing heap and rearranges the heap to maintain the Max Heap property.

//push_heap(start_iterator, end_iterator);

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

    cout << "Initial Heap: ";
    print(v);

    // Insert new element
    v.push_back(60);

    cout << "After push_back(60): ";
    print(v);

    // Restore heap property
    push_heap(v.begin(), v.end());

    cout << "After push_heap(): ";
    print(v);

    cout << "Top Element: " << v.front() << endl;

    return 0;
}