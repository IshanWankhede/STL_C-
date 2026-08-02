// partial_sum(first, last, destination);

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};
    vector<int> result(v.size());

    partial_sum(v.begin(), v.end(), result.begin());

    cout << "Partial Sum: ";

    for(int x : result)
    {
        cout << x << " ";
    }

    return 0;
}