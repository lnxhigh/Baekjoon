# [Gold III] Rounds - 21195 

[문제 링크](https://www.acmicpc.net/problem/21195) 

### 성능 요약

메모리: 4364 KB, 시간: 12 ms

### 분류

자료 구조, 그리디 알고리즘, 수학

### 제출 일자

2025년 1월 5일 22:58:11

### 문제 설명

<p>The popular PerfectShape online group gathers fans of workouts and healthy lifestyle all over the world. Every group member has managed to gain a certain amount of credits for the trendy M0V3 online sports platform, giving them access to various workout and relaxation resources.</p>

<p>The amount of credits owned may however largely differ from one person to the other. Since PerfectShape members value sharing and solidarity, they decide to redispatch credits by playing the following game:</p>

<p>The N group members are numbered from 1 to N and the game comprises k rounds, for some integer k such that 1 ≤ k ≤ N. During the i-th round of the game, all members except member i give S credits to member i. The game may end after any round, and its outcome will be the minimum amount of credits held by a member of the group after that round.</p>

<p>Your task is to figure out the maximum possible game outcome, across all possible game endings.</p>

### 입력 

 <p>The first line of the input contains two integers N and S. Each of the N following lines contains a single integer, the (i + 1)-th line containing the amount of credits C<sub>i</sub> initially owned by member i.</p>

### 출력 

 <p>The output should contain a single integer value C corresponding to the maximum possible game outcome.</p>

