#include <iostream>
using namespace std;

void heapify(int *input, int n, int i, bool isMaxHeap)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (isMaxHeap)
    {
        if (left < n && input[left] > input[largest])
            largest = left;
        if (right < n && input[right] > input[largest])
            largest = right;
        if (largest != i)
        {
            swap(input[i], input[largest]);
            heapify(input, n, largest, isMaxHeap);
        }
    }
    else
    {
        if (left < n && input[left] < input[largest])
            largest = left;
        if (right < n && input[right] < input[largest])
            largest = right;
        if (largest != i)
        {
            swap(input[i], input[largest]);
            heapify(input, n, largest, isMaxHeap);
        }
    }
}

void sort(int *input, int n, bool isMaxHeap)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(input, n, i, isMaxHeap);
    for (int i = n - 1; i > 0; i--)
    {
        swap(input[i], input[0]);
        heapify(input, i, 0, isMaxHeap);
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
    sort(arr, n, true);
    cout << "Ascending: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    // Sort descending
    sort(arr, n, false);
    cout << "Descending: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
