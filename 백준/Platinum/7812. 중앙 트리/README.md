# [Platinum V] 중앙 트리 - 7812 

[문제 링크](https://www.acmicpc.net/problem/7812) 

### 성능 요약

메모리: 3808 KB, 시간: 36 ms

### 분류

깊이 우선 탐색, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 트리

### 제출 일자

2025년 1월 26일 21:47:28

### 문제 설명

<p>A tree is a connected graph containing no cycles. A vertex is called a median vertex if the total cost to reach all vertices is minimal. There could be more than one median vertex in a tree, that’s why we define median as the set of all median vertices. To find median in a tree with small number of vertices is fairly easy task as you can solve this by a simple brute force program.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/treemedian.gif" style="float:left; height:156px; width:250px">In the left figure, we can see a weighted tree with 5 vertices. The tree median is {B} because the total cost from vertex B to all other vertices is minimal.</p>

<p>B-A = 2    B-D = 7<br>
B-C = 1    B-E = 7 + 5 = 12</p>

<p>TOTAL = 2 + 1 + 7 + 12 = 22</p>

<p>What if the number of vertices is quite large? This might be a problem since brute force program cost too much time. Given a weighted tree with N vertices, output the total cost to reach all vertices from its median.</p>

### 입력 

 <p>Input consists of several cases. Each case begins with an integer n (1<= n <= 10,000) denoting the number of vertices in a tree. Each vertex is numbered from 0...n-1. Each of the next n-1 lines contains three integers: a, b, and w (1<= w <= 100), which means a and b is connected by an edge with weight w.</p>

<p>Input is terminated when n is equal to 0. This input should not be processed.</p>

### 출력 

 <p>For each case, output a line containing the sum of cost of path to all other vertices from the tree median.</p>

<p> </p>

