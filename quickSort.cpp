#include <bits/stdc++.h>

using namespace std;

int quickSort(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[high]);
    return i;
}

void sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = quickSort(arr, low, high);
        sort(arr, low, pivot - 1);
        sort(arr, pivot + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (auto &it : arr)
    {
        cin >> it;
    }

    sort(arr, 0, n - 1);
    for (auto &it : arr)
        cout << it << " ";
    cout << endl;
}