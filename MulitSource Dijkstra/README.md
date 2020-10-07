Description:

Dijkstra Algorithm is used to find the cost of shortest path from a given source vertex to all the other vertices.In the case of Multi Source Dijkstra Algorithm we need to find the shortest distance of all the vertices from a set of source vertices.

To achieve this :
We can add a dummy node connecting to all the source vertices with edge weight of value 0. Now ,we can apply normal single source dijkstra algorithm to get the shortest distance of all the vertices from any source vertices.
