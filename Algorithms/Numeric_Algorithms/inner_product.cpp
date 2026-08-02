// inner_product(first1, last1, first2, initial_value);

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {5, 6, 7, 8};

    int result = inner_product(v1.begin(), v1.end(), v2.begin(), 0);

    cout << "Inner Product = " << result << endl;

    return 0;
}