#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num & 1) {
        cout << num << " is Odd" << endl;
    } else {
        cout << num << " is Even" << endl;
    }

    return 0;
}
