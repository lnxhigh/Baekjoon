# [Platinum IV] 개구리 공주 - 2983 

[문제 링크](https://www.acmicpc.net/problem/2983) 

### 성능 요약

메모리: 33816 KB, 시간: 284 ms

### 분류

자료 구조, 구현, 연결 리스트, 트리를 사용한 집합과 맵

### 제출 일자

2025년 3월 31일 10:07:37

### 문제 설명

<p>Luka parked his truck near the lake. The lake is inhabited by the frog Barica, who jumps across N plants floating on the lake's surface. Knowing a fair number of folk tales, Luka knows that if he kisses Barica, she will turn into a beautiful princess. However, he needs to catch her first! </p>

<p>Assuming an aerial view, the position of a plant on the lake's surface can be defined with a pair of coordinates. From plant (x, y) Barica can jump: </p>

<ul>
	<li>To plant (x+P, y+P), for any positive integer P. Call this direction A. </li>
	<li>To plant (x+P, y−P), for any positive integer P. Call this direction B. </li>
	<li>To plant (x−P, y+P), for any positive integer P. Call this direction C. </li>
	<li>To plant (x−P, y−P), for any positive integer P. Call this direction D. </li>
</ul>

<p>Barica selects one of the four directions and jumps onto the first plant in the chosen direction. If there is no plant in the selected direction, Barica stays where she is. After Barica jumps, the plant she jumped from sinks and disappears. </p>

<p>Knowing the locations of the plants and the sequence of directions Barica chooses, Luka wants to determine coordinates of the plant Barica will end up on. Luka will wait for her at that plant, ambush her and kiss her. </p>

<p>Write a program that solves Luka's problem and helps him turn Barica into a beautiful princess.</p>

### 입력 

 <p>The first line contains two integers N and K (1 ≤ N, K ≤ 100 000), the number of plants and the number of attempted jump. </p>

<p>The second line contains K letters each of which is 'A', 'B', 'C' or 'D'. These letters represent in order the directions in which Barica attempts to jump. </p>

<p>Each of the following N lines contains two integers X and Y (0 ≤ X ≤ 1 000 000 000, 0 ≤ Y ≤ 1000000000), the coordinates of one plant. Barica is initially located on the first plant. </p>

### 출력 

 <p>Output Barica's final coordinates. </p>

<p> </p>

