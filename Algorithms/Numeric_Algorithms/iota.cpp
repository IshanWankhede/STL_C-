// iota(start_iterator, end_iterator, starting_value);

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v(5);

    iota(v.begin(), v.end(), 1);

    for(int x : v)
    {
        cout << x << " ";
    }

    return 0;
}