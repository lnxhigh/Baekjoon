# [Gold IV] 양궁 - 9553 

[문제 링크](https://www.acmicpc.net/problem/9553) 

### 성능 요약

메모리: 2240 KB, 시간: 4 ms

### 분류

기하학, 기댓값의 선형성, 수학, 확률론

### 제출 일자

2025년 2월 3일 03:28:02

### 문제 설명

<p>Last summer you were watching all the matches in the 2012 Olympics in London. One of the interesting sports is archery (it’s the game of propelling arrows with the use of a bow to hit a target), but in this problem we are dealing with a new type of archery.</p>

<p>In this new type of archery, the player has arrows that can penetrate any target and can go to infinity (the same arrow may hit more than one target), and there will be a lot of targets around the player everywhere, and the targets may intersect and/or overlap with each others.</p>

<p>From the top view you can model the targets as line segments and the player as a point at the origin (point (0,0) is the origin), also there will be no target which intersects with the player’s position.</p>

<p>You are really interested to calculate the expected number of targets this player can penetrate using one arrow, if he will shoot his arrow in a random direction (there are infinite number of different directions, and each direction has the same probability to be used for the random shoot).</p>

<p>For example, the following figure explains the first sample test case, where the player is at the origin, and there are two targets T<sub>1</sub> with end points (1,5) and (3,3), and T<sub>2</sub> with end points (3,5) and (6,2), you can notice that there is a region where the player can shoot an arrow and penetrate the two targets, and there are two regions where he can penetrate only one target, and the last region he will not penetrate any target.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images2/archery.png" style="height:323px; width:317px"></p>

<p>Note that a target can be hit at any point between its 2 end points (inclusive).</p>

### 입력 

 <p>Your program will be tested on one or more test cases. The first line of the input will be a single integer T, the number of test cases (1 ≤ T ≤ 100). Followed by the test cases, each test case starts with a line containing one integer N (1 ≤ N ≤ 100) representing the number of targets in the game. Followed by N lines, the i-th line contains 4 integers separated by a single space X<sub>1</sub> Y<sub>1</sub> X<sub>2</sub> Y<sub>2</sub> (−100 ≤ X<sub>1</sub>, Y<sub>1</sub>, X<sub>2</sub>, Y<sub>2</sub> ≤ 100) representing the i-th target end points (X<sub>1</sub>, Y<sub>1</sub>) and (X<sub>2</sub>, Y<sub>2</sub>)</p>

### 출력 

 <p>For each test case, print on a single line, a single number representing the expected number of targets the player can penetrate using one arrow, rounded to five decimal places.</p>

