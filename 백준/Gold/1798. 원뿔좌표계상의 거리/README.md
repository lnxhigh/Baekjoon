# [Gold I] 원뿔좌표계상의 거리 - 1798 

[문제 링크](https://www.acmicpc.net/problem/1798) 

### 성능 요약

메모리: 2120 KB, 시간: 0 ms

### 분류

기하학, 3차원 기하학, 수학

### 제출 일자

2025년 5월 4일 07:57:03

### 문제 설명

<p>A cone is located in 3D such that its base of radius <em>r</em> is in the <em>z</em> = 0 plane with the center at (0,0,0). The tip of the cone is located at (0, 0, <em>h</em>). Two points are given on the cone surface in conic coordinates. The conic coordinates of a point <em>p</em> lying on the surface of the cone are two numbers: the first, <em>d</em>, is the distance from the tip of the cone to <em>p</em> and the second, <em>A</em> < 360, is the angle in degrees between the plane <em>y</em> = 0 and the plane through points (0,0,0), (0,0,<em>h</em>) and <em>p</em>, measured counterclockwise from the direction of the x axis.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images2/cone.gif" style="height:317px; width:289px"></p>

<p>Given are two points <em>p<sub>1</sub></em> = (<em>d<sub>1</sub>, A<sub>1</sub></em>) and <em>p<sub>2</sub></em> = (<em>d<sub>2</sub>, A<sub>2</sub></em>) in the conic coordinates. What is the (shortest) distance between <em>p<sub>1</sub></em> and <em>p<sub>2</sub></em> measured on the surface of the cone?</p>

### 입력 

 <p>The input is a sequence of lines. Each line contains 6 floating point numbers giving values of: <em>r</em>, <em>h</em>, <em>d<sub>1</sub></em>, <em>A<sub>1</sub></em>, <em>d<sub>2</sub></em>, and <em>A<sub>2</sub></em></p>

### 출력 

 <p>For each line of input, output the (shortest) distance between points <em>p<sub>1</sub></em> and <em>p<sub>2</sub></em> on the surface of the cone with the fraction rounded to 2 decimal places.</p>

