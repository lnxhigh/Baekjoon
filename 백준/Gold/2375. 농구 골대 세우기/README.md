# [Gold III] 농구 골대 세우기 - 2375 

[문제 링크](https://www.acmicpc.net/problem/2375) 

### 성능 요약

메모리: 7404 KB, 시간: 44 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2025년 6월 19일 21:01:23

### 문제 설명

<p>흔히 알고 있는 2차원 평면과 같은 격자 나라가 있다.</p>

<p style="text-align: center;"><img alt="" src="https://www.acmicpc.net/JudgeOnline/upload/201103/goal.png" style="height:281px; width:295px"></p>

<p>이 나라에는 위와 같이 원점에서 거리가 정수가 되는 지점에 x축과 또는 y축과 평행하게 길이 나있고 세로로 나있는 길과 가로로 나있는 길이 교차하는 모든 곳에만 마을이 있어서 사람이 살고 있다.</p>

<p>이중에 n개의 마을 사람들만 농구를 좋아하고 이 사람들을 위해 나라에서 농구 골대 딱 하나를 세워주고자 한다.</p>

<p>농구를 좋아하는 어느 마을도 큰 불이익이 없게 하기 위해 각각 농구를 좋아하는 마을에 대해서 ( 각 마을에서 농구골대까지의 거리 × 그 마을의 사람 수 )의 합이 최소화되는 마을에 농구골대를 세우고자 한다. 농구골대는 (길이 아닌)마을에 세워져야 하며 그 마을은 꼭 농구를 좋아하는 마을일 필요는 없다.</p>

<p>한 마을에서 다른 마을까지의 거리는 길을 따라 이동한 최단거리로 간주한다.  이렇게 측정하는 거리를 맨하탄 거리(manhattan distance)라고 한다. 예를들면 (x<sub>1</sub>, y<sub>1</sub>)에서 (x<sub>2</sub>, y<sub>2</sub>)까지의 거리는 |x<sub>2</sub> - x<sub>1</sub>|+|y<sub>2</sub> - y<sub>1</sub>|이다.</p>

### 입력 

 <p>첫 줄에 농구를 좋아하는 마을의 개수인 n이 주어지고 다음 줄부터 x<sub>i</sub>, y<sub>i</sub>, p<sub>i</sub>와 같이 한 줄에 농구를 좋아하는 하나의 마을에 대한 정보가 주어진다. 두 마을의 위치가 같은 경우는 없다.</p>

### 출력 

 <p>한 줄에 농구골대를 세워야 하는 마을의 위치를 출력한다. 만약 답이 되는 여러 개의 마을이 존재한다면 우선 x좌표가 가장 작은 마을을, 그리고 y좌표가 가장 작은 마을을 출력한다.</p>

