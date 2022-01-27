# ENCODING TECHNIQUES

## BYTE COUNT / CHARACTER COUNT
`Implement the data link layer framing method “Byte Count”`
This method is rarely used and is generally required to count total number of characters that are present in frame. This is be done by using field in header. Character count method ensures data link layer at the receiver or destination about total number of characters that follow, and about where the frame ends.
There is disadvantage also of using this method i.e., if anyhow character count is disturbed or distorted by an error occurring during transmission, then destination or receiver might lose synchronization. The destination or receiver might also be not able to locate or identify beginning of next frame.

## CYCLIC REDUNDANCY CHECK METHOD
`A k-bit stream is transmitted by the sender using the standard Cyclic Redundancy Check (CRC) method. The generator polynomial is xm + x + 1, where m < k. Show the actual bit string transmitted. Suppose that the one bit in the bit stream is inverted during transmission. Show that this error is detected at the receiver’s end.` 
Cyclic Redundancy Check (CRC) is an error detection method. It is based on binary division.
### CRC Generator-
CRC generator is an algebraic polynomial represented as a bit pattern. Bit pattern is obtained from the CRC generator using the following rule-
The power of each term gives the position of the bit and the coefficient gives the value of the bit.
 

Example-
 Consider the CRC generator is x7 + x6 + x4 + x3 + x + 1. The corresponding binary pattern is obtained as- Thus, for the given CRC generator, the corresponding binary pattern is 11011011.

 

Properties Of CRC Generator-
 The algebraic polynomial chosen as a CRC generator should have at least the following properties-
 - Rule-01: It should not be divisible by x. This condition guarantees that all the burst errors of length equal to the length of polynomial are detected.
 - Rule-02: It should be divisible by x+1. This condition guarantees that all the burst errors affecting an odd number of bits are detected.
 

Important Notes-
 If the CRC generator is chosen according to the above rules, then-
- CRC can detect all single-bit errors
- CRC can detect all double-bit errors provided the divisor contains at least three logic 1’s.
- CRC can detect any odd number of errors provided the divisor is a factor of x+1.
- CRC can detect all burst error of length less than the degree of the polynomial.
- CRC can detect most of the larger burst errors with a high probability.
 

`Step-01: Calculation Of CRC At Sender Side` At sender side, A string of n 0’s is appended to the data unit to be transmitted. Here, n is one less than the number of bits in CRC generator. Binary division is performed of the resultant string with the CRC generator. After division, the remainder so obtained is called as CRC. It may be noted that CRC also consists of n bits.
 

`Step-02: Appending CRC To Data Unit`- At sender side, The CRC is obtained after the binary division.
The string of n 0’s appended to the data unit earlier is replaced by the CRC remainder.
 

`Step-03: Transmission To Receiver`- The newly formed code word (Original data + CRC) is transmitted to the receiver.
 

`Step-04: Checking at Receiver Side`- At receiver side, The transmitted code word is received. The received code word is divided with the same CRC generator. On division, the remainder so obtained is checked.
 


