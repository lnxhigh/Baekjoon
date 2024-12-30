# [Silver I] 완전 이진 트리 - 9934 

[문제 링크](https://www.acmicpc.net/problem/9934) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

재귀, 트리

### 제출 일자

2024년 12월 30일 16:30:39

### 문제 설명

<p>Little Mirko has paid a touristic visit to a village nearby Donji Andrijevci, a town in Slavonia. As it happens, the arrangement of streets in the village looks awfully familiar to the shape of a perfect binary tree of the order K. A perfect binary tree of order K consists of 2K - 1 nodes arranged in K levels (just like in the image). Each node contains a building labeled with a house number. Moreover, all buildings but the ones in the last level have a left and right child (see the image again). </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/2f3d1f78-7ef1-4be4-868c-6172f57f2db6/-/preview/" style="width: 429px; height: 147px;"></p>

<p style="text-align: center;">Perfect binary tree of orders 2 and 3</p>

<p>Mirko has visited all the buildings in a village and noted down the exact entrance order. Now he wants to describe to you how the village looks like, but he can't quite remember. Luckily, he remembers the way in which he visited the buildings: </p>

<ol>
	<li>in the beginning, he was standing in front of the only building in the first level </li>
	<li>if the building which he is currently standing in front of has a left child which he hasn't visited yet, he will move in front of the left child </li>
	<li>if the building doesn't have a left child or he has already visited it, he will enter the current building and write its house number on his paper </li>
	<li>if he has already visited the current building and the building has a right child, he will move in front of the right child </li>
	<li>if he has visited the current building and its left and right child, he will return to the parent of the current building </li>
</ol>

<p>After visiting the villages in the pictures above, the paper would look like this: 2-1-3 for the first village and 1-6-4-3-5-2-7 for the second village. Write a programme to help Mirko reconstruct the order of house numbers on each level.</p>

### 입력 

 <p>The first line of input contains the integer K (1 ≤ K ≤ 10), the number of levels of the village Mirko just visited. The second line of input contains 2<sup>K</sup> integers, the sequence of house numbers on Mirko's paper. The house numbers will be unique and from the interval [1, 2<sup>K</sup>]. </p>

### 출력 

 <p>The output must consist of K lines. The i<sup>th</sup> line must contain the sequence of house numbers in the i<sup>th</sup> level of the village. </p>

