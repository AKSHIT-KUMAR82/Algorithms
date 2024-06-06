#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        int u, v, wt;
        vector<int> dis(V, INT_MAX);
        dis[S] = 0;
        for (int i = 1; i <= V - 1; i++)
        {
            for (int j = 0; j < edges.size(); j++)
            {
                u = edges[j][0];
                v = edges[j][1];
                wt = edges[j][2];
                if (dis[u] != INT_MAX && dis[u] + wt < dis[v])
                {
                    dis[v] = dis[u] + wt;
                }
            }
        }
        for (int j = 0; j < edges.size(); j++)
        {
            u = edges[j][0];
            v = edges[j][1];
            wt = edges[j][2];
            if (dis[u] != INT_MAX && dis[u] + wt < dis[v])
            {
                cout << "Negative edge weight cycle detected\n";
            }
        }

        return dis;
    }
};

int main()
{

    int N, m;
    cin >> N >> m;
    vector<vector<int>> edges;

    for (int i = 0; i < m; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < 3; ++j)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        edges.push_back(temp);
    }

    int src;
    cin >> src;

    Solution obj;
    vector<int> res = obj.bellman_ford(N, edges, src);

    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}