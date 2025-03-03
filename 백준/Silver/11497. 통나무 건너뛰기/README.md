# [Silver I] 통나무 건너뛰기 - 11497 

[문제 링크](https://www.acmicpc.net/problem/11497) 

### 성능 요약

메모리: 2156 KB, 시간: 36 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2025년 3월 3일 19:52:40

### 문제 설명

<p>We want to arrange N logs in a circle for a playing ground shown in Figure 1. Kids are jumping one log to the next log circularly. We are concerned to arrange the logs to help kids by minimizing the height difference between two adjacent logs.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11497/1.png" style="height:268px; width:274px"></p>

<p style="text-align: center;">Figure 1. N logs are arranged in a circle.</p>

<p>The difficulty of log jumping depends on the maximum difference of heights among all pairs of two adjacent logs. Assume that we are given 5 logs with the heights {2, 4, 5, 7, 9}. Note that the last log with height 5 is immediate adjacent to the first log with height 2 in the arrangement [2, 9, 7, 4, 5]. The maximum height difference of the arrangement [2, 9, 7, 4, 5] is |2 – 9| = 7. We can make a better arrangement as [2, 5, 9, 7, 4] where the maximum height difference is |5 – 9| = 4. This arrangement [2, 5, 9, 7, 4] is optimal since there is no arrangement with the maximum height difference less than 4.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing an integer, N (5 ≤ N ≤ 10,000), where N is the number of logs. In the next line, the heights of N logs, L<sub>i</sub> are given as a sequence of integers. (1 ≤ L<sub>i</sub> ≤ 100,000)</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain an integer representing the maximum height difference of an optimal log arrangement. The following shows sample input and output for three test cases.</p>

