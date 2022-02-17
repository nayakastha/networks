# ALOHA Protocols
ALOHA is a multiple access protocol for transmission of data via a shared network channel. It operates in the medium access control sublayer (MAC sublayer) of the open systems interconnection (OSI) model. Using this protocol, several data streams originating from multiple nodes are transferred through a multi-point transmission channel.

In ALOHA, each node or station transmits a frame without trying to detect whether the transmission channel is idle or busy. If the channel is idle, then the frames will be successfully transmitted. If two frames attempt to occupy the channel simultaneously, collision of frames will occur and the frames will be discarded. These stations may choose to retransmit the corrupted frames repeatedly until successful transmission occurs.

There are two major types of ALOHA.

## 1. Pure ALOHA
In pure ALOHA, the time of transmission is continuous.Whenever a station hasan available frame, it sends the frame. If there is collision and the frame is destroyed, the sender waits for a random amount of time before retransmitting it.

## 2. Slotted ALOHA
Slotted ALOHA reduces the number of collisions and doubles the capacity of pure ALOHA. The shared channel is divided into a number of discrete time intervals called slots. A station can transmit only at the beginning of each slot. However,there can still be collisions if more than one station tries to transmit at the beginning of the same time slot.
