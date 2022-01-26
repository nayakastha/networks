 # Understanding Packet Flow Across the Network Part

 ## Why does packet flow happen?
 To explain why packets flow across Network Devices (internally or externally), imagine IP packet generator such HTTP request from web browser asking wikipedia.com’s web server for a particular web page. The PC’s TCP/IP stack went through all the logical steps to accomplish a webpage request and display the web page on the PC.

 ## IP Routing and Ethernet MAC Forwarding
 - *Network Layer Routing Concept*: is based on Dotted Decimal Notation Logical destination IP Address inside the IP Packet (172.16.10.20). Meaning, Internet Protocol (IP) Routes IP packets using IP Address System across the internet without really caring or bothering what LAN medium or WAN connection in use such Ethernet, PPP, HDLC, Frame Relay, ATM, Fiber, etc…, therefore, Internet Protocol (IP) Route IP Packets.
 - *Data-Link Layer Forwarding Concept*: If Ethernet used, is based on 12-Hex Character Physical destination MAC Address inside the frame (3001.2222.2222)Meaning, Ethernet Physical Address is used as a vehicle to transport the Packet, hence, different MAC address is used on each Hop (a.k.a. different vehicle) till the IP Packet reach handled to its final destination.

 ## Routing IP Packets to Default Router
 `By Data, Segments, Packets, and Frames Encapsulation`
 - *Application Layer* encapsulated the HTTP Data Request into HTTP Data Header, and handled the Header to the Transport Layer for further Processing
 - *Transport Layer* encapsulated the HTTP Data Header into Segment adding source and destination TCP ports to the Segment, and handled the Segments to Network Layer for Packing using Logical Addressing.
 - *Network Layer* encapsulated the Segment into an IP Packet adding logical source and destination IP addresses to the packet, and handled the packet to the Data Link Layer for Framing using Hardware Addressing.
 - *Data Link Layer* encapsulated the IP Packet into a Frame adding hardware source and destination MAC addresses to the Frame with Ethernet Header and Trailer, and handled the Frame to the Physical Layer for Delivery using Ethernet Standard or Protocol.
 - *Physical Layer* converted the Frame one at a time to stream of bits, encoded the bits into signals based on the type of media used (Copper, Fiber, or Wireless), and transmitted the signals one at a time to the Default Gateway.

 ## Forwarding Ethernet Frames to Default Router
 it does some analysis and figure out that the IP of `wikipedia.com` is located at different subnet, hence, PC chooses to send the IP packet to the nearby router -> R3.
 In order to route the IP Packet from PC to R3, PC forwards the frame which hold the IP packet across the ethernet medium to; these frames include the packets in the data portion of the Ethernet frames. From PC perspective, the frame that holds the IP Packet must use R3’s MAC address to reach R3’s interface port.
 Once IP Packet  received by R3’s interface port, it will be unpacked/repacked using NEW MAC address, and forwarded again to the nearby Router. This process will be repeated again and again till the IP packet can reach its final destination.

 ## Terms and Protocols
 - *ARP* - The `Address Resolution Protocol(ARP)` is a communication protocol used to discover the data-link layer address(Layer 2 address like Media Access Control(MAC) address) associated with an Internet layer address(Layer 3 address like IPv4 address). 
 - *IPCONFIG* - `ipconfig` stands for Internet Protocol Configuration. This command is used to view all the current TCP/IP network configurations values of the computer.
 - *IFCONFIG* - `ifconfig` stands for Interface Configuration. This command is the same as ipconfig, and is used to view all the current TCP/IP network configurations values of the computer.
 - *Tracert* - The Windows `Tracert` tool determines the route to a destination by sending ICMP packets to the destination. In these packets, Tracert uses varying IP Time-To-Live (TTL) values.
 - *Traceroute* - `Traceroute` is the route tracing tool used on Unix-like Operating Systems (including Mac OS X). On Mac OS X, you can access Traceroute through the Network Utility.
 - *NSLOOKUP* - `nslookup` (from name server lookup) is a network administration command-line tool for querying the Domain Name System (DNS) to obtain the mapping between domain name and IP address, or other DNS records.
 - *NETSTAT* - The `netstat` command generates displays that show network status and protocol statistics. You can display the status of TCP and UDP endpoints in table format, routing table information, and interface information. `netstat` displays various types of network data depending on the command line option selected. 
 - *SNOOP* - The `snoop` command is used to monitor packets on the network. The snoop command must be run as the root user. The use of this command is a good way to ensure that the network hardware is functioning on both the client and the server.
 - *TCPDUMP* - `tcpdump` is a data-network packet analyzer computer program that runs under a command line interface. It allows the user to display TCP/IP and other packets being transmitted or received over a network to which the computer is attached


 