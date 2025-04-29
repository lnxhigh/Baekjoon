# [Gold II] Pattern Lock - 8894 

[문제 링크](https://www.acmicpc.net/problem/8894) 

### 성능 요약

메모리: 2028 KB, 시간: 4 ms

### 분류

백트래킹, 브루트포스 알고리즘, 구현

### 제출 일자

2025년 4월 30일 00:58:12

### 문제 설명

<p>Pattern lock security is generally used in Android handsets instead of a password. The pattern lock can be set by joining points on a 3×3 matrix in a chosen order. The points of the matrix are registered in a numbered order starting with 1 in the upper left corner and ending with 9 in the bottom right corner. This pattern must involve at least 4 points to set, cannot be disconnected and each point number can be used at most once. So the pattern of the lock screen in Figure 1(b) would be 2-1-5-3-6-8-4-7-9.</p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images2/lock1.png" style="height:136px; width:250px"></p>

<p style="text-align:center">Figure 1. (a) Android pattern lock screen with overlaid identification numbers on contact points. (b) A valid pattern lock.</p>

<p>In Figure 1(b), since the point 8 is already visited, you can connect from point 7 to point 9 directly. If the point 8 is not visited yet, you cannot connect from point 7 to point 9 directly.</p>

<p>Though Chulsoo has completely forgotten his pattern, he can get his pattern image as a geometric graph from his smudged smartphone screen such as Figure 2.</p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images2/lock2.png" style="height:134px; width:253px"></p>

<p style="text-align:center">Figure 2. (a) A pattern image. (b) A geometric graph of the pattern image.</p>

<p>For example, let’s consider four geometric graphs in Figure 3. Since the graph in Figure 3(a) is disconnected, this pattern is not possible to construct. Even though the graph in Figure 3(b) is connected, this pattern cannot be constructed. That is, there is no sequence joining points that makes the given pattern. The pattern given in Figure 3(c) can be constructed by the point-joining sequence 1-8-9-7-4-3 only. The pattern given in Figure 3(d) can be constructed by 4-5-6-3-2-8-9-7-1 or 8-5-2-3-6-4-1-7-9.</p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images2/lock3.png" style="height:127px; width:539px"></p>

<p style="text-align:center">Figure 3. The geometric graphs obtained from smudged smartphone screen.</p>

<p>You are going to find Chulsoo’s pattern lock from his pattern image. Given a pattern image as a geometric graph, write a program to find a possible pattern lock sequence. </p>

### 입력 

 <p>Your prgram is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing an integer e (3 ≤ e ≤ 24), where e is the number of edges of the geometric graph. In the next e lines of each test case, the i-th line contains two integers s<sub>i</sub>, d<sub>i</sub> (i = 1, 2, ..., e and 1 ≤ s<sub>i</sub>, d<sub>i</sub> ≤ 9), which represent an edge between s<sub>i</sub> and d<sub>i</sub>.</p>

### 출력 

 <p>Your program is to write to standard output. For each test case, if it can be possible to recover a pattern code, print a point joining sequence which makes a pattern. Otherwise, print “IMPOSSIBLE”.</p>

