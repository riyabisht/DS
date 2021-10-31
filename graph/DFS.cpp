// (undirected graph) Depth first search implementation using stack as a key data structure.
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFS(vector<int> adj[], int t) {
    stack<int> Stack;
    vector<int> visited(11, 0);
    visited[t] = 1;
    cout<<t<<" ";

    Stack.push(t);
    while (!Stack.empty()) {
        for (auto i=adj[t].begin();i!=adj[t].end();i++) {
            if (visited[*i] != 1) {
                visited[*i] = 1;
                cout<<*i<<" ";
                Stack.push(*i);
                t = *i;
                i=adj[t].begin();
            }
        }
        Stack.pop();
        t = Stack.top();
    }
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

int main() {
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
    DFS(adj,1);

    return 0;
}