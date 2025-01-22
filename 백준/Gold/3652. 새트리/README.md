# [Gold V] 새트리 - 3652 

[문제 링크](https://www.acmicpc.net/problem/3652) 

### 성능 요약

메모리: 2660 KB, 시간: 0 ms

### 분류

수학, 재귀

### 제출 일자

2025년 1월 22일 16:01:31

### 문제 설명

<p>The Bird tree is an infinite binary tree, whose ﬁrst 5 levels look as follows:</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/bt.png" style="height:240px; width:564px"></p>

<p>It can be defined as follows:</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/bd.png" style="height:85px; width:247px"></p>

<p>This is a co-recursive definition in which both occurrences of bird refer to the full (infinite) tree.</p>

<p>The expression bird + 1 means that 1 is added to every fraction in the tree, and 1/bird means that every fraction in the tree is inverted (so a/b becomes b/a).</p>

<p>Surprisingly, the tree contains every positive rational number exactly once, so every reduced fraction is at a unique place in the tree. Hence, we can also describe a rational number by giving directions (L for left subtree, R for right subtree) in the Bird tree. For example, 2/5 is represented by LRR. Given a reduced fraction, return a string consisting of L’s and R’s: the directions to locate this fraction from the top of the tree.</p>

### 입력 

 <p>On the first line a positive integer: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with two integers a and b (1 ≤ a, b ≤ 10<sup>9</sup>), separated by a ’/’. These represent the numerator and denominator of a reduced fraction. The integers a and b are not both equal to 1, and they satisfy gcd(a, b) = 1.</li>
</ul>

<p>For every test case the length of the string with directions will be at most 10 000.</p>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with the string representation of the location of this fraction in the Bird tree.</li>
</ul>

