#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    vector<vector<int>> AdjMat;

public :

    Graph(int V){
        this->V=V;
        AdjMat.resize(V,vector<int> (V,0));
    }

    void Store_AdjMat(int u,int v){
        //Undirected graph
        AdjMat[u][v]=1;
        AdjMat[v][u]=1;
    }

    void print_edges(){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cout<<AdjMat[i][j]<<" ";
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
        g1.Store_AdjMat(u,v);
    }
    g1.print_edges();
    return 0;
}