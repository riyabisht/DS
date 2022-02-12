//Implementation of breath first search. Key data structure for this
//algorithm is a queue

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void show(vector<int> adj[]) {
    for (int i = 1; i < 11; i++) {
        cout << "Adjacent vertex of head vertex " << i << endl;
        for (auto j : adj[i])
            cout << "-->" << j;
        cout << endl;
    }
    cout<<endl;
}
// BFS code
void BFS(vector<int> adj[], int s) {
    // visited will keep tack of the visited node
    vector<int> visited(11, 0);   
    visited[s] = 1;
    
    //queue is used to store the vertices
    //pop one element a time and check for its adjacent vertiex
    //if the vertex is not visited, mark it 1 and store it in queue
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        s = Q.front();
        cout<<s<<" ";
        Q.pop();

        for (auto i : adj[s]) {
            if (visited[i] != 1) {
                visited[i] = 1;
                Q.push(i);
            }
        }
    }
    cout<<endl;
}


int main() {
    int V = 11;
    vector<int> adj[11];
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 4, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 8);
    addEdge(adj, 2, 7);
    addEdge(adj, 3, 10);
    addEdge(adj, 3, 9);
    addEdge(adj, 5, 6);
    addEdge(adj, 5, 8);
    addEdge(adj, 5, 7);
    addEdge(adj, 7, 8);
    show(adj);
    BFS(adj,1);
    
}