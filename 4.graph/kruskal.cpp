#include <iostream>
#include <vector>
using namespace std;

class Graph{
    public:
    vector<vector<pair<int,int>>> adj;
    vector<int>parent;
    Graph(int vertex){
        adj=vector<vector<pair<int,int>>>(vertex);
        parent = vector<int>(vertex);
    }
    void addEdge(int u,int v , int weight){
        adj[u].push_back({weight,v,});
        adj[v].push_back({weight,u});
    }
    int kruskal(int edge){
        for(int i=0;i<edge;i++){
            int v1,v2;
            v1 = find(i);
            for(auto j:adj[i]){
                v2 = find(j.second);
            }
            if(v1==v2)
                return 1;
        }
    }
};

int main(){
    int vertex,edge;
    cin>>vertex>>edge;
    Graph g(vertex);
    for(int i=0 ; i<edge;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        g.addEdge(u, v, weight);

        g.kruskal(edge);
    }
    return 0;
}