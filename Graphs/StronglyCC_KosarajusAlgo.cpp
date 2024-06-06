#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    //Function to sort all the edges of the graph based on their finishing time.
    void DFS1(int start,vector<vector<int>> &adj,vector<int> &visited,stack<int> &st){
        visited[start]=1;
        for(auto i:adj[start]){
            if(visited[i]==0){
                DFS1(i,adj,visited,st);
            }
        }
        st.push(start);
    }
    
    void DFS2(int start,vector<vector<int>> &adj2,vector<int> &visited){
        visited[start]=1;
        for(auto i:adj2[start]){
            if(visited[i]==0){
                DFS2(i,adj2,visited);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> visited(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                DFS1(i,adj,visited,st);
            }
        }
        
        //After above code, We got a stack having vertex placed on the basis of their finishing time...
        //Step 2: Now our task is to reverse all the edges..
        vector<vector<int>> adj2(V);
        for(int i=0;i<V;i++){
            visited[i]=0;
            for(auto j:adj[i]){
                adj2[j].push_back(i);
            }
        }
        
        //Step 3: Now, Just call dfs again in order of stack that we had....
        int val,TotalSsc=0;
        while(!st.empty()){
            val=st.top();
            st.pop();
            if(visited[val]==0){
                DFS2(val,adj2,visited);
                TotalSsc++;
            }
        }
        
        return TotalSsc;
        
    }
};


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
