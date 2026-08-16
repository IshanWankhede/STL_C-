#include <iostream>
#include <cmath>

using namespace std;

void binaryToDecimal(int binaryNo) {
    int power = 0;
    int decimalNo = 0;

    while(binaryNo > 0) {
        int lastDigit = binaryNo % 10;
        binaryNo /= 10;
        int powerdDigit = lastDigit * (int)(pow(2,power));
        power ++;
        decimalNo += powerdDigit;
    }

    cout << "Decimal No = " << decimalNo << endl;
}

int main () {

    int binaryNo;
    cout << "Enter Binary No: ";
    cin >> binaryNo;

    if(binaryNo == 0){
        cout << "Decimal No: 0";
    }
    else{
        binaryToDecimal(binaryNo);
    }

    return 0;
}