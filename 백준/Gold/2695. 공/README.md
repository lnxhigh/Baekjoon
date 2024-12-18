# [Gold II] 공 - 2695 

[문제 링크](https://www.acmicpc.net/problem/2695) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 12월 19일 02:31:06

### 문제 설명

<p>The classic Two Glass Balls brain-teaser is often posed as: </p>

<blockquote>
<p>"Given two identical glass spheres, you would like to determine the lowest floor in a 100-story building from which they will break when dropped. Assume the spheres are undamaged when dropped below this point. What is the strategy that will minimize the worst-case scenario for number of drops?" </p>
</blockquote>

<p>Suppose that we had only one ball. We'd have to drop from each floor from 1 to 100 in sequence, requiring 100 drops in the worst case. </p>

<p>Now consider the case where we have two balls. Suppose we drop the first ball from floor n. If it breaks we're in the case where we have one ball remaining and we need to drop from floors 1 to n-1 in sequence, yielding n drops in the worst case (the first ball is dropped once, the second at most n-1 times). However, if it does not break when dropped from floor n, we have reduced the problem to dropping from floors n+1 to 100. In either case we must keep in mind that we've already used one drop. So the minimum number of drops, in the worst case, is the minimum over all n. </p>

<p>You will write a program to determine the minimum number of drops required, in the worst case, given B balls and an M-story building. </p>

### 입력 

 <p>The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set consists of a single line containing two (2) decimal integer values: the number of balls B, (1 ≤ B ≤ 50), followed by a space and the number of floors in the building M, (1 ≤ M ≤ 1000). </p>

### 출력 

 <p>For each data set, generate one line of output with the following value: The minimum number of drops needed for the corresponding values of B and M. </p>

