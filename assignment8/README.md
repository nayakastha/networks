# SHORTEST PATH ROUTING ALGORITHM
In computer networks, the shortest path algorithms aim to find the optimal paths between the network nodes so that routing cost is minimized. They are direct applications of the shortest path algorithms proposed in graph theory.

Consider that a network comprises of N vertices (nodes or network devices) that are connected by M edges (transmission lines). Each edge is associated with a weight, representing the physical distance or the transmission delay of the transmission line. The target of shortest path algorithms is to find a route between any pair of vertices along the edges, so the sum of weights of edges is minimum. If the edges are of equal weights, the shortest path algorithm aims to find a route having minimum number of hops.

### Dijkstra’s Algorithm
Input − A graph representing the network; and a source node.
Output − A shortest path tree, spt[], with s as the root node.

Initializations −
- An array of distances dist[] of size |V| (number of nodes), where dist[s] = 0 and dist[u] = ∞ (infinite), where u represents a node in the graph except s.
- An array, Q, containing all nodes in the graph. When the algorithm runs into completion, Q will become empty.
- An empty set, S, to which the visited nodes will be added. When the algorithm runs into completion, S will contain all the nodes in the graph.
- Repeat while Q is not empty −

    - Remove from Q, the node, u having the smallest dist[u] and which is not in S. In the first run, dist[s] is removed.
    - Add u to S, marking u as visited.
    - For each node v which is adjacent to u, update dist[v] as −
    - If (dist[u] + weight of edge u-v) < dist[v], Then
    - Update dist[v] = dist[u] + weight of edge u-v
- The array dist[] contains the shortest path from s to every other node.