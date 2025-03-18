#include <iostream>
using namespace std;

pair<int, int> search(const int *input, const int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (input[i] == target)
        {
            return make_pair(i, input[i]);
        }
    }
    return make_pair(-1, -1);
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

    pair<int, int> result = search(arr, target, size);
    cout << "Found " << result.second << " at index " << result.first << endl;
    return 0;
}
