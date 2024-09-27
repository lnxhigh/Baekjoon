# [Gold V] 가짜소수 - 4233 

[문제 링크](https://www.acmicpc.net/problem/4233) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

분할 정복을 이용한 거듭제곱, 페르마의 소정리, 수학, 정수론, 소수 판정

### 제출 일자

2024년 9월 27일 10:57:26

### 문제 설명

<p>Fermat's theorem states that for any prime number p and for any integer a > 1, a<sup>p</sup> == a (mod p). That is, if we raise a to the pth power and divide by p, the remainder is a. Some (but not very many) non-prime values of p, known as base-a pseudoprimes, have this property for some a. (And some, known as Carmichael Numbers, are base-a pseudoprimes for all a.)</p>

<p>Given 2 < p ≤ 1,000,000,000 and 1 < a < p, determine whether or not p is a base-a pseudoprime.</p>

### 입력 

 <p>Input contains several test cases followed by a line containing "0 0". Each test case consists of a line containing p and a.</p>

### 출력 

 <p>For each test case, output "yes" if p is a base-a pseudoprime; otherwise output "no".</p>

