// count_if(start_iterator, end_iterator, condition_function);

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
    vector<int> v = {10, 15, 20, 25, 30, 35, 40};

    int cnt = count_if(v.begin(), v.end(), isEven);

    cout << "Total Even Numbers : " << cnt << endl;

    return 0;
}