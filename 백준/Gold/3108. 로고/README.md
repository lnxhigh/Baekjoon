# [Gold II] 로고 - 3108 

[문제 링크](https://www.acmicpc.net/problem/3108) 

### 성능 요약

메모리: 2128 KB, 시간: 72 ms

### 분류

자료 구조, 분리 집합, 기하학

### 제출 일자

2024년 12월 3일 08:18:20

### 문제 설명

<p>Competition tasks for the programming language LOGO often involve drawing rectangles on the screen. Drawing in LOGO is done by moving a turtle-shaped cursor. </p>

<p>The turtle is defined by its position and angle. It holds in its mouth a pencil that can be raised or lowered. When the pencil is lowered, moving the turtle causes the pencil to leave a trail on the screen. </p>

<p>The turtle is initially at coordinates (0, 0) facing in the direction of increasing y coordinates, pencil lowered. We can manipulate the turtle with the following set of commands: </p>

<ol>
	<li>FD x – move the turtle x units forward. </li>
	<li>LT α – turn the turtle α degrees counter-clockwise.</li>
	<li>RT α – turn the turtle α degrees clockwise. </li>
	<li>PU – raise the pencil. </li>
	<li>PD – lower the pencil. </li>
</ol>

<p>Your program will be given a set of rectangles (with sides parallel to coordinate axes) that need to be drawn on the screen. The turtle may go over the same segment with its pencil lowered multiple times, but it is not allowed to draw anything other than the given rectangles. </p>

<p>Write a program that calculates the smallest number of times the pencil must be raised in order to draw all the rectangles. </p>

### 입력 

 <p>The first line contains an integer N (1 ≤ N ≤ 1000), the number of rectangles. </p>

<p>Each of the following N lines contains for integers x1, y1, x2 and y2 (−500 ≤ x1 < x2 ≤ 500), (−500 ≤ y1 < y2 ≤ 500) separated by a space. The points (x1, y1) and (x2, y2) are diagonally opposite corners of a rectangle. </p>

### 출력 

 <p>Output the smallest number of times the pencil must be raised to draw the rectangles. </p>

<p> </p>

