#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    vector<vector<int>> AdjLst;

public :

    Graph(int V){
        this->V=V;
        AdjLst.resize(V);
    }

    void Store_AdjLst(int u,int v){
        //Undirected graph
        AdjLst[u].push_back(v);
        AdjLst[v].push_back(u);
    }

    void DFS(vector<int> &visited,int start,vector<int> &result){
        visited[start]=1;
        result.push_back(start);
        for(auto i:AdjLst[start]){
            if(visited[i]==0)
              DFS(visited,i,result);
        }
    }

    
};

int main(){
    int V,E;
    cout<<"ENTER NO. OF VERTICLES AND EDGES : ";
    cin>>V>>E;
    Graph g1(V);
    cout<<"ENTER THE EDGES : \n";
    int u,v;
    for(int i=1;i<=E;i++){
        cin>>u>>v;
        g1.Store_AdjLst(u,v);
    }
    vector<int> visited(V,0),result;
    g1.DFS(visited,0,result);
    cout<<"DFS TRAVERSAL OF THE GRAPH AS FOLLOWS : ";
    for(auto i:result){
        cout<<i<<" ";
    }
    
    return 0;
}