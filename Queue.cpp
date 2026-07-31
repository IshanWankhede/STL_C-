#include <iostream>
#include <queue>

using namespace std;

int main() {

    //========================================================
    // 1. Creating a Queue
    //========================================================

    queue<int> q;

    cout << "Initially Size : " << q.size() << endl;
    cout << "Is Empty       : " << q.empty() << endl;

    cout << "\n";


    //========================================================
    // 2. push()
    //========================================================

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "After push() :" << endl;

    cout << "Front : " << q.front() << endl;
    cout << "Back  : " << q.back() << endl;
    cout << "Size  : " << q.size() << endl;

    cout << "\n";


    //========================================================
    // 3. pop()
    //========================================================

    cout << "Removing Front Element..." << endl;

    q.pop();

    cout << "Front : " << q.front() << endl;
    cout << "Back  : " << q.back() << endl;
    cout << "Size  : " << q.size() << endl;

    cout << "\n";


    //========================================================
    // 4. Display Queue
    //========================================================

    cout << "Queue Elements : ";

    queue<int> temp = q;      // Copy queue

    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }

    cout << "\n\n";


    //========================================================
    // 5. swap()
    //========================================================

    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);

    queue<int> q2;
    q2.push(100);
    q2.push(200);
    q2.push(300);

    q1.swap(q2);

    cout << "Queue 1 : ";

    temp = q1;

    while(!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }

    cout << endl;

    cout << "Queue 2 : ";

    temp = q2;

    while(!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }

    cout << "\n\n";


    //========================================================
    // 6. empty()
    //========================================================

    if(q.empty())
        cout << "Queue is Empty\n";
    else
        cout << "Queue is NOT Empty\n";

    cout << "\n";


    //========================================================
    // 7. Processing Queue
    //========================================================

    cout << "Processing Queue :" << endl;

    while(!q.empty())
    {
        cout << "Front : " << q.front() << endl;
        q.pop();
    }

    cout << "\n";


    //========================================================
    // 8. Check After Removing Everything
    //========================================================

    cout << "Size : " << q.size() << endl;

    if(q.empty())
        cout << "Queue is Empty" << endl;
    else
        cout << "Queue is NOT Empty" << endl;

    return 0;
}