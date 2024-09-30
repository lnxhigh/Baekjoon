# [Gold V] 알약 - 4811 

[문제 링크](https://www.acmicpc.net/problem/4811) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 수학

### 제출 일자

2024년 9월 30일 17:34:59

### 문제 설명

<p>Aunt Lizzie takes half a pill of a certain medicine every day. She starts with a bottle that contains N pills.</p>

<p>On the first day, she removes a random pill, breaks it in two halves, takes one half and puts the other half back into the bottle.</p>

<p>On subsequent days, she removes a random piece (which can be either a whole pill or half a pill) from the bottle. If it is half a pill, she takes it. If it is a whole pill, she takes one half and puts the other half back into the bottle.</p>

<p>In how many ways can she empty the bottle? We represent the sequence of pills removed from the bottle in the course of 2N days as a string, where the i-th character is W if a whole pill was chosen on the i-th day, and H if a half pill was chosen (0 <= i < 2N). How many different valid strings are there that empty the bottle?</p>

### 입력 

 <p>The input will contain data for at most 1000 problem instances. For each problem instance there will be one line of input: a positive integer N <= 30, the number of pills initially in the bottle. End of input will be indicated by 0.</p>

### 출력 

 <p>For each problem instance, the output will be a single number, displayed at the beginning of a new line. It will be the number of different ways the bottle can be emptied.</p>

