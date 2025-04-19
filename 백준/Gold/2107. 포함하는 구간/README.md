# [Gold V] 포함하는 구간 - 2107 

[문제 링크](https://www.acmicpc.net/problem/2107) 

### 성능 요약

메모리: 2268 KB, 시간: 8 ms

### 분류

브루트포스 알고리즘, 정렬

### 제출 일자

2025년 4월 19일 18:22:51

### 문제 설명

<p>The farm has suffered an extraordinary amount of rain lately. Now wanting to eat free from rain, the ingenious cows have set up N (1 <= N <= 25,000) rectangular umbrellas to shield them from the rain while they are grazing.</p>

<p>The cows' field is a single strip of grass, and each umbrella completely covers some interval of grass. However, they have set up the umbrellas in a most haphazard way, and some of the umbrellas cover all or part of an area covered by one or more other umbrellas. Your task is to find the greatest number of umbrellas whose areas are completely covered by a single umbrella.</p>

### 입력 

 <ul>
	<li>Line 1: The single integer N</li>
	<li>Lines 2..N+1: Two space-separated integers, A and B (1 <= A < B <= 2,000,000,000) that are the endpoints of the interval of grass covered by an umbrella. No endpoint is shared by any two umbrellas.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the maximum number of umbrellas whose coverage is entirely within the area covered by another single umbrella.</li>
</ul>

