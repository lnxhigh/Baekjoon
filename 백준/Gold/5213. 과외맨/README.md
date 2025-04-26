# [Gold II] 과외맨 - 5213 

[문제 링크](https://www.acmicpc.net/problem/5213) 

### 성능 요약

메모리: 14112 KB, 시간: 56 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색, 구현

### 제출 일자

2025년 4월 26일 21:03:15

### 문제 설명

<p>Mister No (real name Jerry Drake) is a comic book character who frequently gets himself into a lot of trouble, which he is usually able to get out of. However, this time it's not so easy. He was searching for ancient Mayan treasures and, in the process, stumbled upon a lost temple. Inside the temple there is a large hall, and inside the hall stands a stone Totem with inscriptions that are the key to understanding the purpose of life (42). However, getting to the Totem is a great challenge.</p>

<p>The Totem is situated on the opposite side of the hall form the entrance. The floor of the hall is covered with stone tiles that bear a striking resemblance to domino tiles. Each tile is divided into two halves (squares), and each half has a number from one to six, inclusive, chiseled into it. Tiles are arranged in N rows, with N tiles in each odd-numbered row and N - 1 tiles in each even-numbered row. The image below corresponds to the first test example (N = 5):</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/04f37a7b-2308-4f1c-837a-ad5197c14870/-/preview/" style="width: 304px; height: 122px;"></p>

<p>It is only possible to step from one tile to an adjacent one if the two tiles have matching numbers on halves that share an edge. Help Mister No find the shortest path to the Totem by determining the sequence of tiles (outputting the sequence of tiles' labels, described below) that need to be stepped on, in order, from the first to the last tile on the path. If there is no possible path to the Totem, find the shortest path to the tile with the largest label (so that Mister No can make a heroic jump). The stone tiles are labelled in row-major order: in the first row, the first tile has the label 1, and the last one N; in the second row, the first tile is N + 1, and the last one 2*N - 1, and so on. The entrance leads to the tile with label 1, and the totem is on the last tile in the last row. Mister No always starts from the entrance.</p>

### 입력 

 <p>The first line of input contains the positive integer N (1 ≤ N ≤ 500), the number of stone tile rows. Each of the following N * N - N / 2 lines (where “/” stands for integer division) contains two positive integers A<sub>i</sub> and B<sub>i</sub> (1 ≤ A<sub>i</sub>, B<sub>i</sub> ≤ 6, 1 ≤ i ≤ N * N - N / 2), the values chiseled into the left and right halves, respectively, of tile i.</p>

### 출력 

 <p>The first line of output must contain the length (in tiles) of the required shortest path.</p>

<p>The second line of output must contain a sequence of space-separated positive integers, the labels of tiles on the shortest path. As there can exist more than one shortest path, output any one of them.</p>

