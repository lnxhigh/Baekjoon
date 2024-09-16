# [Gold II] 하노이의 네 탑 - 9942 

[문제 링크](https://www.acmicpc.net/problem/9942) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 수학

### 제출 일자

2024년 9월 16일 22:53:26

### 문제 설명

<p>Refer to problem three for a description of the classic three-tower version of the Towers of Hanoi problem.</p>

<p>For this problem, we extend the Towers of Hanoi to have four towers and ask the question “What are the fewest number of moves to solve the Towers of Hanoi problem for a given n if we allow four towers instead of the usual three?” We keep the rules of trying to move n disks from one specified post to another and do not allow a bigger disk to be put on top of a smaller one. What is new for this problem is to have two spare posts instead of just one.</p>

<p>For example, to move 3 disks from post A to post D, we can move disk 1 from A to B, disk 2 from A to C, disk 3 from A to D, disk 2 from C to D, and disk 1 from B to D, making a total of 5 moves.</p>

### 입력 

 <p>Input will be positive integers (n), one per line, none being larger than 1,000. For each value of n, compute the fewest number of moves for the four-tower problem. Stop processing at the end of the file. (There is no end-of-data flag.)</p>

### 출력 

 <p>Output the fewest number of moves. Follow this format exactly: “Case”, one space, the case number, a colon and one space, and the answer for that case. You may assume the answer will fit in a 64-bit integer type. Do not print any trailing spaces.</p>

