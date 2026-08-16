#include <iostream>

using namespace std;

int reverse_array(int arr[], int size);

int main() {
    int size;
    cout << "Enter The Size of Array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " Elements in array: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    reverse_array(arr, size);

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

int reverse_array(int arr[], int size) {
    int strt = 0;
    int end = size - 1;

    while(!(strt > end)) {
        swap(arr[strt],arr[end]);
        strt++;
        end--;
    }
}