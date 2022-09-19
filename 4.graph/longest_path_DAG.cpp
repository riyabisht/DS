#include <climits>
#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>

using namespace std;

class Graph {
public:
  vector<vector<pair<int, int>>> adj;
  stack<int> st;
  vector<int> visited;

  Graph(int vertex) {
    adj = vector<vector<pair<int, int>>>(vertex);
    visited = vector<int>(vertex, INT_MIN);
  }
  // longest Path in DAG

  // dfs
  // topological sort
  void topological_order(int u) {
    // if not visited
    if (visited[u] == INT_MIN) {
      visited[u] = 1;
      for (auto i : adj[u])
        topological_order(i.first);
      st.push(u);
    }
  }

  // add edge
  void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
  }

  // print topological order
  void printtopo() {
    while (!st.empty()) {
      cout << st.top();
      st.pop();
    }
  }

  // print graph
  void printGraph(int v) {
    cout << endl;
    for (int j = 0; j < v; j++) {
      cout << "u :" << j;
      for (auto i : adj[j]) {
        cout << "->" << i.first << "(" << i.second << ")";
      }
      cout << endl;
    }
  }
};

int main() {

  int vertex = 0, edges = 0, source = 0;
  cout << "vertex edges source" << endl;
  cin >> vertex >> edges >> source;

  Graph g(vertex);

  for (int i = 1; i <= edges; i++) {
    int u, v, weight;
    cin >> u >> v >> weight;
    g.addEdge(u, v, weight);
  }
  g.printGraph(vertex);

  // find topological order
  for (int i = 0; i < vertex; i++) {
    g.topological_order(i);
  }

  // reinitiallise all vertices
  g.visited = vector<int>(vertex, INT_MIN);
  g.visited[source] = 0;
  for (int i = 0; i < vertex; i++) {
    // source vertex
    if (g.visited[i] != INT_MIN) {
    }
  }

  return 0;
}
