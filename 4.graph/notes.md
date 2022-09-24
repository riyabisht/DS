# graph

- representation
  - adjacency matrix
  - adjacency list
  - key-value pair (edges, weight)
- traversal
  - bfs
  - dfs
- minimum spanning trees
  - Kruskal Algorithm
  - Prim algorithms (Greedy Algorithms)
  - Brovuka'a Algorithm
- Shortest Path
  - Single source shortest paths
    - Dijkstra (Greedy Approach)
    - Bellman ford (Dynamic Programming)
  - All pair shortest path
    - Floyd Warshall
    - Johnson's Algorithm
- Connectivity
  - Path between two vertices
  - Bridges in a graph
  - Articulation Points
  - Eulerian Path

## Topological sort 

- Linear ordering of graph 
- Only possible for DAG 
- topological sorting starts when it has 0 prerequisites/vertex with 0 incoming edges 
- more than one topological sort is possible 

### Application 

- cycle detection 
  topological sorting of a cyclic graph is not possible 

