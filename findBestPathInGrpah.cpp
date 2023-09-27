#include <bits/stdc++.h>

using namespace std;

bool dfs(int current, bool visited[], int pathVisited[], vector<int> adjList[], int check[])
{
    visited[current] = true;
    pathVisited[current] = 1;
    check[current] = 0;
    for (int nextVertex : adjList[current])
    {
        if (!visited[nextVertex])
        {
            if (dfs(nextVertex, visited, pathVisited, adjList, check) == true)
            {
                check[current] = 0;
                return true;
            }
        }
        else if (pathVisited[nextVertex])
        {
            check[current] = 0;
            return true;
        }
    }

    pathVisited[current] = 0;
    check[current] = 1;
    return false;
}
int main()
{
    int n;
    int x, y;
    int range;
    cin >> n >> range;
    vector<int> adjList[range];
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        adjList[x].push_back(y);
    }
    int count = 0;
    bool Visited[range] = {false};
    int pathVisited[range] = {0};
    int check[range] = {0};
    for (int i = 0; i < range; i++)
    {
        if (!Visited[i])
        {
            dfs(i, Visited, pathVisited, adjList, check);
        }
    }

    for (int i = 0; i < range; i++)
    {
        if (check[i])
            cout << i << " ";
    }
    cout << endl;
    // cout << ("count %d", count) << endl;
}