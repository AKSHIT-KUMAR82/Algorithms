#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    //Function to check whether there is any cycle for each component of graph...
    bool CheckCycle(vector<int> &visited,int src,vector<int> adj[]){
        queue<pair<int,int>> track;
        track.push({src,-1});
        visited[src]=1;
        int node,parent;
        while(!track.empty()){
            node=track.front().first;
            parent=track.front().second;
            for(auto i: adj[node]){
                if(visited[i]==1&&parent!=i) return true;
                if(visited[i]==0){
                    track.push({i,node});
                    visited[i]=1;
                }
            }
            track.pop();
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph...
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(CheckCycle(visited,i,adj)) return true;
            }
        }
        return false;
    }
};
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}