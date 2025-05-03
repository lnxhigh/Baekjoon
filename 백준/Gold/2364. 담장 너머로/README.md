# [Gold I] 담장 너머로 - 2364 

[문제 링크](https://www.acmicpc.net/problem/2364) 

### 성능 요약

메모리: 2580 KB, 시간: 16 ms

### 분류

너비 우선 탐색, 플로이드–워셜, 그래프 이론, 그래프 탐색, 최단 경로

### 제출 일자

2025년 5월 4일 01:23:05

### 문제 설명

<p>In a country, great walls have been built in such a way that every great wall connects exactly two towns. The great walls do not cross each other. Thus, the country is divided into such regions that to move from one region to another, it is necessary to go through a town or cross a great wall. For any two towns A and B, there is at most one great wall with one end in A and the other in B, and further, it is possible to go from A to B by always walking in a town or along a great wall. The input format implies additional restrictions. </p>

<p>There is a club whose members live in the towns. In each town, there is only one member or there are no members at all. The members want to meet in one of the regions (outside of any town). The members travel riding their bicycles. They do not want to enter any towns, because of the traffic, and they want to cross as few great walls as possible, as it is a lot of trouble. To go to the meeting region, each member needs to cross a number (possibly 0) of great walls. They want to find such an optimal region that the sum of these numbers (crossing-sum, for short) is minimized.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/wall.png" style="height:300px; width:761px"></p>

<p>The towns are labeled with integers from 1 to N, where N is the number of towns. In Figure 1, the labeled nodes represent the towns and the lines connecting the nodes represent the great walls. Suppose that there are three members, who live in towns 3, 6, and 9. Then, an optimal meeting region and respective routes for members are shown in Figure 2. The crossing-sum is 2: the member from town 9 has to cross the great wall between towns 2 and 4, and the member from town 6 has to cross the great wall between towns 4 and 7.</p>

<p>You are to write a program which, given the towns, the regions, and the club member home towns, computes an optimal region and the minimal crossing-sum.</p>

### 입력 

 <p>The first line contains one integer: the number of regions M, 2≤M≤200. The second line contains one integer: the number of towns N, 3≤N≤250. The third line contains one integer: the number of club members L, 1≤L≤30, L≤N. The fourth line contains L distinct integers in increasing order: the labels of the towns where the members live.</p>

<p>After that the file contains 2M lines so that there is a pair of lines for each region: the first two of the 2M lines describe the first region, the following two the second and so on. Of the pair, the first line shows the number of towns I on the border of that region. The second line of the pair contains I integers: the labels of these I towns in some order in which they can be passed when making a trip clockwise along the border of the region, with the following exception. The last region is the “outside region” surrounding all towns and other regions, and for it the order of the labels corresponds to a trip in counterclockwise direction. The order of the regions gives an integer labeling to the regions: the first region has label 1, the second has label 2, and so on. Note that the input includes all regions formed by the towns and great walls, including the “outside region”.</p>

### 출력 

 <p>The first line contains one integer: the minimal crossing-sum. The second line contains one integer: the label of an optimal region. There may be several different solutions for the region and your program needs to output only one of them.</p>

