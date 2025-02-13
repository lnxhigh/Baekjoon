# [Gold V] 피자 굽기 - 1756 

[문제 링크](https://www.acmicpc.net/problem/1756) 

### 성능 요약

메모리: 3192 KB, 시간: 52 ms

### 분류

구현

### 제출 일자

2025년 2월 13일 14:36:16

### 문제 설명

<p>For his birthday present little Johnny has received from his parents a new plaything which consists of a tube and a set of disks. The aforementioned tube is of unusual shape. Namely, it is made of a certain number of cylinders (of equal height) with apertures of different diameters carved coaxially through them. The tube is closed at the bottom, open at the top. An exemplary tube consisting of cylinders whose apertures have the diameters: 5cm, 6cm, 4cm, 3cm, 6cm, 2cm and 3cm is presented in the image below.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/kra1.png" style="height:206px; width:350px"></p>

<p>The disks in Johnny's plaything are cylinders of different diameters and height equal to those forming the tube.</p>

<p>Johnny has invented a following game: having a certain set of disks at his disposal, he seeks to find what depth the last of them would stop at, assuming that they are being thrown into the centre of the tube. If, for instance, we were to throw disks of consecutive diameters: 3cm, 2cm and 5cm, we would obtain the following situation:</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/kra2.png" style="height:206px; width:350px"></p>

<p>As you can see, upon being thrown in, every disk falls until it gets stuck (which means that it lies atop a cylinder, aperture of which has a diameter smaller than the diameter of the disk) or it is stopped by an obstacle: the bottom of the tube or another disk, which has already stopped.</p>

<p>The game being difficult, Johnny constantly asks his parents for help. As Johnny's parents do not like such intellectual games, they have asked you - an acquaintance of theirs and a programmer - to write a programme which will provide them with answers to Johnny's questions.</p>

<p>Write a programme which:</p>

<ul>
	<li>reads the description of the tube and the disks which Johnny will throw into it from the standard input,</li>
	<li>computes the depth which the last disk thrown by Johnny stops at,</li>
	<li>writes the outcome to the standard output.</li>
</ul>

### 입력 

 <p>The first line of the standard input contains two integers n and m (1 ≤ n,m ≤ 300 000) separated by a single space and denoting the height of Johnny's tube (the number of cylinders it comprises) and the number of disks Johnny intends to throw into it, respectively. The second line of the standard input contains n integers r<sub>1</sub>,r<sub>2</sub>,...,r<sub>n</sub> (1 ≤ r<sub>i</sub> ≤ 1 000 000 000 for 1 ≤ i ≤ n) separated by single spaces and denoting the diameters of the apertures carved through the consecutive cylinders (in top-down order), which the tube consists of. The third line contains m integers k<sub>1</sub>,k<sub>2</sub>,...,k<sub>m</sub> (1 ≤ k<sub>j</sub> ≤ 1 000 000 000 for 1 ≤ j ≤ m) separated by single spaces and denoting the diameters of consecutive disks which Johnny intends to throw into the tube.</p>

<p> </p>

### 출력 

 <p>The first and only line of the standard output should contain a single integer denoting the depth which the last disk stops at. Should the disk not fall into the tube at all, the answer should be 0.</p>

<p> </p>

