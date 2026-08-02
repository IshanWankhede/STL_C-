// rotate(start_iterator, middle_iterator, end_iterator);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {10,20,30,40,50};

    rotate(v.begin(), v.begin() + 2, v.end());

    cout << "After Rotation: ";

    for(int x : v)
    {
        cout << x << " ";
    }

    return 0;
}