# [Silver IV] 에라토스테네스의 체 - 2960 

[문제 링크](https://www.acmicpc.net/problem/2960) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2024년 10월 6일 22:48:28

### 문제 설명

<p>The sieve of Eratosthenes is a famous algorithm to find all prime numbers up to N. The algorithm is: </p>

<ol>
	<li>Write down all integers between 2 and N, inclusive.</li>
	<li>Find the smallest number not already crossed out and call it P; P is prime. </li>
	<li>Cross out P and all its multiples that aren't already crossed out. </li>
	<li>If not all numbers have been crossed out, go to step 2. </li>
</ol>

<p>Write a program that, given N and K, find the K-th integer to be crossed out. </p>

### 입력 

 <p>The integers N and K (1 ≤ K < N, max(1, K) < N ≤ 1000).</p>

<p> </p>

### 출력 

 <p>Output the K-th number to be crossed out.</p>

