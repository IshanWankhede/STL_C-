#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Custom Functor
class Compare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    priority_queue<int, vector<int>, Compare> pq;

    pq.push(50);
    pq.push(10);
    pq.push(40);
    pq.push(20);
    pq.push(30);

    cout << "Elements:\n";

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}