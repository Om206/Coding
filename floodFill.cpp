#include <bits/stdc++.h>

using namespace std;

void dfs(int ini, int sr, int sc, int newColor, vector<vector<int>> &ans,
         vector<vector<int>> &image, int delRow[], int delCol[])
{
    int n = ans.size();
    int m = ans[0].size();
    ans[sr][sc] = newColor;

    for (int i = 0; i < 4; i++)
    {
        int nSr = sr + delRow[i];
        int nSc = sc + delCol[i];

        if (nSr >= 0 && nSr < n && nSc >= 0 && nSc < m && image[nSr][nSc] == ini && ans[nSr][nSc] != newColor)
        {
            dfs(ini, nSr, nSc, newColor, ans, image, delRow, delCol);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    vector<vector<int>> image(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            image[i][j] = x;
        }
    }
    vector<vector<int>> ans = image;
    int initColor = image[sr][sc];
    int delCol[] = {0, +1, 0, -1};

    int delRow[] = {-1, 0, +1, 0};
    dfs(initColor, sr, sc, newColor, ans, image, delRow, delCol);

    for (auto it : ans)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
}