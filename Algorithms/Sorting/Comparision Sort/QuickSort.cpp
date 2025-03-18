#include <iostream>
using namespace std;

int partition(int *input, int low, int high, bool isIncrease)
{
    int pivot = high;
    int j = low - 1;
    for (int i = low; i < high; i++)
    {
        if (isIncrease ? input[i] <= input[pivot] : input[i] >= input[pivot])
        {
            j++;
            swap(input[i], input[j]);
        }
    }
    swap(input[j + 1], input[pivot]);
    return j + 1;
}

void sort(int *input, int low, int high, bool isIncrease)
{
    if (low < high)
    {
        int pivot = partition(input, low, high, isIncrease);
        sort(input, low, pivot - 1, isIncrease);
        sort(input, pivot + 1, high, isIncrease);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Input array:";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Sort ascending
    sort(arr, 0, n, true);
    cout << "Ascending: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    // Sort descending
    sort(arr, 0, n, false);
    cout << "Descending: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
