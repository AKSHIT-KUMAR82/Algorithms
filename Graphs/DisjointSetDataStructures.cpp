//Now, Let's talk about Disjoint sets data structure....

//Why it's used ???

/*
-> Actually it is used to check whether two nodes in a disconnected graph belongs to the same component or not 
in constant time complexity which is very optimised as compared to dfs and bfs traversals which takes O(N+E)~ Linear time complexity.
-> It's very useful in dynamic graphs where structure of graph changes in each step.
*/

//Decription :

/*

-> It basically contains two functions :
1) FindParent(int node) : It returns ultimate parent of the given node in const time complexity(4 alpha)....
2) Union(int u,int v) : It' end goal is to combine u with v but in between there are some steps that we need to follow, It's done using two 
methods : 1) By rank 2) By size...

let's understand it using rank method...
Step 1) Find ultimate parent of u and v
Step 2) Find rank of both the ultimate parents
Step 3) Attack smaller rank component to high rank component

*/

//Now let's start coding....
#include<bits/stdc++.h>
using namespace std;

class disjoint{
    
    private:
    vector<int> parent;
    vector<int> rank;

    public:
    disjoint(int V){
        rank.resize(V,0);
        parent.resize(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
    }

    int FindParent(int node){
        if(node==parent[node]){
            return node;
        }
        return (parent[node]=FindParent(parent[node]));
    }

    void Union(int u,int v){
        int pu,pv;
        pu=FindParent(u);
        pv=FindParent(v);
        if(pu==pv) return;
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
};