#include <iostream>

using namespace std;

void swapMinMax(int arr[], int size);

int main()
{

    int size;
    cout << "Enter The Size of Array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " Elements in array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    swapMinMax(arr, size);

    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void swapMinMax(int arr[], int size)
{
    int minIndex = 0, maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }

    int temp = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = temp;
}
