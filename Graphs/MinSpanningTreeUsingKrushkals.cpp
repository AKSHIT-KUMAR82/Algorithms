#include<bits/stdc++.h>
using namespace std;

class disjoint{
    private:
    vector<int> rank;
    vector<int> parent;
    
    public:
    disjoint(int V){
        rank.resize(V,0);
        parent.resize(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
    }
    
    int Uparent(int node){
        if(node==parent[node]){
            //It means We have reached to ultimate parent for that component 
            return node;
        }
        return (parent[node]=Uparent(parent[node]));
    }
    
    void UnionByRank(int u,int v){
        int UPu,UPv;
        UPu=Uparent(u);
        UPv=Uparent(v);
        if(UPu==UPv) return;
        if(rank[UPu]>rank[UPv]){
            parent[UPv]=UPu;
        }
        else if(rank[UPu]<rank[UPv]){
            parent[UPu]=UPv;
        }
        else{
            parent[UPu]=UPv;
            rank[UPv]++;
        }
        return;
    }
    
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> store;
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                store.push_back({j[1],{i,j[0]}});
            }
        }
        sort(store.begin(),store.end());
        int u,v,weight,TotalMinWeight=0;
        disjoint obj(V);
        for(int i=0;i<store.size();i++){
            u=store[i].second.first;
            v=store[i].second.second;
            weight=store[i].first;
            if(obj.Uparent(u)!=obj.Uparent(v)){
                TotalMinWeight+=weight;
                obj.UnionByRank(u,v);
            }
        }
        return TotalMinWeight;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}