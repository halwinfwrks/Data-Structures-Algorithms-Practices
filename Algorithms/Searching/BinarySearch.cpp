#include <iostream>
using namespace std;

void search(const int *input, int start, int end, int target)
{
    if (start > end)
    {
        cout << "Target not found in the array." << endl;
        return;
    }
    int mid = (start + end) / 2;
    if (input[mid] == target)
    {
        cout << "Target found at index " << mid << endl;
        return;
    }
    else if (input[mid] < target)
        search(input, mid + 1, end, target);
    else
        search(input, start, mid - 1, target);
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 30, 40, 50};
    int target = 30;
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "The input array is: " << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    search(arr, 0, size - 1, target);
    return 0;
}
