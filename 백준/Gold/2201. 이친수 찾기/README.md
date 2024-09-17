# [Gold II] 이친수 찾기 - 2201 

[문제 링크](https://www.acmicpc.net/problem/2201) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 수학

### 제출 일자

2024년 9월 18일 01:19:22

### 문제 설명

<p>“Pinary” number is a positive number using only two digits “0” and “1” with usual rule that it must not begin with a 0, and the additional rule that two successive digits must not be both “1”. This means that the factor “11” is forbidden in the string. So the allowed Pinary writings are 1, 10, 100, 101, 1000, 1001, …, 100010101010100010001. For example, “100101000” is a Pinary number, but neither “0010101” nor “10110001” are Pinary numbers.</p>

<p>Each Pinary number represents a positive integer in the order they appear (using length order, lexicographic order), that is, 1 is mapped to 1, 10 is mapped to 2. And 100, 101 and 1000 are mapped to 3, 4 and 5, respectively. You are to write a program to generate Pinary number representations for integers given.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing a postive integer 1 ≤ K ≤ 1,000,000,000,000,000,000.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. For each test case, print the Pinary number representation for input integer.</p>

