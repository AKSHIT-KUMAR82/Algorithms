#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    //Function to check whether there is any cycle for each component of graph...
    bool CheckCycle(vector<int> &visited,int node,int parent,vector<int> adj[]){
        visited[node]=1;
        for(auto i:adj[node]){
            if(visited[i]==1){
                if(i!=parent){
                    return true;
                }
            }
            else{
                if(CheckCycle(visited,i,node,adj)) return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(CheckCycle(visited,i,-1,adj)) return true;
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