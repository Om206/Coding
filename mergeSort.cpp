#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int>
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high + 1) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    mergeSort(arr, 0, n - 1);
    for (auto &it : arr)
        cout << it << " ";
    cout << endl;
}