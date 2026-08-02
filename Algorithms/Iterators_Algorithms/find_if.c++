// find_if(start_iterator, end_iterator, condition_function);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Condition Function
bool isEven(int x)
{
    return x % 2 == 0;
}

int main()
{
    vector<int> v = {11, 25, 33, 40, 55, 60};

    auto it = find_if(v.begin(), v.end(), isEven);

    if(it != v.end())
    {
        cout << "First Even Number : " << *it << endl;
        cout << "Index : " << it - v.begin() << endl;
    }
    else
    {
        cout << "No Even Number Found" << endl;
    }

    return 0;
}