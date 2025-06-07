# [Gold II] Jetpack - 13485 

[문제 링크](https://www.acmicpc.net/problem/13485) 

### 성능 요약

메모리: 8964 KB, 시간: 16 ms

### 분류

너비 우선 탐색, 깊이 우선 탐색, 그래프 이론, 그래프 탐색, 구현, 시뮬레이션

### 제출 일자

2025년 6월 7일 23:19:34

### 문제 설명

<p>Little Mirko got a new mobile phone for his birthday! As all kids nowadays, he quickly downloaded all of the popular mobile games, including Jetpack Joyride.</p>

<p>In the game, the protagonist Barry is running across a field consisting of 10 rows and N columns of squares of equal size. Initially, Barry is located in the center of the square in the lower left corner. Barry is constantly running to the right at the speed of one square per second. Additionally, he must avoid obstacles that are in his way.</p>

<p>When Mirko presses the phone screen, Barry turns on his super-duper special jetpack and starts his ascent at the speed of one square per second (still moving to the right, now moving diagonally up at an angle of 45°, until he reaches the ceiling, when he will continue moving to the right until Mirko releases the screen). When Mirko releases the phone screen, Barry starts falling down at the speed of one square per second (now moving diagonally again, but this time facing down, until he reaches the floor, when he will continue moving to the right).</p>

<p>Mirko just started playing the game recently and he’s still not good at it. He saw on YouTube that someone managed to complete the game by crossing all N columns, so he is asking you for your help. He will give you the layout of the fields in the game, and you must output the moves he has to play in order to win. </p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 10<sup>5</sup>), the size of the field.<br>
Each of the following 10 lines contains N characters ‘.’ and ‘X’, the layout of the field in the game. The characters ‘X’ denote obstacles, and ‘.’ walkable fields. </p>

### 출력 

 <p>The first line of output must contain the integer P (0 ≤ P ≤ 5⋅10<sup>4</sup>), the number of moves Mirko has to make. </p>

<p>In the following P lines, output any series of P moves, each in its own line, such that it solves Mirko’s problem from the task. </p>

<p>A move is determined by two integers​ t<sub>i</sub> and x<sub>i</sub>, where t<sub>i</sub> denotes the second in which Mirko has to press the screen, and x<sub>i</sub> denotes how long he needs to keep the screen pressed.</p>

<p>A series of moves must be sorted in chronological order. In other words, it must hold t<sub>i</sub>+ x<sub>i</sub> ≤ t<sub>i+1</sub>.</p>

<p>Also, no move should begin after the end of the game, t<sub>i</sub> < N.</p>

<p>The input data will be such that a solution will surely exist. </p>

