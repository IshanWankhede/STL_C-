#include <iostream>
using namespace std;

int decimal_binary(int decimalNO);

int main(){
    int decimalNO;
    cout << "Enter No to convert in Binary: ";
    cin >> decimalNO;

    int binaryNO = decimal_binary(decimalNO);

    cout << "Conversion......" << endl;
    cout << "Decimal = " << decimalNO << " Binary = " << binaryNO << endl;

    return 0;
}

int decimal_binary(int decimalNO) {
    int ans = 0;
    int pow = 1;

    while(decimalNO > 0) {
        int rem = decimalNO % 2;
        decimalNO = decimalNO / 2;

        ans += (rem * pow);
        pow *= 10;
    }

    return ans;
}
