// unique(start_iterator, end_iterator);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {10, 10, 20, 20, 30, 30, 40, 40};

    auto it = unique(v.begin(), v.end());
    //it iterator k phele  saare unique elem hai
    // it ke badd saare duplicate elem hai
    
    v.erase(it, v.end());

    cout << "After unique(): ";

    for(int x : v)
    {
        cout << x << " ";
    }

    return 0;
}