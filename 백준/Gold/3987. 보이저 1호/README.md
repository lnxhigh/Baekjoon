# [Gold V] 보이저 1호 - 3987 

[문제 링크](https://www.acmicpc.net/problem/3987) 

### 성능 요약

메모리: 3300 KB, 시간: 4 ms

### 분류

그래프 이론, 그래프 탐색, 구현, 시뮬레이션

### 제출 일자

2025년 2월 13일 13:31:51

### 문제 설명

<p>The Voyager 1 space probe (not to be confused with the Intrepid-class starship) was launched a long time ago, in 1977, and is currently on the verge of leaving our Solar System. As it travels further through space, it has been programmed to leave a radio signal message in any star system it stumbles upon, to mark the probe's path for as long as possible. </p>

<p>Let us assume that a star system can be represented by a rectangular grid with N rows and M columns, dividing the space into N by M equal cells. Each cell can contain a single planet, black hole, or be empty. The probe broadcasts the signal from a pre-determined empty cell, in one of the four axis-aligned directions (“U”-up, “R”-right, “D”-down, “L”-left). Upon being broadcast, the signal propagates in a straight line along the same row/column until it reaches a planet, where it is deflected by 90 degrees in another direction. There are two kinds of planets, which we will denote by „/“ and „\“. The deflection rules are shown in the image below: </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d64de82b-5fce-46ac-a54a-315b0a157136/-/preview/" style="width: 641px; height: 134px;"></p>

<p>The signal permanently leaves the system upon either entring a cell containing a black hole, or propagating outside the edges of the rectangular grid. It is also known that the signal needs one second to propagate from the current cell to a neighbouring one. </p>

<p>Write a program to determine the direction in which the probe needs to broadcast the signal so that it remains within the system for as long as possible, outputting the optimal direction as well as the resulting longest time. If it is possible for the signal to remain in the system indefinitely, output the message „Voyager“ instead of the required time. </p>

### 입력 

 <p>The first line of input contains two positive integers, N (1 ≤ N ≤ 500) and M (1 ≤ M ≤ 500). </p>

<p>Each of the following N lines contains M characters from the set {“/”, “\”, “C”, “.”}, where “/” and “\” represent the two kinds of planets, “C” represents a black hole, and “.” represents an empty cell.</p>

<p>The last line of input contains two positive integers, PR (1 ≤ PR ≤ N) and PC (1 ≤ PC ≤ M), the row and column number, respectively, of the cell where the probe is situated. </p>

### 출력 

 <p>The first line of output must contain the required optimal broadcast direction (“U”, “R”, “D”, or “L”). If the solution is not unique, select the first optimal one in the following priority order: first “U”, then “R”, then “D”, and finally “L”. </p>

<p>The second line of output must contain the required longest time (or message).</p>

