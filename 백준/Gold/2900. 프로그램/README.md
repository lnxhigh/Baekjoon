# [Gold III] 프로그램 - 2900 

[문제 링크](https://www.acmicpc.net/problem/2900) 

### 성능 요약

메모리: 25460 KB, 시간: 428 ms

### 분류

수학, 정수론, 누적 합

### 제출 일자

2024년 9월 7일 17:04:17

### 문제 설명

<p>Mirko is trying to debug a piece of his code. First he creates an array of N integers and fills it with zeros. Then he repeatedly calls the following procedure (he is such a good coder he coded it in both C++ and Pascal):</p>

<pre>void something(int jump) {
    int i = 0;
    while (i < N) {
        a[i] = a[i] + 1;
        i = i + jump;
    }
}</pre>

<p>As you can see, this procedure increases by one all elements in the array whose indices are divisible by jump.</p>

<p>Mirko calls the procedure exactly K times, using the sequence X<sub>1</sub> X<sub>2</sub> X<sub>3</sub>... X<sub>k</sub> as arguments.</p>

<p>After this, Mirko has a list of Q special parts of the array he needs to check to verify that his code is working as it should be. Each of this parts is defined by two numbers, L and R (L ≤ R) the left and right bound of the special part. To check the code, Mirko must compute the sum of all elements of seq between and including L and R. In other words seq[L] + seq[L+1] + seq[L+2] + ... + seq[R]. Since he needs to know the answer in advance in order to check it, he asked you to help him.</p>

### 입력 

 <p>The first line of input contains two integers, N (1 ≤ N ≤ 10<sup>6</sup>), size of the array, and K (1 ≤ K ≤ 10<sup>6</sup>), number of calls to something Mirko makes.</p>

<p>The second line contains K integers: X<sub>1</sub>X<sub>2</sub>X<sub>3</sub> ... X<sub>k</sub>, arguments passed to the procedure. (1 ≤ X<sub>i</sub> < N).</p>

<p>Next line contains one integer Q (1 ≤ Q ≤ 10<sup>6</sup>), number of special parts of the array Mirko needs to check.</p>

<p>Next Q lines contain two integers each L<sub>i</sub> and R<sub>i</sub>(0 ≤ L<sub>i</sub>≤ R<sub>i</sub> < N), bounds of each special part.</p>

### 출력 

 <p>The output should contain exactly Q lines. The i<sup>th</sup> line should contain the sum of elements seq[L<sub>i</sub>] + seq[L<sub>i</sub>+1] + seq[L<sub>i</sub>+2] + ... + seq[R<sub>i</sub>].</p>

