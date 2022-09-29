# graph

## representation
  - adjacency matrix
  - adjacency list
  - key-value pair (edges, weight)

## traversal
  - bfs
  - dfs

## Topological sort 

- Linear ordering of graph 
- Only possible for DAG 
- topological sorting starts when it has 0 prerequisites/vertex with 0 incoming edges 
- more than one topological sort is possible 

- Application 

- cycle detection 
  topological sorting of a cyclic graph is not possible 

## minimum spanning trees
- MST - Minimum spanning Tree
   - connected, undirected, +ve weighted subgraph
   - used to find min weight set of edges that connects all of the vertices.
   - spanning tree with a weight less than or equal to the weight of every other spanning tree.
   - if 'n' nodes then n-1 edges

- Applications of mst
      
  - Network design : lines that connects all your offices with a minimum total cost.
  - telephone, electrical, hydraulic, TV cable, computer, road
  - Travelling saleperson problem, Steiner tree

### Kruskal Algorithm
  - Greedy approch
  
  - step1: sort edges in accending order of their weights
  - step2: pick smallest edge and check weather it forms cycle with spanning tree formed so far
  - step3: if cycle not formed, include this edge.Else discard it.
  - step4: Repeat step2 until there are n-1 edges in the spanning tree.

  - use Uninon find to detect cycle

  - [kruskal's algo](4.graph/kruskal.cpp)   

### Prim algorithms (Greedy Algorithms)
  - Brovuka'a Algorithm
## Shortest Path
  - Single source shortest paths
    - Dijkstra (Greedy Approach)
    - Bellman ford (Dynamic Programming)
  - All pair shortest path
    - Floyd Warshall
    - Johnson's Algorithm
## Connectivity
  - Path between two vertices
  - Bridges in a graph
  - Articulation Points
  - Eulerian Path



