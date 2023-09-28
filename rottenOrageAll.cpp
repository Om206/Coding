#include <bits/stdc++.h>

using namespace std;

// here we have to use only BFS because if we use dfs then it first visit
//  node by which we may not get time minimum time

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> orange(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            orange[i][j] = x;
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delCol[] = {0, +1, 0, -1};

    int delRow[] = {-1, 0, +1, 0};

    queue<pair<pair<int, int>, int>> q;
    int freshOragne = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (orange[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
            {
                vis[i][j] = 0;
            }

            if (orange[i][j] == 1)
            {
                freshOragne++; // check so that all oranges are visited
            }
        }
    }
    int maxTime = 0;
    int cnt = 0;
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        maxTime = max(d, maxTime);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + delRow[i];
            int nc = c + delCol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != 1 && orange[nr][nc] == 1)
            {
                q.push({{nr, nc}, d + 1});
                vis[nr][nc] = 1;
                cnt++; // check all the oranges are visited
            }
        }
    }

    if (cnt != freshOragne)
    {
        cout << -1;
        return 0;
    }
    cout << "maxTime: " << maxTime << endl;
    return 0;
}