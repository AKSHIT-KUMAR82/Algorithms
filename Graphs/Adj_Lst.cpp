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

    void print_edges(){
        for(int i=0;i<V;i++){
            cout<<i<<" : ";
            for(int j:AdjLst[i]){
                cout<<j<<" ";
            }
            cout<<endl;
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
    g1.print_edges();
    return 0;
}