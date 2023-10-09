#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, noOfEdges, src;
    cin >> V >> noOfEdges >> src;
    vector<vector<int>> edges;
    for (int i = 0; i < noOfEdges; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }

    vector<int> dist(V, 1e8);
    dist[src] = 0;
    // N - 1 cycles to find the shotest
    for (int i = 0; i < V - 1; i++)
    {
        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // last cycle if dist get updated then we can say there is a negitive edge cycle present
    for (auto &it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
        {
            cout << "Negitive edge cycle present\n";
            return 0;
        }
    }

    cout << "No negitive edge cycle present\n";
    cout << "shortest path from src: " << src << " is\n";

    for (int i = 0; i < V; i++)
    {
        cout << "dist from " << src << " to " << i << " is " << dist[i] << endl;
    }
    return 0;
}