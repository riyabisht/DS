#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef vector<vector<pair<int,int>>> vip;
typedef vector<int> vi;

void print_graph(vip graph){
    cout<<"u"<<"   v"<<"    weights"<<endl;
    int node =0;
    for(auto i:graph){
        for(auto j:i){
            cout<<node<<"   "<<j.second<<"    "<<j.first<<endl;
        }
        node++;
    }

}
bool allVisited(vector<bool> mst){
    for(auto i:mst){
        if(i==false)
        return false;
    }
    return true;
}
int minimum(vi key,vector<bool> mst){
    int min = INT16_MAX;
    int index;
    for(int i=0;i<key.size();i++){
        if (mst[i]==false && key[i]<min){ 
        min = key[i];
        index =i;
        }
    }
    return index;
}
void prims(vip graph,vi key,vector<bool> mst,vi &parent){

    //repeat 3 steps until all nodes are not visited
    while(allVisited(mst)==false){
    //step 1: take index whose value is mini mum 
    int u = minimum(key,mst);

    //step 2: mark it visited   
    mst[u]=true;

    //step 3: find all adjacent nodes
    for(auto i:graph[u]){
        int v = i.second;
        //update key & parent if satisfy condition :  u--wt-->v   wt<key[v]  
        if(i.first<key[v]){
            key[v]=i.first;
            parent[v]=u;
        }
    }
    }
}
int main(){
    //weighted graph
    //pair={wt,node}
    vector<vector<pair<int,int>>> graph; 
    graph={
        {{2,1},{6,3}},
        {{2,0},{3,2},{8,3},{5,4}},
        {{3,1},{7,4}},
        {{6,0},{8,1}},
        {{5,1},{7,2}}
    };
    int size = graph.size();

    //for storing minimum weights
    vector<int>key(size,INT16_MAX);
    //for marking node visited or not
    vector<bool>mst(size,false);
    //for keeping track of parent node
    //final parent array provide us the answer
    vector<int>parent(size,-1);

    //initialise
    //let start node 0
    key[0]=0;
    prims(graph,key,mst,parent);
    //print_graph(graph);
    for(auto i:parent){
        cout<<i<<" ";
    }
    
    return 0;
}