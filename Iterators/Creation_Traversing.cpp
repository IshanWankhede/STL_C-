#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    // Create an iterator
    vector<int>::iterator it;

    // Initialize iterator to the beginning
    it = v.begin();

    cout << "Elements of Vector: ";

    // Traverse using iterator
    while(it != v.end())
    {
        cout << *it << " ";
        it++;
    }

    return 0;
}