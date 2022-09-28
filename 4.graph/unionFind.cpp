// Program to detect cycle using union find algorithm
#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
  vector<vector<pair<int, int>>> adj;
  vector<int> parent;
  Graph(int vertex) {
    adj = vector<vector<pair<int, int>>>(vertex);
    parent = vector<int>(vertex);
  }

  void Addedge(int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
  }

  int find(int i) {
    if (i == parent[i])
      return i;
    return find(parent[i]);
  }

  void Union(int u, int v) {
    parent[v] = u;
  }

  bool detectcycle(int vertex) {
    for (int i = 0; i < vertex; i++)
      parent[i] = i;

    for (int i = 0; i < vertex; i++) {
      int a, b;
      a = find(i);
      for (auto j : adj[i]) {
        b = find(j.first);
        if (a == b) return true;
        else
          Union(i, j.first);
      }
    }
    return false;
  }
};

int main() {
  int vertex, edge;
  cout << "vertex edge";
  cin >> vertex >> edge;
  Graph g(vertex);
  for (int i = 0; i < edge; i++) {
    int u, v, weight;
    cin >> u >> v >> weight;
    g.Addedge(u, v, weight);
  }
  if (g.detectcycle(vertex))
    cout << "cycle present";
  else
    cout << "cycle not present";

  return 0;
}