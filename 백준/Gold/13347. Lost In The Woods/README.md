# [Gold I] Lost In The Woods - 13347 

[문제 링크](https://www.acmicpc.net/problem/13347) 

### 성능 요약

메모리: 2020 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍, 수학, 확률론

### 제출 일자

2025년 2월 4일 10:37:14

### 문제 설명

<p>Your friend has gotten lost in the woods. He has called and asked for you to come get him, but you are very busy and would rather just stay home. You quickly look up a map of the woods. It appears that the woods consist of a small number of clearings, with paths connecting them. You hope that the woods are sufficiently small and simple that your friend can get out easily, even if he is just randomly running around.</p>

<p>From your friend’s description, you can figure out at which clearing he is. Assuming that every time he reaches a clearing, he runs in a uniformly random direction (including back the way he came), and that it takes him exactly one minute to get from clearing to clearing, can you predict how long it will take him to get out on average?</p>

### 입력 

 <p>The first line contains two integers N and M, where N is the number of clearings in the woods (2 ≤ N ≤ 20), and M is the total number of paths between clearings. The clearings are numbered 0 through N − 1, such that clearing 0 is the one where your friend is right now and clearing N − 1 is the exit of the woods.</p>

<p>The next M lines each contain two integers K and L, indicating a path between clearing K and clearing L (0 ≤ K, L < M).</p>

<p>You may assume that it is possible for your friend to reach the exit by following paths, that paths do not cross, and that there is at most one path between any two clearings.</p>

### 출력 

 <p>Output a single line containing a single number: the expected value of the number of minutes it will take your friend to get out of the woods.</p>

<p>Your answer may have an absolute error of at most 10<sup>−5</sup>.</p>

