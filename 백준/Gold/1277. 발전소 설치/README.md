# [Gold IV] 발전소 설치 - 1277 

[문제 링크](https://www.acmicpc.net/problem/1277) 

### 성능 요약

메모리: 10504 KB, 시간: 12 ms

### 분류

그래프 이론, 최단 경로, 데이크스트라

### 제출 일자

2025년 6월 6일 14:21:34

### 문제 설명

<p>A vicious thunderstorm has destroyed some of the wires of the farm's electrical power grid! Farmer John has a map of all N (2 <= N <= 1,000) of the powerpoles, which are conveniently numbered 1..N and located on integer plane coordinates x_i,y_i (-100,000 <= x_i <= 100000; -100,000 <= y_i <= 100,000).</p>

<p>Some W (1 <= W <= 10,000) power wires connect pairs of power poles Pi and Pj (1 <= Pi <= N; 1 <= Pj <= N).</p>

<p>He needs to get power from pole 1 to pole N (which means that some series of wires can traverse from pole 1 to pole N, probably through some intermediate set of poles).</p>

<p>Given the locations of the N poles and the list of remaining power wires, determine the minimum length of power wire required to restore the electrical connection so that electricity can flow from pole 1 to pole N.  No wire can be longer than some real number M (0.0 < M <= 200,000.0).</p>

<p>As an example, below on the left is a map of the 9 poles and 3 wires after the storm. For this task, M = 2.0. The best set of wires to add would connect poles 4 and 6 and also poles 6 and 9.</p>

<pre>      After the storm              Optimally reconnected

3  . . . 7 9 . . . . .          3  . . . 7 9 . . . . .
                                          /
2  . . 5 6 . . . . . .          2  . . 5 6 . . . . . .
                                        /
1  2-3-4 . 8 . . . . .          1  2-3-4 . 8 . . . . .
   |                               |
0  1 . . . . . . . . .          0  1 . . . . . . . . .

   0 1 2 3 4 5 6 7 8 9             0 1 2 3 4 5 6 7 8 9
</pre>

<p>The total length is then 1.414213562 + 1.414213562 = 2.828427124 .</p>

### 입력 

 <p>* Line 1: Two space-separated integers: N and W</p>

<p>* Line 2: A single real number: M</p>

<p>* Lines 3..N+2: Each line contains two space-separated integers: x_i and y_i</p>

<p>* Lines N+3..N+2+W: Two space-separated integers: Pi and Pj</p>

### 출력 

 <p>* Line 1: A single integer on a single line.  If restoring connection is impossible, output -1. Otherwise, output a single integer that is 1000 times the total minimum cost to restore electricity. Do not perform any rounding; truncate the resulting product.</p>

<p> </p>

