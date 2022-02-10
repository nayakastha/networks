# Selective Repeat ARQ
It is also known as *Sliding Window Protocol* and used for error detection and control in the data link layer.

In the selective repeat, the sender sends several frames specified by a window size even without the need to wait for individual acknowledgement from the receiver as in Go-Back-N ARQ. In selective repeat protocol, the retransmitted frame is received out of sequence.

In Selective Repeat ARQ only the lost or error frames are retransmitted, whereas correct frames are received and buffered.

The receiver while keeping track of sequence numbers buffers the frames in memory and sends NACK for only frames which are missing or damaged. The sender will send/retransmit a packet for which NACK is received.

## Sender (Server Side) - (`server.cpp`)[./server.cpp]: Language: c++
[]: # Path: assignment4\server.c
The algorithm for this process is as.

            1. Start.

            2. Establish connection (recommended UDP)

            3. Accept the window size from the client(should be <=40)

            4. Accept the packets from the network layer.

            5. Calculate the total frames/windows required.

            6. Send the details to the client(totalpackets,totalframes.)

            7. Initialise the transmit buffer.

            8. Built the frame/window depending on the windowsize.

            9. Transmit the frame.

            10. Wait for the acknowledgement frame.

            11. Check for the acknowledgement of each packet and repeat the process for the packet for which the negative acknowledgement isreceived. Else continue as usual.

            12. Increment the frame count and repeat steps 7 to 12 until all packets are transmitted.

            13. Close the connection.

            14.Stop.


## Receiver (Client Side) - (`client.cpp`)[./client.cpp]: Language: c++
The algorithm for this module process is as

            1. Start.

            2. Establish a connection.(recommended UDP)

            3. Send the windowsize on server request.

            4. Accept the details from the server(totalpackets,totalframes).

            5. Initialise the receive buffer with the expected packets.

            6. Accept the frame/window from the server.

            7. Check for validity of the packets and construct the acknowledgement frame depending on the validity.(Here the acknowledgement is accepeted from the users)

            8. Depending on the acknowledgement frame readjust the process.

            9. Increment the framecount and repeat steps 5-9 until all packets are received.

            10. Close the connection.

            11. Stop.