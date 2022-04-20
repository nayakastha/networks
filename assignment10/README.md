# What is Traffic Shaping?

The burst nature of traffic on a network is the main cause of congestion. If the traffic is uniform, there will be no congestion. Hence, to avoid congestion, traffic control tries to solve the problem with excellent design to prevent congestion.

It tries to regulate the traffic after traffic monitoring making the traffic rate more uniform and predictable, hence avoiding congestion. Basically, traffic shaping will regulate the average rate or burst nature of data transmission.

# The Leaky Bucket Algorithm:
Imagine a leaky bucket, i.e. a bucket with a small hole at the bottom. Now imagine a faucet draining water into the bucket. The water will leak out of the bucket at a particular speed. Now increase the speed of water coming from the faucet. However, the water will still leak out of the bucket at the original speed only.

Every host in a network is having a buffer with a finite queue length. Packets coming at different speeds from different sources enter the buffer. The speed of packets going out of buffer is regulated. If there are any packets put in the buffer when the buffer is full, these packets are discarded. If there are no packets in the buffer, the outflow is zero. This is nothing but a single server queuing system with a constant service time hence leading to regulated traffic.

However, the drawback of this leaky bucket algorithm is that it rigidly controls the rate to one fixed value irrespective of the speed of incoming packets. When large bursts of traffic arrive, the fixed value of the data rate of output should also be increased.



# The Token Bucket Algorithms:
It is a variant of the leaky bucket algorithm. The same procedure follows for regulation of speed. The only difference is that the bucket is filled with tokens at a certain rate.

A packet has to grab a token and destroy it to leave the bucket. Hence, packets are never lost. The packets only have to wait until a packet is available and then they leave the bucket. This is used for the production of varying output rates since we can regulate the rate of production of tokens in accordance with the burst or speed of incoming traffic.

If the traffic is large, the speed at which tokens are produced can be increased to a particular extent so that the traffic is regulated and there is no congestion. If the traffic is intermediate or less, the rate at which tokens are produced can be reduced.