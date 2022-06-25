#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef  vector<vector<pair<int,int>>> vvip;

vector<int> dijkstra_(vvip graph ,int source){
    //store shortest path
    vector<int>dist(graph.size(),INT16_MAX);

    //want node in increasing order according wo weights
    //need to remove some nodes 
    //use set 
    set<pair<int,int>> weight_store;
    
    //initialise
    dist[source]=0;
    weight_store.insert({0,0});
    while (!weight_store.empty()){
        //fetch top node
        auto top = *(weight_store.begin());
        int u=top.second;
        
        //remove top node
        weight_store.erase(weight_store.begin());

        //adjacent nodes of top
        for(auto i:graph[u]){ // {0.0}---> take node 0 
            int v= i.second;
            if(dist[u]+i.first < dist[v]){

                auto record = weight_store.find({dist[v],v});
                //if record found erase
                if(record!=weight_store.end())
                    weight_store.erase(record);

                //update distance
                dist[v]=dist[u]+i.first; 
                //insert node and weight
                weight_store.insert({dist[v],v});
            }
        }

    }
    
    
    return dist;
}



int main(){

    //weighted graph 
    vector<vector<pair<int,int>>> graph; 
    graph={
        {{7,1},{1,2},{2,3}},
        {{7,0},{3,2},{5,3},{1,4}},
        {{1,0},{3,1}},
        {{2,0},{5,1},{7,4}},
        {{1,1},{7,3}}
    };
    int start=0;
    vector<int>min_dis;
    min_dis= dijkstra_(graph,start);
    for(auto i:min_dis)
        cout<<i<<" ";
    return 0;
}