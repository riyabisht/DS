// Implementation of undirected graph using adjacency list
#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[]) {
    for (int i = 0; i < 5; i++) {
        cout << "Adjacent vertix of head vertex " << i << endl;
        for (auto j : adj[i]) {
            cout << "-->" << j;
        }
        cout << endl;
    }
}
int main() {
    int V = 5;
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj);
}