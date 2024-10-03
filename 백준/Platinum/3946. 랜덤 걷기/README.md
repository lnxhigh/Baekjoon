# [Platinum III] 랜덤 걷기 - 3946 

[문제 링크](https://www.acmicpc.net/problem/3946) 

### 성능 요약

메모리: 10008 KB, 시간: 12 ms

### 분류

다이나믹 프로그래밍, 수학, 확률론

### 제출 일자

2024년 10월 4일 00:16:32

### 문제 설명

<p>Consider the classic random walk: at each step, you have a 1/2 chance of taking a step to the left and a 1/2 chance of taking a step to the right. Your expected position after a period of time is zero; that is, the average over many such random walks is that you end up where you started. A more interesting question is what is the expected rightmost position you will attain during the walk</p>

### 입력 

 <p>The first line of input contains a single integer P, (1 ≤ P ≤ 15), which is the number of data sets that follow Each data set should be processed identically and independently.</p>

<p>Each data set consists of a single line of input consisting of three space-separated values. The first value is an integer n, which is the number of steps to take (1 ≤ n ≤ 1000). The final two are double precision floating-point values L and R which are the probabilities of taking a step left or right respectively at each step (0 ≤ L ≤ 1, 0 ≤ R ≤ 1, 0 ≤ L + R ≤ 1).</p>

<p>Note: the probably of not taking a step would be 1 - L - R.</p>

### 출력 

 <p>For each data set there is a single line of output. It contains the data set number, followed by a single space which is then followed by the expected (average) rightmost position you will obtain during the walk, as a double precision floating point value to four decimal places.</p>

