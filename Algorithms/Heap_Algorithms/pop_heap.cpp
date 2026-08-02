// It moves the largest element (root of the Max Heap) to the end of the vector and rearranges the remaining elements so they still form a valid Max Heap.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& v)
{
    for(int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {30, 10, 50, 20, 40};

    make_heap(v.begin(), v.end());

    cout << "After make_heap(): ";
    print(v);

    pop_heap(v.begin(), v.end());

    cout << "After pop_heap(): ";
    print(v);

    cout << "Largest Element (Moved to End): " << v.back() << endl;

    return 0;
}