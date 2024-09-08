# [Gold V] 흙길 보수하기 - 1911 

[문제 링크](https://www.acmicpc.net/problem/1911) 

### 성능 요약

메모리: 2100 KB, 시간: 0 ms

### 분류

그리디 알고리즘, 정렬, 스위핑

### 제출 일자

2024년 9월 8일 18:31:15

### 문제 설명

<p>Farmer John has a problem: the dirt road from his farm to town has suffered in the recent rainstorms and now contains (1 ≤ N ≤ 10,000) mud pools.</p>

<p>Farmer John has a collection of wooden planks of length (1 ≤ L ≤ 1,000,000) that he can use to bridge these mud pools. He can overlap planks and the ends do not need to be anchored on the ground. However, he must cover each pool completely.</p>

<p>Given the mud pools, help FJ figure out the minimum number of planks he needs in order to completely cover all the mud pools.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and L</li>
	<li>Lines 2..N+1: Line i+1 contains two space-separated integers: s<sub>i</sub> and e<sub>i</sub> (0 ≤ s<sub>i</sub> < e<sub>i</sub> ≤ 1,000,000,000) that specify the start and end points of a mud pool along the road. The mud pools will not overlap. These numbers specify points, so a mud pool from 35 to 39 can be covered by a single board of length 4. Mud pools at (3,6) and (6,9) are not considered to overlap.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The miminum number of planks FJ needs to use.</li>
</ul>

