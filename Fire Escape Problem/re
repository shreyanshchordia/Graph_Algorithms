**Description**
This algorithm counts the total number of connected components and the size of connected components. The number of connected components can be count using the following technique.
Depth First Search
Since this is an undirected graph, the number of times a Depth First Search starts from an unvisited vertex is equal to the number of connected components.We would like to store the graph as an adjacency list due to the large number of vertices (the number of edges are not too many).

Pseudo code:
for u = 1 to N
    if u is not visited
        connected_components++
        dfs(u)

dfs(u)
    mark_visited(u)
    for all children v, of u
        if v is not visited
            dfs(v)
