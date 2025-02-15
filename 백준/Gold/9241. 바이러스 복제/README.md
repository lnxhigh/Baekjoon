# [Gold V] 바이러스 복제 - 9241 

[문제 링크](https://www.acmicpc.net/problem/9241) 

### 성능 요약

메모리: 2540 KB, 시간: 0 ms

### 분류

그리디 알고리즘, 구현, 문자열

### 제출 일자

2025년 2월 15일 17:03:35

### 문제 설명

<p>Some viruses replicate by replacing a piece of DNA in a living cell with a piece of DNA that the virus carries with it. This makes the cell start to produce viruses identical to the original one that infected the cell. A group of biologists is interested in knowing how much DNA a certain virus inserts into the host genome. To ﬁnd this out they have sequenced the full genome of a healthy cell as well as that of an identical cell infected by a virus.</p>

<p>The genome turned out to be pretty big, so now they need your help in the data processing step. Given the DNA sequence before and after the virus infection, determine the length of the smallest single, consecutive piece of DNA that can have been inserted into the ﬁrst sequence to turn it into the second one. A single, consecutive piece of DNA might also have been removed from the same position in the sequence as DNA was inserted. Small changes in the DNA can have large effects, so the virus might insert only a few letters, or even nothing at all.</p>

### 입력 

 <p>The input consists of two lines containing the DNA sequence before and after virus infection respectively. A DNA sequence is given as a string containing between 1 and 10<sup>5</sup> upper-case letters from the alphabet {A, G, C, T}.</p>

### 출력 

 <p>Output one integer, the minimum length of DNA inserted by the virus.</p>

<p> </p>

