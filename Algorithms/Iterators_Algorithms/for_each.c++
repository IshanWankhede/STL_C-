#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function called for every element
void print_double(int x)
{
    cout << x*2 << " ";
}

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    cout << "Vector Elements: ";

    for_each(v.begin(), v.end(), print_double);

    return 0;
}