#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[], vector<pair<int, int>> &MinSpanTree)
    {
        //We are assuming that we have 0-indexed nodes...
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> MinHeap;
        vector<int> visited(V,0);
        MinHeap.push({0,{0,-1}});
        int MinWeight=0,node,parent,weight;
        while(!MinHeap.empty()){
            node=MinHeap.top().second.first;
            parent=MinHeap.top().second.second;
            weight=MinHeap.top().first;
            MinHeap.pop();
            if(visited[node]==0){
                visited[node]=1;
                MinWeight+=weight;
                for(auto i:adj[node]){
                    if(visited[i[0]]==0){
                        MinHeap.push({i[1],{i[0],node}});
                    }
                }
                if(parent!=-1){
                    MinSpanTree.push_back({parent,node});
                }
            }
        }
        return MinWeight;
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
    vector<pair<int, int>> MinSpanTree;
    Solution obj;
    cout << "Minimum spanning tree weight : "<<obj.spanningTree(V, adj, MinSpanTree) << "\n";
    cout<<"Edges in the MSP : \n";
    for(auto i:MinSpanTree){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}

/* Theory :
 Here what we are doing is , We can start with any starting node, then we have create a vector called visited to track the visited nodes
 and along with that we have to make a min heap for storing pair of <weight,node> in which we push starting node with 0 weight then we have to
 run a while loop till the min heap becomes empty then for each iteration we have to get it's top value and check whether that node is already
 visited or not...........If its visited then just simply pop it out and if it's not visited then add it's weight to the MinWeight and mark it
 visited thereafter for that value move across in adjacency list and for each of it's vector check if it's not visited then push that value into
 min heap with it's edge weight for the current node and after doing so the whole process at last we'll get MinWeight but if we also asked to print
 the edges that have been included in the minimum spanning tree then we have to store one more value which is parent in min heap
 i.e vector<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> MinHeap*/