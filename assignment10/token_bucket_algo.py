import time


class TokenBucket:

    def __init__(self, tokens, time_unit, forward_callback, drop_callback):
        self.tokens = tokens
        self.time_unit = time_unit
        self.forward_callback = forward_callback
        self.drop_callback = drop_callback
        self.bucket = tokens
        self.last_check = time.time()

    def handle(self, packet):
        current = time.time()
        time_passed = current - self.last_check
        self.last_check = current

        self.bucket = self.bucket + \
            time_passed * (self.tokens / self.time_unit)

        if (self.bucket > self.tokens):
            self.bucket = self.tokens

        if (self.bucket < 1):
            self.drop_callback(packet)
        else:
            self.bucket = self.bucket - 1
            self.forward_callback(packet)


def forward(packet):
    print("Packet that is forwarded: " + str(packet))


def drop(packet):
    print("Packet that is dropped: " + str(packet))


throttle = TokenBucket(1, 1, forward, drop)

packet = 0
print("---Token Bucket Implementation---")

size = int(input("Enter the number of packets to be transmitted - \n"))

while (packet < size):
    time.sleep(0.2)
    throttle.handle(packet)
    packet += 1