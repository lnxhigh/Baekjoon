# [Gold III] 성곽 - 2234 

[문제 링크](https://www.acmicpc.net/problem/2234) 

### 성능 요약

메모리: 2060 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 비트마스킹, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 4월 1일 00:00:42

### 문제 설명

<pre>     1   2   3   4   5   6   7
   #############################
 1 #   |   #   |   #   |   |   #
   #####---#####---#---#####---#   
 2 #   #   |   #   #   #   #   #
   #---#####---#####---#####---#
 3 #   |   |   #   #   #   #   #   
   #---#########---#####---#---#
 4 # ->#   |   |   |   |   #   #   
   #############################  (Figure 1)

#  = Wall
|  = No wall
-  = No wall
-> = It points to the wall to remove according to the example output.</pre>

<p>Figure 1 shows the map of a castle. Write a program that calculates</p>

<ol>
	<li>how many rooms the castle has</li>
	<li>how big the largest room is</li>
	<li>which wall to remove from the castle to make as large a room as possible.</li>
</ol>

<p>The castle is divided into m * n (m<=50, n<=50) square modules. Each such module can have between zero and four walls.</p>

### 입력 

 <p>The map is stored in the input in the form of numbers, one for each module.</p>

<ul>
	<li>The input starts with the number of modules in the north-south direction and the number of modules in the east-west direction.</li>
	<li>In the following lines each module is described by a number (0<=p<=15). This number is the sum of: 1 (= wall to the west), 2 (= wall to the north), 4 (= wall to the east), 8 (= wall to the south). Inner walls are defined twice; a wall to the south in module 1,1 is also indicated as a wall to the north in module 2,1.</li>
	<li>The castle always has at least two rooms.</li>
</ul>

### 출력 

 <p>In the output, the following are written on three lines: First the number of rooms, then the area of the largest room (counted in modules) and a suggestion of which wall to remove (first the row and then the column of the module next to the wall and finally the compass direction that points to the wall). In our example ("4 1 E" is one of several possibilities, you need only produce one):</p>

<p> </p>

