# [Platinum IV] 탈옥 - 9376 

[문제 링크](https://www.acmicpc.net/problem/9376) 

### 성능 요약

메모리: 2312 KB, 시간: 8 ms

### 분류

0-1 너비 우선 탐색, 너비 우선 탐색, 데이크스트라, 그래프 이론, 그래프 탐색, 최단 경로

### 제출 일자

2024년 12월 1일 19:23:05

### 문제 설명

<p>John is on a mission to get two people out of prison. This particular prison is a one-story building. He has managed to get hold of a detailed ﬂoor plan, indicating all the walls and doors. He also knows the locations of the two people he needs to set free. The prison guards are not the problem – he has planned a diversion that should leave the building practically void.</p>

<p>The doors are his main concern. All doors are normally opened remotely from a control room, but John can open them by other means. Once he has managed to open a door, it remains open. However, opening a door takes time, which he does not have much of, since his diversion will only work for so long. He therefore wants to minimize the number of doors he needs to open. Can you help him plan the optimal route to get to the two prisoners?</p>

### 입력 

 <p>On the ﬁrst line one positive number: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with two space-separated integers h and w (2 ≤ h, w ≤ 100): the width and height of the map.</li>
	<li>h lines with w characters describing the prison building:
	<ul>
		<li>‘.’ is an empty space.</li>
		<li>‘*’ is an impenetrable wall.</li>
		<li>‘#’ is a door.</li>
		<li>‘<span>$</span>’ is one of the two people to be liberated.</li>
	</ul>
	</li>
</ul>

<p>John can freely move around the outside of the building. There are exactly two people on the map. For each person, a path from the outside to that person is guaranteed to exist.</p>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with a single integer: the minimum number of doors John needs to open in order to get to both prisoners.</li>
</ul>

