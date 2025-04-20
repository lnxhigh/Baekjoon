# [Gold I] 로봇 청소기 - 4991 

[문제 링크](https://www.acmicpc.net/problem/4991) 

### 성능 요약

메모리: 2648 KB, 시간: 156 ms

### 분류

너비 우선 탐색, 비트마스킹, 브루트포스 알고리즘, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 4월 20일 13:45:30

### 문제 설명

<p>Here, we want to solve path planning for a mobile robot cleaning a rectangular room floor with furniture.</p>

<p>Consider the room floor paved with square tiles whose size fits the cleaning robot (1 × 1). There are 'clean tiles' and 'dirty tiles', and the robot can change a 'dirty tile' to a 'clean tile' by visiting the tile. Also there may be some obstacles (furniture) whose size fits a tile in the room. If there is an obstacle on a tile, the robot cannot visit it. The robot moves to an adjacent tile with one move. The tile onto which the robot moves must be one of four tiles (i.e., east, west, north or south) adjacent to the tile where the robot is present. The robot may visit a tile twice or more.</p>

<p>Your task is to write a program which computes the minimum number of moves for the robot to change all 'dirty tiles' to 'clean tiles', if ever possible.</p>

### 입력 

 <p>The input consists of multiple maps, each representing the size and arrangement of the room. A map is given in the following format.</p>

<pre>w h
c<sub>11</sub> c<sub>12</sub> c<sub>13</sub> ... c<sub>1w</sub>
c<sub>21</sub> c<sub>22</sub> c<sub>23</sub> ... c<sub>2w</sub>
...
c<sub>h1</sub> c<sub>h2</sub> c<sub>h3</sub> ... c<sub>hw</sub></pre>

<p>The integers w and h are the lengths of the two sides of the floor of the room in terms of widths of floor tiles. w and h are less than or equal to 20. The character c<sub>yx</sub> represents what is initially on the tile with coordinates (x, y) as follows.</p>

<ul>
	<li>'<code>.</code>' : a clean tile</li>
	<li>'<code>*</code>' : a dirty tile </li>
	<li>'<code>x</code>' : a piece of furniture (obstacle) </li>
	<li>'<code>o</code>' : the robot (initial position)</li>
</ul>

<p>In the map the number of 'dirty tiles' does not exceed 10. There is only one 'robot'.</p>

<p>The end of the input is indicated by a line containing two zeros.</p>

### 출력 

 <p>For each map, your program should output a line containing the minimum number of moves. If the map includes 'dirty tiles' which the robot cannot reach, your program should output -1.</p>

