# [Gold II] 빵집 - 3109 

[문제 링크](https://www.acmicpc.net/problem/3109) 

### 성능 요약

메모리: 12384 KB, 시간: 76 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 그리디 알고리즘

### 제출 일자

2025년 4월 22일 14:25:26

### 문제 설명

<p>Mirko owns a bakery on the edge of the city. Because of the financial crisis, Mirko's monthly gas bill for the ovens has become too large so he decided to steal gas from a large pipeline near his bakery. </p>

<p>The land surrounding the bakery can be modelled by an R×C grid so that the pipeline is in the first column and Mirko's bakery in the last column. </p>

<p>Mirko will connect pipes to the gas pipeline and his bakery. Some parcels of land are inaccessible and Mirko cannot put pipes through them. </p>

<p>Every path from the pipeline to the bakery starts in a cell in the first column in the grid, ends in the last column, and each cell on the path is connected to the cell diagonally up-right, right or diagonally down-right. </p>

<p>In order to pull as much gas from the pipeline as possible, Mirko wants to get as many paths to his bakery as possible. The paths may not cross nor touch. In other words, at most one path may pass through any cell. </p>

<p>Write a program that calculates the largest number of paths Mirko can pull. </p>

### 입력 

 <p>The first line contains two integers R and C (1 ≤ R ≤ 10000, 5 ≤ C ≤ 500), the dimensions of the grid.Each of the following R lines contains a string of C characters, each being a period '.' or the letter 'x'. The letter 'x' represents an inaccessible parcel of land. The first and last cells in each row will be clear.</p>

### 출력 

 <p>Output the largest number of paths Mirko can pull from the pipeline to the bakery. </p>

<p> </p>

