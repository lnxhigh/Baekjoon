# [Gold III] 이진 트리 - 13325 

[문제 링크](https://www.acmicpc.net/problem/13325) 

### 성능 요약

메모리: 51172 KB, 시간: 560 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 트리

### 제출 일자

2025년 1월 23일 11:42:29

### 문제 설명

<p>We are given a full binary tree of height k, where each edge has a positive weight. The full binary tree of height k has (2<sup>k+1</sup> − 1) nodes containing 2<sup>k</sup> leaves. The distance from the root to a leaf is the sum of weights of all the edges on the path from the root to the leaf. In this problem, we would like to increase the weights of certain edges so that all root-to-leaf paths have the same distance and keep the sum of all the edge weights as small as possible.</p>

<p>For example, consider a full binary tree of height 2 in Figure 1(a). A number alongside an edge indicates the weight of the edge. The solution of this instance is shown in Figure 1(b). That is, all root-to-leaf paths have the same distance 5, and the sum of all the edge weights is 15 which is the minimum possible value in this case. </p>

<p> </p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13325/1.png" style="height:183px; text-align:center; width:453px"></p>

<p style="text-align: center;">Figure 1. Illustration of increasing edge weights.</p>

<p>Given the weights of all edges in a full binary tree, you are to write a program that increases the weights of certain edges so that all root-to-leaf paths have the same distance and the total edge weights is as small as possible.</p>

### 입력 

 <p>Your program is to read from standard input. The input begins with a line containing a positive integer k (1 ≤ k ≤ 20) which represents the height of a full binary tree. In the second line, all the edge weights are given. The edge weights are given by level-by-level, and left-to-right order in a level. The weight of any edge is between 1 and 1,000, inclusive.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line which contains the total edge weights of the tree obtained after increasing edge weights. Note that the weight of a certain edge can be increased to a value larger than 1,000 in some cases.</p>

