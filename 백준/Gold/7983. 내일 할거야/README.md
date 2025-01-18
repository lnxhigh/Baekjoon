# [Gold V] 내일 할거야 - 7983 

[문제 링크](https://www.acmicpc.net/problem/7983) 

### 성능 요약

메모리: 10212 KB, 시간: 272 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2025년 1월 18일 14:27:29

### 문제 설명

<p>Byteasar tends to postpone all the tasks he needs to perform. However, if he promises to do something, you can certainly count on him.</p>

<p>Byteasar woke up early today and prepared a list of n tasks that he needs to perform in near future. The i-th task will take him d<sub>i</sub> consecutive days to perform and has to be completed within the next t<sub>i</sub> days, starting from today. Byteasar would like to know how much time he can spend doing nothing until he really has to start performing some tasks. Could you write a program that will help him find that out? Byteasar could also write such a program himself, however this could disturb his procrastination period.</p>

### 입력 

 <p>The first line of input contains one integer n (1 ≤ n ≤ 1 000 000): the number of tasks that Byteasar has to perform. The following n lines hold a description of the tasks. The i-th of those lines contains two integers d<sub>i</sub> and t<sub>i</sub> (1 ≤ d<sub>i</sub>, t<sub>i</sub> ≤ 10<sup>9</sup>). We assume that Byteasar is able to perform all the tasks on time.</p>

### 출력 

 <p>Your program should output one integer k: the maximum number of days during which Byteasar can avoid working. In other words, on the day number k + 1 at latest Byteasar must start performing one of the tasks in order to be able to eventually complete all the tasks on time.</p>

