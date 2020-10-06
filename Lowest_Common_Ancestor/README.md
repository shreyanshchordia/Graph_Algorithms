LOWEST COMMON ANCESTOR (A Standard Graph Algorithm).
	
Description :-

Given a graph consisting of Nodes.We want to get the Lowest Common Ancestor of any two nodes of the graph, for several number of querries.
Constraints: 
The number of nodes are upto 10^5.(1 based Indexing).

This algorithm returns the lowest common ancestor for each querry in O(logn) time complexity.

Algorithm Description:-

We Observe that when we are traversing the graph using Depth First Search Algorithm then suppose a particular node is having a discovery time 'X'(the time at which that node is discovered using dfs) and finish time 'Y'(the time at which the the discovery of that node and all the nodes in subtree of that node are finished).
So a node 'N' is ancestor of a node 'M' iff discovery_time(N)<discovery_time(M) and finish_time(N)>finish_time(M). So this concept is used along with the concept of Binary Lifting to calculate the lowest common Ancestor of two nodes of graph.
