#include <iostream>
using namespace std;

void sort(int *input, int n, bool isIncrease)
{
    if (n <= 1)
        return;

    int min = input[0], max = input[0];
    for (int i = 1; i < n; i++)
    {
        if (input[i] < min)
            min = input[i];
        if (input[i] > max)
            max = input[i];
    }

    if (min == max)
        return;

    int range = max - min + 1;
    int *countingTable = new int[range](); // Initialize to 0
    for (int i = 0; i < n; i++)
    {
        countingTable[input[i] - min]++;
    }
    for (int i = 1; i < range; i++)
    {
        countingTable[i] += countingTable[i - 1];
    }
    int *output = new int[n];
    for (int i = n - 1; i >= 0; i--)
    { // Stable sort: right to left
        int index = countingTable[input[i] - min] - 1;
        output[index] = input[i];
        countingTable[input[i] - min]--;
    }

    if (isIncrease)
    {
        for (int i = 0; i < n; i++)
        {
            input[i] = output[i];
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            input[i] = output[n - 1 - i];
        }
    }

    delete[] countingTable;
    delete[] output;
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