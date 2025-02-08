# [Platinum IV] 평면도 - 3136 

[문제 링크](https://www.acmicpc.net/problem/3136) 

### 성능 요약

메모리: 33704 KB, 시간: 132 ms

### 분류

자료 구조, 오일러 지표 (χ=V-E+F), 기하학, 해시를 사용한 집합과 맵

### 제출 일자

2025년 2월 8일 11:47:30

### 문제 설명

<p>The architect Mirko has given his three-year old son, Mirko, Jr., the task of creating the floor plan for the building he is currently working on. </p>

<p>The surface he will be working on is a huge piece of paper modeled by a coordinate plane, on which all points with integer coordinates are marked. Mirko, Jr. draws the floor plan by putting his pencil in the origin and making N fast and clumsy strokes. In each stroke, he moves the pencil (without lifting it off the surface) straight to one of the 8 neighbouring points (horizontally, vertically or diagonally). The possible strokes are numbered 0 to 7 as shown in the image below. </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/0890f805-9491-4781-964f-8e013864bae7/-/preview/" style="width: 209px; height: 216px;"></p>

<p style="text-align: center;">The 8 possible moves.</p>

<p>After several thousand strokes, Mirko, Jr. finally gets tired after which his father attempts to count the number of rooms in the floor plan. A room is an empty space in the floor plan, surrounded by pencil strokes on all sides. Note that it is possible for rooms to have "holes" i.e. to completely surround other rooms. Also, it is possible for that Mirko, Jr. draws the same wall segment more than once. </p>

<p>Write a program that, given the exact pencil strokes, calculates the number of rooms in the floor plan. </p>

### 입력 

 <p>The first line contains an integer N (1 ≤ N ≤ 100000), the number of pencil strokes. </p>

<p>The second line contains a string of N digits between 0 and 7, the pencil strokes in order in which Mirko, Jr. makes them. </p>

### 출력 

 <p>Output the number of rooms in the floor plan.</p>

