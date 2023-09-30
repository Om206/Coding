#include <bits/stdc++.h>
using namespace std;

void printSet(set<pair<int, int>> &st)
{
    for (auto it : st)
    {
        cout << it.first << " " << it.second << endl;
    }
}
void usePriorityQueue(vector<int> &dist, vector<int> &src, vector<pair<int, int>> adj[],
                      int v, int n, int sr)
{
    priority_queue<pair<int, int>> qr;
    qr.push({0, sr});
    dist[sr] = 0;
    while (!qr.empty())
    {
        int node = qr.top().second;
        int d = qr.top().first;
        qr.pop();
        for (auto &it : adj[node])
        {
            if (d + it.second < dist[it.first])
            {
                dist[it.first] = d + it.second;
                qr.push({dist[it.first], it.first});
                src[it.first] = node;
            }
        }
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
    for (auto &it : dist)
        it = 1e9;
    for (auto &it : src)
        it = 0;
    // no need to go here just for priority_queue i wrote this code
    cout << "\n\n\n using priority_queue\n\n";
    usePriorityQueue(dist, src, adj, v, n, sc);
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