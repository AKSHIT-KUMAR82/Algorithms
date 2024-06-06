#include <bits/stdc++.h>
using namespace std;


class Solution {
  private:
    //Function to detect cycle in each component of graph...
    bool CheckCycle(int src,vector<int> adj[],vector<int> &visited,vector<int> &path){
        visited[src]=1;
        path[src]=1;
        for(auto i:adj[src]){
            if(visited[i]==0){
                if(CheckCycle(i,adj,visited,path)) return true;
            }else{
                if(path[i]==1){
                    return true;
                }
            }
        }
        path[src]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> path(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(CheckCycle(i,adj,visited,path)) return true;
            }
        }
        return false;
    }
    
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
