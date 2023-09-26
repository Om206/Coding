#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> adjList[N + 1];
bool visited[N + 1];

bool dfs(int node, int parent)
{
    visited[node] = true;
    for (auto adj : adjList[node])
    {
        if (!visited[adj])
        {
            if (dfs(adj, node))
                return true;
        }
        else if (adj != parent)
        {
            return true;
        }
    }
    return false;
}

bool detect(int src)
{
    visited[src] = true;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto adj : adjList[node])
        {
            if (!visited[adj])
            {
                visited[adj] = true;
                q.push({adj, node});
            }
            else if (parent != adj)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    bool result = false;
    result = detect(1);

    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         if (dfs(i, -1))
    //         {
    //             result = true;
    //             break;
    //         }
    //     }
    // }
    cout << "result: " << result << endl;
}