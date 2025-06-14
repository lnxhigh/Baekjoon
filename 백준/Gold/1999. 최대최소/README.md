# [Gold IV] 최대최소 - 1999 

[문제 링크](https://www.acmicpc.net/problem/1999) 

### 성능 요약

메모리: 2788 KB, 시간: 76 ms

### 분류

자료 구조, 다이나믹 프로그래밍

### 제출 일자

2025년 6월 14일 18:56:44

### 문제 설명

<p>FJ has decided to grow his own corn hybrid in order to help the cows make the best possible milk.  To that end, he's looking to build the cornfield on the flattest piece of land he can find.</p>

<p>FJ has, at great expense, surveyed his square farm of N x N hectares (1 <= N <= 250). Each hectare has an integer elevation (0 <= elevation <= 250) associated with it.</p>

<p>FJ will present your program with the elevations and a set of K (1 <= K <= 100,000) queries of the form "in this B x B submatrix, what is the maximum and minimum elevation?".  The integer B (1 <= B <= N) is the size of one edge of the square cornfield and is a constant for every inquiry. Help FJ find the best place to put his cornfield.</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: N, B, and K.</li>
	<li>Lines 2..N+1: Each line contains N space-separated integers.  Line 2 represents row 1; line 3 represents row 2, etc.  The first integer on each line represents column 1; the second integer represents column 2; etc.</li>
	<li>Lines N+2..N+K+1: Each line contains two space-separated integers representing a query. The first integer is the top row of the query; the second integer is the left column of the query.  The integers are in the range 1..N-B+1.</li>
</ul>

### 출력 

 <ul>
	<li>Lines 1..K: A single integer per line representing the difference between the max and the min in each query.</li>
</ul>

