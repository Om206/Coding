#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Structure to represent an item
struct Item
{
    int weight;
    int value;
};

int knapsack(int capacity, vector<int> &items)
{
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    vector<vector<int>> countDp(n + 1, vector<int>(capacity + 1, 0));
    int count = 0;
    int maxC = 0;
    sort(items.begin(), items.end());
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (items[i - 1] > w)
            {
                dp[i][w] = dp[i - 1][w];
                countDp[i][w] = countDp[i - 1][w];
            }
            else
            {
                if (dp[i - 1][w] < (dp[i - 1][w - items[i - 1]] + items[i - 1]))
                {
                    dp[i][w] = dp[i - 1][w - items[i - 1]] + items[i - 1];
                    countDp[i][w] = countDp[i - 1][w - items[i - 1]] + 1;
                }
                else
                {
                    dp[i][w] = dp[i - 1][w];
                    countDp[i][w] = countDp[i - 1][w];
                }
            }
        }
    }
    count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i][capacity] == capacity)
        {
            count = i;
            break;
        }
    }
    cout << "Count= " << count << endl;

    for (auto &it : countDp)
    {
        for (auto &it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    cout << "DP matrix\n";
    for (auto &it : dp)
    {
        for (auto &it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
    return dp[n][capacity] == capacity ? countDp[n][capacity] : 0;
}

int main()
{
    int n;
    cin >> n;
    int capacity;
    cin >> capacity;
    vector<int> items(n, 0);
    for (auto &it : items)
        cin >> it;
    int maxValue = knapsack(capacity, items);

    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
