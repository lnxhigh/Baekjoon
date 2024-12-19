# [Gold V] Cheating a Boolean Tree (Small) - 12703 

[문제 링크](https://www.acmicpc.net/problem/12703) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

백트래킹, 구현, 트리

### 제출 일자

2024년 12월 20일 01:29:43

### 문제 설명

<p>For this problem we will consider a type of binary tree that we will call a boolean tree. In this tree, every row is completely filled, except possibly the last (deepest) row, and the nodes in the last row are as far to the left as possible. Additionally, every node in the tree will either have 0 or 2 children. </p>

<p>What makes a boolean tree special is that each node has a boolean value associated with it, 1 or 0. In addition, each interior node has either an "AND" or an "OR" gate associated with it. The value of an "AND" gate node is given by the logical AND of its two children's values. The value of an "OR" gate likewise is given by the logical OR of its two children's values. The value of all of the leaf nodes will be given as input so that the value of all nodes can be calculated up the tree.</p>

<p>The root of the tree is of particular interest to us. We would really like for the root to have the value <strong>V</strong>, either 1 or 0. Unfortunately, this may not be the value the root actually has. Luckily for us, we can cheat and change the type of gate for some of the nodes; we can change an AND gate to an OR gate or an OR gate to an AND gate.</p>

<p>Given a description of a boolean tree and what gates can be changed, find the minimum number of gates that need to be changed to make the value of the root node <strong>V</strong>. If this is impossible, output "IMPOSSIBLE" (quotes for clarity).</p>

### 입력 

 <p>The first line of the input file contains the number of cases, <strong>N</strong>. <strong>N</strong> test cases follow.</p>

<p>Each case begins with <strong>M</strong> and <strong>V</strong>.  <strong>M</strong> represents the number of nodes in the tree and will be odd to ensure all nodes have 0 or 2 children.  <strong>V</strong> is the desired value for the root node, 0 or 1.</p>

<p><strong>M</strong> lines follow describing each of the tree's nodes. The X<sup>th</sup> line will describe node X, starting with node 1 on the first line.</p>

<p>The first (<strong>M</strong>−1)/2 lines describe the interior nodes. Each line contains <strong>G</strong> and <strong>C</strong>, each being either 0 or 1. If <strong>G</strong> is 1 then the gate for this node is an AND gate, otherwise it is an OR gate. If <strong>C</strong> is 1 then the gate for this node is changeable, otherwise it is not. Interior node X has nodes 2X and 2X+1 as children.</p>

<p>The next (<strong>M</strong>+1)/2 lines describe the leaf nodes. Each line contains one value <strong>I</strong>, 0 or 1, the value of the leaf node.</p>

<p>To help visualize, here is a picture of the tree in the first sample input.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/12704/images-2.png" style="height:240px; width:422px"></p>

<p>Limits</p>

<ul>
	<li>1 < <strong>N</strong> ≤ 20</li>
	<li>2 < <strong>M</strong> < 30</li>
</ul>

### 출력 

 <p>For each test case, you should output:</p>

<pre>Case #<strong>X</strong>: <strong>Y</strong></pre>

<p>where <strong>X</strong> is the number of the test case and <strong>Y</strong> is the minimum number of gates that must be changed to make the output of the root node <strong>V</strong>, or "IMPOSSIBLE" (quotes for clarity) if this is impossible.</p>

