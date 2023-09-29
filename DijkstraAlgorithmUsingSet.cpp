#include <bits/stdc++.h>
using namespace std;

void printSet(set<pair<int, int>> &st)
{
    for (auto it : st)
    {
        cout << it.first << " " << it.second << endl;
    }
}
int main()
{
    int v, n, sc;
    cin >> v >> n >> sc;
    set<pair<int, int>> s;
    vector<int> dist(v, 1e9);
    vector<int> src(v, 0);

    vector<pair<int, int>> adj[v];
    int x, y, d;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> d;
        adj[x].push_back({y, d});
        adj[y].push_back({x, d});
    }
    // for (auto it2 : adj)
    // {
    //     for (auto it3 : it2)
    //     {
    //         cout << "{" << it3.first << " " << it3.second << "},";
    //     }
    //     cout << endl;
    // }

    src[sc] = sc;
    s.insert({0, sc});

    while (!s.empty())
    {
        auto it = s.begin();
        int node = (*it).second;
        int d = (*it).first;
        s.erase({d, node});
        dist[sc] = 0;
        for (auto it1 : adj[node])
        {
            int edg = it1.second;
            int adjNode = it1.first;
            if ((d + edg) < dist[adjNode])
            {
                if (dist[adjNode] <= 1e9)
                {
                    s.erase(make_pair(dist[adjNode], adjNode));
                }
                dist[adjNode] = d + edg;
                src[adjNode] = node;
                s.insert(make_pair(dist[adjNode], adjNode));
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << "Src " << sc << " to " << i << ": " << dist[i] << endl;
        cout << "Path is: ";
        int j = i;
        cout << i;
        while (j != sc)
        {
            cout << "<-" << src[j];
            j = src[j];
        }
        cout << endl
             << endl;
    }
}