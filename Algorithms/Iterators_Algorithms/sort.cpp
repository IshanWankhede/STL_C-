// sort(start_iterator, end_iterator);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {40, 10, 30, 50, 20};

    sort(v.begin(), v.end());

    cout << "Ascending Order: ";

    for(int x : v)
    {
        cout << x << " ";
    }cout << endl;

    cout << "Reversing Order: ";

    reverse(v.begin(), v.end());

    for(int x: v){
        cout << x << " ";
    }

    return 0;
}