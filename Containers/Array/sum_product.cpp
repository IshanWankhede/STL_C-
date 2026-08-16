#include <iostream>

using namespace std;

void sumOfarray(int arr[], int size);
void productOfarray(int arr[], int size);

int main() {

    int size;
    cout << "Enter The Size of Array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " Elements in array: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    sumOfarray(arr, size);
    productOfarray(arr, size);

    return 0;
}

void sumOfarray(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }

    cout << "Sum = " << sum << endl;
}

void productOfarray(int arr[], int size) {
    int product = 1;
    for(int i = 0; i < size; i++){
        product *= arr[i];
    }

    cout << "Product = " << product << endl;
}