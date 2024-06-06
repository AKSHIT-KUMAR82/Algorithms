#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S, vector<int> &parent)
    {
        vector<int> distance(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distance[S] = 0;
        parent[S] = S;
        pq.push({0, S});
        int u, v, weight, dis;
        while (!pq.empty())
        {
            u = pq.top().second;
            dis = pq.top().first;
            pq.pop();
            for (auto i : adj[u])
            {
                v = i[0];
                weight = i[1];
                if (distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }
        return distance;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int i = 0;
    while (i++ < E)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }
    int S;
    cin >> S;
    vector<int> parent(V);
    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S, parent);
    int node;
    cout << "ENTER NODE FOR WHICH YOU WANT TO PRINT THE SHORTEST PATH FROM SOURCE NODE : ";
    cin >> node;
    vector<int> path;
    while (node != parent[node])
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(node);
    cout << "PATH AS FOLLOWS : ";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << "\nSHORTEST DISTANCE FROM SOURCE : " << res[path[0]];

    return 0;
}
