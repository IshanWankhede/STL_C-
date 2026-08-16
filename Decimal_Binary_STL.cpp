#include <iostream>
#include <stack>

using namespace std;

void decimalToBinary(int decimalNO);

int main() {

    int decimalNO;
    cout << "Enter Decimal No: ";
    cin >> decimalNO;

    if(decimalNO == 0) {
        cout << "Binary No = 0" << endl;
    }
    else {
        decimalToBinary(decimalNO);
    }

    return 0;
}

void decimalToBinary(int decimalNO) {
    stack<int> s;

    while(decimalNO > 0){
        s.push(decimalNO % 2);
        decimalNO /= 2;
    }

    cout << "Binary = ";
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}