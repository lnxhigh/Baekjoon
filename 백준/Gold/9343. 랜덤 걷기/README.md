# [Gold I] 랜덤 걷기 - 9343 

[문제 링크](https://www.acmicpc.net/problem/9343) 

### 성능 요약

메모리: 18404 KB, 시간: 16 ms

### 분류

조합론, 페르마의 소정리, 수학, 모듈로 곱셈 역원, 정수론

### 제출 일자

2025년 1월 30일 04:52:46

### 문제 설명

<p>“Thorfun Company Limited” aka “thorfun.com”, a social network for blogger, writer and reader, founded by four new graduated. One of them is passion in computational problems. One day he found something very interesting because, it is a solution of various problems and “Random Walks” is one of them. Given a one dimensional line and you stand at the original point (position 0). At each step you can walk either left or right for unit length.</p>

<p>First, let us have a look at a basic version of the problem. You can walk whatever you want for 2N steps but, you must end at the original point. How many different paths that you can walk? The solution is very simple. You start and end at the same point, it means that you must take the same number of left and right step. Choosing N for the right and the other N for the left from 2N steps is equal to <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mrow><mjx-mo class="mjx-s3"><mjx-c class="mjx-c28 TEX-S3"></mjx-c></mjx-mo><mjx-mtable style="min-width: 1.388em;"><mjx-table><mjx-itable><mjx-mtr><mjx-mtd style="padding-bottom: 0.2em;"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-tstrut></mjx-tstrut></mjx-mtd></mjx-mtr><mjx-mtr><mjx-mtd style="padding-top: 0.2em;"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-tstrut></mjx-tstrut></mjx-mtd></mjx-mtr></mjx-itable></mjx-table></mjx-mtable><mjx-mo class="mjx-s3"><mjx-c class="mjx-c29 TEX-S3"></mjx-c></mjx-mo></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">(</mo><mtable columnspacing="1em" rowspacing="4pt"><mtr><mtd><mn>2</mn><mi>N</mi></mtd></mtr><mtr><mtd><mi>N</mi></mtd></mtr></mtable><mo data-mjx-texclass="CLOSE">)</mo></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\begin{pmatrix}  2N  \\  N  \end{pmatrix}\)</span></mjx-container>.</p>

<p>“Random Walks” problem is similar to the basic problem. However, during the walks you must not walk into negative integers. For example, if N = 1 you can walk on the path 0 → 1 → 0 but you can’t walk on path 0 → -1 → 0. You task is to write a program to compute the number of path that follow the above rules. In addition, the result may be very large. So, print the result modulo by 1 000 000 007 (Prime number). </p>

### 입력 

 <p>First line of input is a number of test cases T ≤ 1 000. </p>

<p>Each test case is a line contain an integers N (1 ≤ N ≤ 1 000 000) </p>

### 출력 

 <p>For each test case, display an integer indicating the number of paths that you can walk modulo by 1 000 000 007 </p>

