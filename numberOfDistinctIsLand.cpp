#include <bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc, int r, int c, vector<vector<int>> &vis,
         vector<vector<int>> &adj, vector<pair<int, int>> &results, int delRow[], int delCol[])
{
    vis[sr][sc] = 1;
    results.push_back({sr - r, sc - c});
    int n = adj.size();
    int m = adj[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nsr = sr + delRow[i];
        int nsc = sc + delCol[i];
        if (nsr >= 0 && nsr < n && nsc >= 0 && nsc < m &&
            vis[nsr][nsc] != 1 && adj[nsr][nsc] == 1)
        {
            dfs(nsr, nsc, r, c, vis, adj, results, delRow, delCol);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }

    set<vector<pair<int, int>>> s;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && adj[i][j] == 1)
            {
                vector<pair<int, int>> results;
                dfs(i, j, i, j, vis, adj, results, delRow, delCol);
                s.insert(results);
            }
        }
    }

    cout << "number: " << s.size() << endl;
}