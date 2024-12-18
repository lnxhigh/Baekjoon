# [Gold II] 유클리드 게임 - 4342 

[문제 링크](https://www.acmicpc.net/problem/4342) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

유클리드 호제법, 게임 이론, 수학, 정수론

### 제출 일자

2024년 12월 18일 16:30:59

### 문제 설명

<p>Two players, Stan and Ollie, play, starting with two natural numbers. Stan, the first player, subtracts any positive multiple of the lesser of the two numbers from the greater of the two numbers, provided that the resulting number must be nonnegative. Then Ollie, the second player, does the same with the two resulting numbers, then Stan, etc., alternately, until one player is able to subtract a multiple of the lesser number from the greater to reach 0, and thereby wins. For example, the players may start with (25,7):</p>

<pre>25 7 
11 7 
 4 7 
 4 3 
 1 3 
 1 0</pre>

<p>an Stan wins.</p>

### 입력 

 <p>The input consists of a number of lines. Each line contains two positive integers giving the starting two numbers of the game. Stan always starts.</p>

### 출력 

 <p>For each line of input, output one line saying either Stan wins or Ollie wins assuming that both of them play perfectly. The last line of input contains two zeroes and should not be processed.</p>

