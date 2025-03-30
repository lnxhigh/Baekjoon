# [Platinum IV] 돌 던지기 - 3025 

[문제 링크](https://www.acmicpc.net/problem/3025) 

### 성능 요약

메모리: 11516 KB, 시간: 36 ms

### 분류

자료 구조, 구현, 시뮬레이션, 스택

### 제출 일자

2025년 3월 30일 22:05:13

### 문제 설명

<p>For nearly two weeks now, Domeniko has been lying in his bed because his friend Nedjeljko accidently threw a large rock on his left foot. As Domeniko has already solved the tasks from all Croatian national competitions since 1998, he has to find a new way to kill time. </p>

<p>Domeniko's new game is played on an R×C board. Initially every square is either empty or blocked by a wall. Domeniko throws a rock into the board by putting it in the topmost row of a column and then letting gravity do the rest. </p>

<p>Gravity works as follows: </p>

<ul>
	<li>If the square under the rock is a wall or if the rock is in the bottom row of a column, then the rock remains there. </li>
	<li>If the square under the rock is empty, then the rock moves to that square. </li>
	<li>If the square under the rock contains another rock, then the falling rock may slide sideways: 
	<ul>
		<li>If the squares left and left-down of the rock are empty, then the rock slides one square left. </li>
		<li>If the rock doesn't slide left and the squares to the right and right-down are empty, then the rock slides one square right. </li>
		<li>Otherwise, the rock remains there and never moves again. </li>
	</ul>
	</li>
</ul>

<p>Domeniko will never throw another rock while the previous rock hasn't settled down. </p>

<p>Write a program that draws the board after Domeniko throws all his rocks into the board, if we know the columns that Domeniko threw his rocks into, in order. </p>

<p>Note: Domeniko will never throw a rock into column in which the top row isn't empty.</p>

### 입력 

 <p>The first line contains integers R and C (1 ≤ R ≤ 30000, 1 ≤ C ≤ 30), the size of the board. </p>

<p>Each of the following R lines contains C characters, the initial layout of the board. A '.' represents an empty field, while the uppercase letter 'X' is a square blocked by a wall. </p>

<p>The next line contains an integer N (1 ≤ N ≤ 100000), the number of rocks Domeniko throws. </p>

<p>Each of the following N lines contains an integer between 1 and C, the column into which Domeniko throws a rock (the leftmost column is column 1). </p>

<p>Note: In 60% of the test cases, R will be no more than 30.</p>

### 출력 

 <p>Output R lines, each containing C characters, the final layout of the board. Rocks should be presented with an uppercase letter 'O'. </p>

