// count(start_iterator, end_iterator, value);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 20, 40, 20, 50};

    int cnt = count(v.begin(), v.end(), 20);

    cout << "20 appears " << cnt << " times." << endl;

    return 0;
}