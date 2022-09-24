#include <errno.h>
#include <iostream>
#include <limits.h>
#include <stack>
#include <stdio.h>
#include <vcruntime.h>
#include <vector>

using namespace std;
class Graph {
public:
  vector<vector<pair<int, int>>> adj;
  stack<int> st;
  vector<int> visited;
  vector<int> dis;

  Graph(int v) {
    visited = vector<int>(v, false);
    dis = vector<int>(v, INT_MAX);
    adj = vector<vector<pair<int, int>>>(v);
  }

  void topological_sort(int u) {
      visited[u] = true;
      for (auto i : adj[u]) {
        //cout<<i.first<<" ";
        if (!visited[i.first]) {
         // cout<<i.first<<" ";
          topological_sort(i.first);
        }
      }
      st.push(u);
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

  void printTopo() {
    while (!st.empty()) {
      cout << st.top();
      st.pop();
    }
  }
  void shortest_path(int source, int nodes) {
    dis[source] = 0;
    while (!st.empty()) {

      int u = st.top();
      st.pop();
      if (dis[u] != INT_MAX) {
        for (auto i : adj[u]) {
          // update weights of adjacent vertices
          if (dis[i.first] > dis[u] + i.second)
            dis[i.first] = dis[u] + i.second;
        }
      }
    }
    for (auto i : dis) {
      (i == INT_MAX) ? cout << "INF " : cout << -1*i << " ";
    }
  }

  void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
  }
};
int main() {
  int nodes, edges, source;
  cout << "nodes edges source";
  cin >> nodes >> edges >> source;
  Graph g(nodes);
  cout << "u v weight\n";

  // buid graph
  for (int i = 0; i < edges; i++) {
    int v, u, w;
    cin >> u >> v >> w;
    // negate edge weights
    g.addEdge(u, v, -1 * w);
  }

  //g.printGraph(nodes);

  // find topological sort
  for (int i = 0; i < nodes; i++) {
    if (!g.visited[i]) {
       g.topological_sort(i);
    }
  }

  //g.printTopo();
  // shortest path
  g.shortest_path(source, nodes);

  return 0;
}