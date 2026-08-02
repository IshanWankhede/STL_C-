#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {30, 10, 50, 20, 40};

    auto it = max_element(v.begin(), v.end());

    cout << "Maximum = " << *it << endl;
    cout << "Index = " << it - v.begin();

    return 0;
}