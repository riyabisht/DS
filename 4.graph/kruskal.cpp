#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Graph {
public:
  vector<vector<pair<int, int>>> adj;
  vector<int> parent;
  vector<pair<int, pair<int, int>>> edgeList;

  Graph(int vertex, int edge) {
    adj = vector<vector<pair<int, int>>>(vertex);
    edgeList = vector<pair<int, pair<int, int>>>(edge);
    parent = vector<int>(vertex);
  }

  //add edge
  void addEdge(int u, int v, int weight) {
    adj[u].push_back({
        weight,
        v,
    });
    adj[v].push_back({weight, u});
  }

  // find
  int find(int i) {
    if (parent[i] == i)
      return i;
    return find(parent[i]);
  }

  // merge
  void merge(int u, int v) {
    int n1 = find(u);
    int n2 = find(v);
    if (n1 < n2) {
      parent[n2] = n1;
    } else {
      parent[n1] = n2;
    }
  }

  // print graph
  void print(int vertex) {
    for (int i = 0; i < vertex; i++) {
      cout << i << "-->";
      for (auto j : adj[i]) {
        cout << j.second << " ";
      }
      cout << endl;
    }
  }

  // Kruskal
  void kruskal(int edge, int vertex) {
    int minWeight = 0;
    vector<vector<int>> mst(vertex);
    for (int i = 0; i < vertex; i++)
      parent[i] = i;

    sort(edgeList.begin(), edgeList.end());
    for (auto i : edgeList) {
      cout << i.first << " " << i.second.first << " " << i.second.second;
      cout << endl;
    }

    for (auto i : edgeList) {
      int u, v, a, b;
      u = i.second.first;
      v = i.second.second;
      if (find(u) != find(v)) {
        merge(u, v);
        mst[u].push_back(v);
        cout << u << "---" << v << "=" << i.first << endl;
        minWeight += i.first;
      }
    }
    cout << minWeight;
  }
 
};

int main() {
  int vertex, edge;
  cin >> vertex >> edge;
  Graph g(vertex, edge);
  for (int i = 0; i < edge; i++) {
    int u, v, weight;
    cin >> u >> v >> weight;
    g.addEdge(u, v, weight);
    g.edgeList.push_back({weight, {u, v}});
  }
  g.print(vertex);
  g.kruskal(edge, vertex);
  return 0;
}