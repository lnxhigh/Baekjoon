# [Gold III] NxM 보드 완주하기 - 9944 

[문제 링크](https://www.acmicpc.net/problem/9944) 

### 성능 요약

메모리: 2028 KB, 시간: 396 ms

### 분류

백트래킹, 구현

### 제출 일자

2025년 2월 22일 00:44:07

### 문제 설명

<p>A game starts with an M × N board with some squares marked as “obstacles” (drawn as dark squares in the figure below). The player chooses a starting position for a ball (drawn as solid gray dot) and chooses a direction (up, down, left, or right) to advance. Once the direction is chosen, the ball will advance in that direction until it hits an obstacle, the boundary of the board, or its own trajectory. When it hits one of these, the ball stops. Then the player is allowed to choose another direction, and the ball will advance in the same manner. The game ends when no legal move can be made. The player wins if and only if the trajectory includes all the empty squares on the board. The figure below traces a trajectory that shows one way to win the game in 10 steps.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images2/fboard.png" style="height:219px; width:244px"></p>

<p>Given an initial setting of a board, write a program to calculate the minimum number of steps to win the game.</p>

### 입력 

 <p>Each case on the input file begins with two integers m and n (1 ≤ m, n ≤ 30), indicating the size of board.The next m lines describe the initial setting of the board. Each line contains n characters, either ‘*’ or ‘.’, indicating if the corresponding square is an obstacle or empty, respectively. [For example, see below for the input file corresponding to the case in the figure above.] It is guaranteed that the initial board is not fully covered by obstacles. Process until end-of-file; there is no end of data flag.</p>

### 출력 

 <p>Output the minimum number of steps to cover the board. Follow the format exactly: “Case”, one space, the case number, a colon and one space, and one integer indicating the minimum number of steps to win the game, or if there is no way to win, the number -1. Do not print any trailing spaces</p>

