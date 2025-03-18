#include <iostream>
using namespace std;

void merge(int *input, int l, int m, int r, bool isIncrease)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int i, j, k;
    for (i = 0; i < n1; i++)
        L[i] = input[l + i];
    for (j = 0; j < n2; j++)
        R[j] = input[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
        if (isIncrease ? L[i] <= R[j] : L[i] >= R[j])
            input[k++] = L[i++];
        else
            input[k++] = R[j++];
    while (i < n1)
        input[k++] = L[i++];
    while (j < n2)
        input[k++] = R[j++];
}

void sort(int *input, int l, int r, bool isIncrease)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        sort(input, l, m, isIncrease);
        sort(input, m + 1, r, isIncrease);
        merge(input, l, m, r, isIncrease);
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
