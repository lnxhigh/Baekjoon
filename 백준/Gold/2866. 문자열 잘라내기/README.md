# [Gold V] 문자열 잘라내기 - 2866 

[문제 링크](https://www.acmicpc.net/problem/2866) 

### 성능 요약

메모리: 5340 KB, 시간: 344 ms

### 분류

자료 구조, 문자열, 이분 탐색, 집합과 맵, 해시를 사용한 집합과 맵

### 제출 일자

2025년 6월 21일 02:45:44

### 문제 설명

<p>In this economy, we all know how hard it is to get a job. Mirko, a recent college graduate, however, got lucky - he is now employed as a runeologist by the Language Institute of Croatia. His friend Slavko believes runeology isn’t a science and is hence angry at Mirko for believing the opposite. One foggy Christmas day, Mirko’s laptop broke. Since he isn’t great with computers, he gave it to Slavko to repair it. Slavko, felling a little naughty, decided to mess up a particular file Mirko was working on. </p>

<p>This file contains a matrix of R rows and C columns. Each element of the matrix is a single letter. No two columns of the matrix are equal. To have some fun with pseudo-scientist Mirko, Slavko decided he will delete as much rows as possible from the top of the table, without breaking the no-equal-column rule.</p>

### 입력 

 <p>The first line of input contains two integers R and C (2 ≤ R, C ≤ 1000), the number of rows and the number of columns, respectively. </p>

<p>In each of the next R lines there are C small letters of the English alphabet. These R x C letters represent Mirko’s table (which does not have two same columns). </p>

### 출력 

 <p>Output a single integer, the maximum number of rows which can be deleted from the top of the table so that no two columns are equal. </p>

