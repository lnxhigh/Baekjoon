# [Gold IV] IP 주소 - 2064 

[문제 링크](https://www.acmicpc.net/problem/2064) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

비트마스킹, 구현

### 제출 일자

2025년 3월 9일 21:38:18

### 문제 설명

<p>Alex is administrator of IP networks. His clients have a bunch of individual IP addresses and he decided to group all those IP addresses into the smallest possible IP network.</p>

<p>Each IP address is a 4-byte number that is written byte-by-byte in a decimal dot-separated notation “byte0.byte1.byte2.byte3” (quotes are added for clarity). Each byte is written as a decimal number from 0 to 255 (inclusive) without extra leading zeroes.</p>

<p>IP network is described by two 4-byte numbers — network address and network mask. Both network address and network mask are written in the same notation as IP addresses.</p>

<p>In order to understand the meaning of network address and network mask you have to consider their binary representation. Binary representation of IP address, network address, and network mask consists of 32 bits: 8 bits for byte0 (most significant to least significant), followed by 8 bits for byte1, followed by 8 bits for byte2, and followed by 8 bits for byte3.</p>

<p>IP network contains a range of 2n IP addresses where 0 ≤ n ≤ 32. Network mask always has 32 − n first bits set to one, and n last bits set to zero in its binary representation. Network address has arbitrary 32 − n first bits, and n last bits set to zero in its binary representation. IP network contains all IP addresses whose 32 − n first bits are equal to 32 − n first bits of network address with arbitrary n last bits. We say that one IP network is smaller than the other IP network if it contains fewer IP addresses.</p>

<p>For example, IP network with network address 194.85.160.176 and network mask 255.255.255.248 contains 8 IP addresses from 194.85.160.176 to 194.85.160.183 (inclusive).</p>

### 입력 

 <p>The first line of the input file contains a single integer number m (1 ≤ m ≤ 1000). The following m lines contain IP addresses, one address on a line. Each IP address may appear more than once in the input file.</p>

### 출력 

 <p>Write to the output file two lines that describe the smallest possible IP network that contains all IP addresses from the input file. Write network address on the first line and network mask on the second line.</p>

