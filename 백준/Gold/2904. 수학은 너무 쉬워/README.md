# [Gold III] 수학은 너무 쉬워 - 2904 

[문제 링크](https://www.acmicpc.net/problem/2904) 

### 성능 요약

메모리: 36716 KB, 시간: 24 ms

### 분류

수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2024년 9월 18일 20:49:44

### 문제 설명

<p>Mirkos great grandmother Katica is an avid mathematician. She likes to torment Mirko with math games. This time she wrote down a sequence of numbers on a piece of paper and told Mirko he may do the following:</p>

<ul>
	<li>Choose any two numbers in the sequence (let's call them A i B) and a prime number X such that A is divisible by X. After that, Mirko erases A and writes <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mfrac><mjx-frac><mjx-num><mjx-nstrut></mjx-nstrut><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi></mjx-num><mjx-dbox><mjx-dtable><mjx-line></mjx-line><mjx-row><mjx-den><mjx-dstrut></mjx-dstrut><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D44B TEX-I"></mjx-c></mjx-mi></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mfrac><mi>A</mi><mi>X</mi></mfrac></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\frac{A}{X}\)</span></mjx-container> in its place. In the end he erases B and writes <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D44B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi><mo>×</mo><mi>X</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(B \times X\)</span></mjx-container> in its place.</li>
</ul>

<p>Mirko may perform this operation as many times he wants. His goal is to obtain the maximum possible score, because he gets candy from his great grandmother if he does so. The score for one sequence is the greatest common divisor of all the numbers in the sequence.</p>

<p>He is not very good at this, and he likes his candy so he has asked you to help him. Write a program that will calculate the maximum possible score. Since you are such a nice guy, you should also print the smallest number of times Mirko must perform the operation to obtain the maximum possible score.</p>

### 입력 

 <p>The first line of input contains one integer N, (1 ≤ N ≤ 100), number of elements in the starting sequence.</p>

<p>The second line of input contains N positive integers smaller than or equal to 1 000 000, the sequence Katica gave to Mirko.</p>

### 출력 

 <p>The one and only line of output should contain two integers. The first integer is the maximal possible score Mirko can obtain. The second integer is the smallest number of operations Mirko needs to perform to obtain it.</p>

