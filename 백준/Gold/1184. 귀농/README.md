# [Gold I] 귀농 - 1184 

[문제 링크](https://www.acmicpc.net/problem/1184) 

### 성능 요약

메모리: 41104 KB, 시간: 12 ms

### 분류

브루트포스 알고리즘, 자료 구조, 해시를 사용한 집합과 맵, 누적 합

### 제출 일자

2025년 4월 25일 20:46:08

### 문제 설명

<p>After Mirko's failed stint as a coach and a passing obsession with Croatian meat delicacies, his weight problems have motivated him to work hard as a farmer. He has moved to a village where his friend Slavko lives. Farmers in the village share a large common plot of land in the shape of a N×N square, divided into N² unit squares. A unit square at coordinates (i, j) brings in the income of A<sub>ij</sub>, which can be negative (for example, if the square has to be maintained but is not cultivated). The farmers always divide the common land into smaller rectangular fields with edges parallel to the common land edges. </p>

<p>Slavko is skeptical of Mirko since his failure as a coach, so he insists that both of them are assigned land with the same total income, but also thet the two plots share exactly one common corner so that the two friends can keep an eye on each other (Slavko knows that Mirko is prone to mischief). Thecommon corner must be the only point where the two plots meet, in order to prevent border-related arguments. </p>

<p>You are given a description of the common land plot. Find the total number of plot pairs that satisfy Slavko's criteria. </p>

### 입력 

 <p>The first line of input contains the positive integer N (1 ≤ N ≤ 50), the dimensions of the common land plot. </p>

<p>Each of the following N lines contains N space-separated numbers A<sub>ij</sub> (-1000 < A<sub>ij</sub> < 1000), the income provided by the respective cell.</p>

### 출력 

 <p>The first and only line of output must contain the totl number of plot pairs satisfying the given condition.</p>

