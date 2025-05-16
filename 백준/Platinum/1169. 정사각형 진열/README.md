# [Platinum V] 정사각형 진열 - 1169 

[문제 링크](https://www.acmicpc.net/problem/1169) 

### 성능 요약

메모리: 2020 KB, 시간: 4 ms

### 분류

그리디 알고리즘, 기하학

### 제출 일자

2025년 5월 17일 03:09:54

### 문제 설명

<p>In this problem, you are given a sequence S<sub>1</sub>, S<sub>2</sub>,..., S<sub>n</sub> of squares of different sizes. The sides of the squares are integer numbers. We locate the squares on the positive x - y quarter of the plane, such that their sides make 45 degrees with x and y axes, and one of their vertices are on y = 0 line. Let b<sub>i</sub> be the x coordinates of the bottom vertex of S<sub>i</sub> . First, put S<sub>1</sub> such that its left vertex lies on x = 0 . Then, put S<sub>i</sub> , (i > 1) at minimum b<sub>i</sub> such that</p>

<ol>
	<li>b<sub>i</sub> > b<sub>i-1</sub> and</li>
	<li>the interior of S<sub>i</sub> does not have intersection with the interior of S<sub>1</sub>...S<sub>i-1</sub> .</li>
</ol>

<p><img alt="" src="https://www.acmicpc.net/upload/201003/sq.JPG" style="height:149px; width:236px"></p>

<p>The goal is to find which squares are visible, either entirely or partially, when viewed from above. In the example above, the squares S<sub>1</sub> , S<sub>2</sub> , and S<sub>4</sub> have this property. More formally, S<sub>i</sub> is visible from above if it contains a point p , such that no square other than S<sub>i</sub> intersect the vertical half-line drawn from p upwards.</p>

### 입력 

 <p>The input consists of multiple test cases. The first line of each test case is n (1 ≤ n ≤ 50) , the number of squares. The second line contains n integers between 1 to 30, where the i-th number is the length of the sides of S<sub>i</sub> . The input is terminated by a line containing a zero number.</p>

<p> </p>

### 출력 

 <p>For each test case, output a single line containing the index of the visible squares in the input sequence, in ascending order, separated by blank characters.</p>

