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

    vector<int> BFS(){
        //We are assuming that traversal always starts with 0 indexed node...
        vector<int> visited(V,0),result; //0-based indexing for verticles...
        queue<int> store;
        visited[0]=1;
        store.push(0);
        result.push_back(0);
        int val;
        while(!store.empty()){
            val=store.front();
            store.pop();
            for(auto i:AdjLst[val]){
                if(visited[i]!=1){
                    visited[i]=1;
                    store.push(i);
                    result.push_back(i);
                }
            }
        }
        return result;
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
    cout<<"BFS TRAVERSAL OF THE GRAPH AS FOLLOWS : ";
    vector<int> result=g1.BFS();
    for(auto val:result){
        cout<<val<<" ";
    }
    return 0;
}