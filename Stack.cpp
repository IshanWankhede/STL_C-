#include <iostream>
#include <stack>

using namespace std;

int main() {

    //========================================================
    // 1. Creating a Stack
    //========================================================

    stack<int> st;

    cout << "Initially" << endl;
    cout << "Size     : " << st.size() << endl;
    cout << "Is Empty : " << st.empty() << endl;

    cout << "\n";


    //========================================================
    // 2. push()
    //========================================================

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "After push()" << endl;
    cout << "Top Element : " << st.top() << endl;
    cout << "Size        : " << st.size() << endl;

    cout << "\n";


    //========================================================
    // 3. pop()
    //========================================================

    cout << "Removing Top Element..." << endl;

    st.pop();

    cout << "Top Element : " << st.top() << endl;
    cout << "Size        : " << st.size() << endl;

    cout << "\n";


    //========================================================
    // 4. Display Stack
    //========================================================

    cout << "Stack Elements (Top to Bottom): ";

    stack<int> temp = st;      // Copy stack

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << "\n\n";


    //========================================================
    // 5. swap()
    //========================================================

    stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);

    stack<int> st2;
    st2.push(100);
    st2.push(200);
    st2.push(300);

    st1.swap(st2);

    cout << "Stack 1 : ";

    temp = st1;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;

    cout << "Stack 2 : ";

    temp = st2;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << "\n\n";


    //========================================================
    // 6. empty()
    //========================================================

    if (st.empty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is NOT Empty" << endl;

    cout << "\n";


    //========================================================
    // 7. Processing Stack
    //========================================================

    cout << "Processing Stack" << endl;

    while (!st.empty())
    {
        cout << "Top : " << st.top() << endl;
        st.pop();
    }

    cout << "\n";


    //========================================================
    // 8. Check After Removing Everything
    //========================================================

    cout << "Final Size : " << st.size() << endl;

    if (st.empty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is NOT Empty" << endl;

    return 0;
}