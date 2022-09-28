# Disjoint set data structure or Union find Algorithm

- union find 
- undirected graph 
- detect cycle 
- assume their is no self loop
- disjoint set data structure keeps track of set of elements partitioned into a number of disjoint subset
- find : used to find weather two end vertex of edge is belong to same subset or not
- union: join two subset into single subset ,if both don't belong to same subset 

## algorithm
 
- step 1: parent vector which'll be used to check weather both vertex of edge belong to same set or not
- step 2: initialise the parent vector with its own value
- step 3: traverse all the edges one by one 
- step 4: find parent of both 
- step 5: if both are same the then cycle present
- step 6: otherwise merge/union them by parent[u]=v; ( making parent one of other)

[union find](..\unionFind.cpp)
