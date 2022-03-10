# FLOODING ROUTING TECHNIQUE
Flooding is a non-adaptive routing technique following this simple method: when a data packet arrives at a router, it is sent to all the outgoing links except the one it has arrived on. For example, let us consider the network in the figure, having six routers that are connected through transmission lines.

Using flooding technique −
An incoming packet to A, will be sent to B, C and D.
B will send the packet to C and E.
C will send the packet to B, D and F.
D will send the packet to C and F.
E will send the packet to F.
F will send the packet to C and E.

Types of Flooding
Flooding may be of three types −
- Uncontrolled flooding − Here, each router unconditionally transmits the incoming data packets to all its neighbours.Controlled flooding − They use some methods to control the transmission of packets to the neighbouring nodes. The two popular algorithms for controlled flooding are Sequence Number - Controlled Flooding (SNCF) and Reverse Path Forwarding (RPF).
- Selective flooding − Here, the routers don't transmit the incoming packets only along those paths which are heading towards approximately in the right direction, instead of every available paths.

Advantages of Flooding
- It is very simple to setup and implement, since a router may know only its neighbours.
- It is extremely robust. Even in case of malfunctioning of a large number routers, the packets find a way to reach the destination.
- All nodes which are directly or indirectly connected are visited. So, there are no chances for any node to be left out. This is a main criteria in case of broadcast messages.
-The shortest path is always chosen by flooding.

Limitations of Flooding
- Flooding tends to create an infinite number of duplicate data packets, unless some measures are adopted to damp packet generation.
- It is wasteful if a single destination needs the packet, since it delivers the data packet to all nodes irrespective of the destination.
- The network may be clogged with unwanted and duplicate data packets. This may hamper delivery of other data packets.

### Compare flooding with deterministic (k=1) in terms of both delay and bandwidth used
