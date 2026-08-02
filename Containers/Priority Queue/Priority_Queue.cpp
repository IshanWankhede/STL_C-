#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    //========================================================
    // 1. Max Heap (Default Priority Queue)
    //========================================================

    priority_queue<int> maxHeap;

    cout << "Initially" << endl;
    cout << "Size     : " << maxHeap.size() << endl;
    cout << "Is Empty : " << maxHeap.empty() << endl;

    cout << "\n";


    //========================================================
    // 2. push()
    //========================================================

    maxHeap.push(40);
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(50);
    maxHeap.push(20);

    cout << "After push()" << endl;
    cout << "Top Element : " << maxHeap.top() << endl;
    cout << "Size        : " << maxHeap.size() << endl;

    cout << "\n";


    //========================================================
    // 3. Display Max Heap
    //========================================================

    cout << "Max Heap Elements : ";

    priority_queue<int> temp = maxHeap;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << "\n\n";


    //========================================================
    // 4. pop()
    //========================================================

    cout << "Removing Highest Priority Element..." << endl;

    maxHeap.pop();

    cout << "Top Element : " << maxHeap.top() << endl;
    cout << "Size        : " << maxHeap.size() << endl;

    cout << "\n";


    //========================================================
    // 5. Min Heap
    //========================================================

    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(40);
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(50);
    minHeap.push(20);

    cout << "Min Heap Elements : ";

    temp = priority_queue<int>();

    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    cout << "\n\n";


    //========================================================
    // 6. swap()
    //========================================================

    priority_queue<int> pq1;
    pq1.push(100);
    pq1.push(200);
    pq1.push(300);

    priority_queue<int> pq2;
    pq2.push(1);
    pq2.push(2);
    pq2.push(3);

    pq1.swap(pq2);

    cout << "Priority Queue 1 : ";

    temp = pq1;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;

    cout << "Priority Queue 2 : ";

    temp = pq2;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << "\n\n";


    //========================================================
    // 7. Processing Priority Queue
    //========================================================

    cout << "Processing Max Heap" << endl;

    while (!maxHeap.empty())
    {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    cout << "\n\n";


    //========================================================
    // 8. Final Check
    //========================================================

    cout << "Final Size : " << maxHeap.size() << endl;

    if (maxHeap.empty())
        cout << "Priority Queue is Empty" << endl;
    else
        cout << "Priority Queue is NOT Empty" << endl;

    return 0;
}