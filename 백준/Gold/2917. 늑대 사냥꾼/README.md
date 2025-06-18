# [Gold II] 늑대 사냥꾼 - 2917 

[문제 링크](https://www.acmicpc.net/problem/2917) 

### 성능 요약

메모리: 6636 KB, 시간: 16 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 데이크스트라, 격자 그래프

### 제출 일자

2025년 6월 19일 01:42:43

### 문제 설명

<p>Vjekoslav the Wolf is running away from a bunch of blood hungry hunters. The hunters are smart and hide behind trees. Vjekoslav knows this, but doesn't know which trees. He would like to run to his comfortable, civilized cottage (as opposed to the hunters quite uncivilized den, yes I am rooting for the Wolf here) staying as far away as possible from any trees.</p>

<p>The forest can be represented as a N by M gird. Let us mark empty meadow patches with '.', patches with a tree in the middle with '+', Vjekoslav's current position with 'V' and the position of his cottage with 'J'. Vjekoslav can run from his current patch to any other patch north, east, south or west from him, even if it contains a tree.</p>

<p>If Vjekoslav is standing in R-th row and C-th column on the grid and there is a tree in the A-th row and B-th column then the distance between Vjekoslav and that tree is:</p>

<p>|R-A| + |C-B|</p>

<p>Help Vjekoslav find the best route to his cottage. The best route is any route that maximizes the minimal distance between Vjekoslav and all trees at any given moment.</p>

<p>Note that Vjekoslav's cottage doesn't occupy the entire patch so that patch must also be included in the route.</p>

### 입력 

 <p>The first line of input contains integers N and M (1 ≤ N, M ≤ 500), grid dimensions.</p>

<p>The next N lines contain M characters each: '.', '+', 'V', 'J'.</p>

<p>Input will contain exactly one character 'V' and 'J' and at least one character '+'.</p>

### 출력 

 <p>Output a single integer, the minimal distance from a tree in the optimal route.</p>

