# [Gold III] 미친 아두이노 - 8972 

[문제 링크](https://www.acmicpc.net/problem/8972) 

### 성능 요약

메모리: 2344 KB, 시간: 8 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2025년 3월 3일 14:00:34

### 문제 설명

<p>In the computer game Robots, the player tries to escape mad robots. There are many robots against the lone player, but their movement is predictable and the player can take advantage of that. </p>

<p>The game is played on a board of size R×C. The following 5 steps are repeated: </p>

<ol>
	<li>The player moves in one of eight directions (horizontally, vertically or diagonally) or stays in the same cell. </li>
	<li>If the player moves to a cell occupied by a robot, the game ends and the player loses. </li>
	<li>Every robot moves in one of eight directions, to the neighbouring cell closest to the player. More precisely, the robot attempts to minimize the value of |r1−r2| + |s1−s2|, where (r1, s1) and (r2, s2) are the positions of the player and robot. </li>
	<li>If any robot has entered the player's cell, the game ends and the player loses. </li>
	<li>If two or more robots have entered the same cell, a large explosion destroys all the robots in that cell. </li>
</ol>

<p>You will be given the starting location of the player, the locations of all robots and the moves the player makes. If the player makes all his moves and survives, you are to output the state of the board after all his moves. Otherwise, output how many moves he was able to make. </p>

### 입력 

 <p>The first line of input contains two integers R and C (1 ≤ R ≤ 100, 1 ≤ S ≤ 100), the number of rows and columns on the board. </p>

<p>The following R lines contain C characters each, depicting the initial state on the board: the character '.' denotes an empty cell, 'R' a cell occupied by a robot, and 'I' the cell with the player. </p>

<p>The final line contains a string of at most 100 digits, the player's moves. Each move is a digit from 1 to 9, 5 meaning the player does not move, the rest according to this diagram: </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a5693c73-112b-416c-8398-42fddd09c6e7/-/preview/" style="width: 112px; height: 112px;"></p>

<p>The input sequence of moves will be such that the player will never attempt to move outside the board. </p>

### 출력 

 <p>If the player makes all the moves and survives, output the final state of the board in the same format as in the output. Otherwise, output "kraj X" (quotes for clarity), where X is the number of moves the player made.</p>

