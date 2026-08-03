#include <iostream>
using namespace std;

int main() {
    // allocate memory for a single int
    int* p = new int;   // no casting needed
    *p = 42;
    cout << "Value: " << *p << endl;
    delete p; // free memory

    // allocate memory for an array of 5 ints
    int* arr = new int[5];
    for (int i = 0; i < 5; i++) arr[i] = i * 10;
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    delete[] arr; // free array

    return 0;
}
