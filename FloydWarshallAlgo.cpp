#include <bits/stdc++.h>

using namespace std;

void Shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (auto &it : matrix)
    {
        for (auto &it1 : it)
        {
            if (it1 == -1)
            {
                it1 = 1e9;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for (auto &it : matrix)
    {
        for (auto &it1 : it)
        {
            if (it1 == 1e9)
            {
                it1 = -1;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (auto &it : matrix)
    {
        for (auto &it1 : it)
        {
            cin >> it1;
        }
    }

    Shortest_distance(matrix);
    for (auto &it : matrix)
    {
        for (auto &it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
}