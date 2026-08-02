// partition(start_iterator, end_iterator, condition_function);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Predicate Function
bool isEven(int x)
{
    return x % 2 == 0;
}

int main()
{
    vector<int> v = {10, 15, 20, 25, 30, 35, 40};

    partition(v.begin(), v.end(), isEven);

    cout << "After Partition: ";

    for(int x : v)
    {
        cout << x << " ";
    }

    return 0;
}