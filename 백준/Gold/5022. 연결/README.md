# [Gold I] 연결 - 5022 

[문제 링크](https://www.acmicpc.net/problem/5022) 

### 성능 요약

메모리: 2168 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 4월 19일 14:07:02

### 문제 설명

<p><img alt="" src="https://www.acmicpc.net/upload/images/connect.png" style="float:right; height:133px; opacity:0.9; width:128px">When constructing electric circuits one has to connect pairs of points using wire, preferable as short as possible. In this problem we have an empty circuit board of size N×M where we want to connect the two points A1 and A2 with each other using one wire, and the two points B1 and B2 with each other using another wire. The wires must go along the horizontal and vertical edges of the grid (see gure), and the two wires may not share a common vertex. Determine the minimum length of wire needed to do so. The wire may not go outside the circuit board.</p>

### 입력 

 <p>The first line contains two integers, N (2 ≤ N ≤ 100) and M (2 ≤ M ≤ 100), the grid size of the circuit board.</p>

<p>Then follows four lines containing the coordinates for the points A1, A2, B1 and B2, respectively. Each coordinate pair will be described using two integers and will correspond to an intersection point in the grid. The rst coordinate will be between 0 and N inclusive and the second coordinate between 0 and M inclusive. All coordinate pairs will be unique.</p>

### 출력 

 <p>A single line containing the minimum length of wire needed to connect the points, or "IMPOSSIBLE" if it's not possible to do so.</p>

