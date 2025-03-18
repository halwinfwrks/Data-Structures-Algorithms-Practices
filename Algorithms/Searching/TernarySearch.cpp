#include <iostream>
using namespace std;

void search(const int *input, int left, int right, int target)
{
    if (left > right)
    {
        cout << "Element not found in the array" << endl;
        return;
    }
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;
    if (input[mid1] == target)
    {
        cout << "Element found at index " << mid1 << endl;
        return;
    }
    if (input[mid2] == target)
    {
        cout << "Element found at index " << mid2 << endl;
        return;
    }
    if (input[mid1] > target)
        search(input, 0, mid1 - 1, target);
    else if (input[mid2] < target)
        search(input, mid2 + 1, right, target);
    else
        search(input, mid1 + 1, mid2 - 1, target);
}

int main(int argc, char const *argv[])
{
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(input) / sizeof(input[0]);
    int target = 5;

    cout << "The input array is: " << endl;
    for (int i = 0; i < n; i++)
        cout << input[i] << " ";
    cout << endl;

    search(input, 0, n - 1, target);
    return 0;
}
