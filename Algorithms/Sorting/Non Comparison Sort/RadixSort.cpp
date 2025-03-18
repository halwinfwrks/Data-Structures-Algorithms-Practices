#include <iostream>
using namespace std;

#include <cstdlib>
#include <cstring>

void countSort(int *input, int n, int exp, bool isIncrease) {
    int *output = new int[n];
    int *count = new int[10]();

    for (int i = 0; i < n; i++) {
        int digit = (input[i] / exp) % 10;
        count[digit]++;
    }

    if (isIncrease) {
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
    } else {
        for (int i = 8; i >= 0; i--) {
            count[i] += count[i + 1];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (input[i] / exp) % 10;
        output[count[digit] - 1] = input[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        input[i] = output[i];
    }

    delete[] output;
    delete[] count;
}

void sort(int *input, int n, bool isIncrease) {
    if (n <= 1) return;

    int max = input[0];
    for (int i = 1; i < n; i++) {
        if (input[i] > max) max = input[i];
    }

    bool allSame = true;
    for (int i = 1; i < n && allSame; i++) {
        if (input[i] != max) allSame = false;
    }
    if (allSame) return;

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(input, n, exp, isIncrease);
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