# Link State Routing Algorithm vs. Distance Vector Routing Algorithm
Routing is the process of transferring data from a source to a destination over the internet. The two types of routing algorithms are distance vector routing and link state routing, which are classified based on how the routing tables are updated.

The first distinction between distance vector and link state routing is that in distance vector routing, routers share the knowledge of the entire autonomous system, whereas in link state routing, routers only share the knowledge of their immediate neighbours.

## Distance Vector Routing:
Distance Vector Routing protocols determine the best path to a given destination based on distance. The distance metric is usually measured in hops, but it could also be delay, packet loss, or something else. If the distance metric is hop, a hop is traversed each time a packet passes through a router. The route to a given network with the fewest hops is the best route to that network.

The direction of that specific network is shown by the vector. Directly connected neighbours receive the entire routing table sent by distance vector protocols. RIP (Routing Information Protocol) and IGRP (Internal Gateway Routing Protocol) are two examples of distance vector protocols.

It’s a dynamic routing algorithm in which each router calculates the distance between itself and each potential destination, or its immediate neighbours.
The router shares its knowledge of the entire network with its neighbours, and the table is updated accordingly.
Information sharing takes place with neighbours on a regular basis.
Bellman-Ford algorithm helps in creating routing tables.

## Link State Routing:
Shortest-path-first protocols are another name for Link State protocols. Protocols that use link state routing have a complete picture of the network topology. As a result, they have a better understanding of the entire network than any distance vector protocol.

Each router with link state routing creates three separate tables. One table stores information about directly connected neighbours, another stores the topology of the entire internetwork, and the third stores the actual routing table.

All routers in the network receive information about directly connected links via link state protocols. OSPF (Open Shortest Path First) and IS-IS (Intermediate System to Intermediate System) are two examples of Link State Routing Protocols.

It is a dynamic routing algorithm in which each router in the network shares information about its neighbours with all other routers. Through flooding, a router sends information about its neighbours to all other routers. Information sharing happens only when there is a change.
Dijkstra’s Algorithm helps in creating routing tables.

## Inferences
During the experiement we saw that for *nodes < 10* `the distance vector routing duration is shorter than link state routing`. 
But for *nodes > 10*, `the link state routing duration is shorter than distance vector routing`.
Distance vector protocols always choose the route with the fewest number of hops as the best route. This can be a problem when the best route to a destination is not the route with the least number of hops. Convergence time is the amount of time it takes to propagate changes in network topology throughout the internetwork.
Additionally, link state convergence occurs faster than distance vector convergence. This is because link state establishes a neighbor relationship with directly connected peers and shares routing information with its neighbors only when there are changes in the network topology. Link state protocols exchange periodically (about every 90 seconds) send their updates to every router on the network. Also, link state routing protocols only send updates to neighboring routers, unlike distance vector protocols, which send the entire routing table