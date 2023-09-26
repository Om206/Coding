#include <bits/stdc++.h>

using namespace std;
const int N = 10005;
vector<int> adjList[N];
bool Visited[N];

void dfs(int current)
{
    Visited[current] = true;
    for (int nextVertex : adjList[current])
    {
        if (Visited[nextVertex])
            continue;
        dfs(nextVertex);
    }
}
int main()
{
    int n;
    int x, y;
    int range;
    cin >> n >> range;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    int count = 0;
    for (int i = 0; i < range; i++)
    {
        if (!Visited[i])
        {
            cout << "Hello\n";
            count++;
            dfs(i);
        }
    }

    cout << ("count %d", count) << endl;
}