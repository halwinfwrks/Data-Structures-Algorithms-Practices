#include <iostream>
using namespace std;

void sort(int *input, int n, bool isIncrease)
{
    if (n <= 1)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        int extremeIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (isIncrease ? (input[j] < input[extremeIndex]) : (input[j] > input[extremeIndex]))
            {
                extremeIndex = j;
            }
        }
        if (extremeIndex != i)
        {
            swap(input[i], input[extremeIndex]);
        }
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
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // Sort descending
    sort(arr, n, false);
    cout << "Descending: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}
