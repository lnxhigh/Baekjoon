# [Gold II] 거짓말 - 2402 

[문제 링크](https://www.acmicpc.net/problem/2402) 

### 성능 요약

메모리: 2852 KB, 시간: 144 ms

### 분류

자료 구조, 분리 집합, 그래프 이론, 누적 합

### 제출 일자

2025년 6월 9일 18:34:24

### 문제 설명

<p>어느 두 사람이 질문자와 답변자가 되어 게임을 하고 있다. 게임을 위해 답변자에게 길이 N(1 ≤ N ≤ 1,000,000,000)의 이진 수열(0과 1로만 이루어진 수열)이 주어진다.</p>

<p>질문자는 M(1 ≤ M ≤ 5,000)번에 걸쳐 답변자에게 수열의 i번째 항부터 j번째 항까지 1이 짝수 번 나타나는지 홀수 번 나타나는지를 물어본다. 이는 i번째 항과 j번째 항을 포함시켜서 생각하는 것으로 한다. 1이 짝수 번 나타나는 경우에는 0이라고, 홀수 번 나타나는 경우에는 1이라고 답변자가 답한다.</p>

<p>이 게임의 목적은, 이런 식으로 질문과 답변을 진행하다가, 답변자가 몇 번째 질문에서 거짓말을 하였는지를 알아내는 것이다. 질문자와 답변자의 질문과 답이 주어졌을 때, 답변자가 몇 번째 질문에 대해 거짓말을 했는지를 알아내는 프로그램을 작성하시오.</p>

<p>답변자가 어느 질문에 대해 거짓말을 했다는 것은, 그 전 질문까지의 답변과 그 질문의 답변을 동시에 만족하는 이진 수열이 존재하지 않음을 의미한다.</p>

### 입력 

 <p>첫째 줄에는 두 정수 N과 M이 주어진다. 다음 M개의 줄에는 질문과 답을 나타내는 3개의 정수가 주어진다. 첫 번째 정수는 i이며, 두 번째 정수는 j이다. 세 번째 정수는 그 질문에 대한 답변자의 답을 나타낸다.</p>

### 출력 

 <p>첫째 줄에 몇 번째 질문에 대해 답변자가 거짓말을 했는지를 출력한다. 만약 답변자가 모든 질문에 대해 거짓말을 하지 않았다면 M+1을 출력한다.</p>

