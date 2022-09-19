// detect no of articualtion point in a graph using Tarjan's Agorithm
#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;     // aticualtion points
vector<bool> vis;    // visited vertices
vector<int> disTime; // discovery time
vector<int> low;     // low discory time ( help to detect back edge)
vector<int> parent;

void dfs(vector<int> graph[], int time, int node) {

  int childGraph = 0;
  vis[node] = true;
  disTime[node] = low[node] = time;
  time++;

  // dfs on adjacent node
  for (auto i : graph[node]) {

    if (!vis[i]) {
      // if adj node not visited count++
      childGraph++;
      parent[i] = node;
      dfs(graph, time, i);

      low[node] = min(low[node], low[i]);

      // check for articulstion point

      // case1: if node is root
      if (parent[node] == -1 && childGraph > 1)
        ans[node] = 1;

      // case2: if node is not root
      // check back edge present or not
      if (parent[node] != -1 && low[i] >= disTime[node])
        ans[node] = 1;

    } else if (i != parent[node])
      low[node] = min(low[node], disTime[i]);
  }
}

vector<int> articualtionPoints(vector<int> graph[], int V) {

  vis = vector<bool>(V, false);
  disTime = vector<int>(V, -1);
  low = vector<int>(V, -1);
  parent = vector<int>(V, -1);
  ans = vector<int>(V, 0);

  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      parent[i] = -1;
      dfs(graph, 0, i);
    }
  }

  return ans;
}

void addEdge(vector<int> graph[], int u, int v) {
  graph[u].push_back(v);
  graph[v].push_back(u);
}
int main() {
  int V;
  int E;
  cin >> V;
  cin >> E;
  int u, v;

  vector<int> graph[V];
  for (int i = 1; i <= E; i++) {
    cin >> u;
    cin >> v;
    addEdge(graph, u, v);
  }
  cout << endl;
  //   for(auto i:graph){
  //     for(auto j:i)
  //       cout<<j<<" ";
  //    cout<<endl;
  //   }

  articualtionPoints(graph, V);
  for (int i = 0; i < V; i++) {
    if (ans[i]) cout << i << " ";
  }
}