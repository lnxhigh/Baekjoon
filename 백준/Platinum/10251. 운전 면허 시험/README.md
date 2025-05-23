# [Platinum V] 운전 면허 시험 - 10251 

[문제 링크](https://www.acmicpc.net/problem/10251) 

### 성능 요약

메모리: 17724 KB, 시간: 336 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 5월 23일 09:22:41

### 문제 설명

<p>Taking a driving test must make people nervous in almost every city in the world. People in Grid city in which road network looks like a grid should pass an interesting driving test in order to obtain a driver’s license. Information on an M × N grid-shaped road network is given to the applicant before he takes the test in the city. Using the given information, he has to comply with 3 rules, described below, to pass the test.</p>

<p><strong><img alt="" src="https://www.acmicpc.net/upload/images2/driving1(1).png" style="float:right; height:205px; width:286px">Rule 1</strong>: He must drive a car eastward or downward from the starting point s, located at upper-left corner of the grid, to the ending point t, located at lower-right corner of the grid. </p>

<p><strong>Rule 2</strong>: The driving time for each segment (either vertical or horizontal) of the grid must be exactly L (which is given before taking the test) and the turning time to change direction must be exactly 1. No turning time is assumed at the starting point s. </p>

<p><strong>Rule 3</strong>: Using an amount of fuel, say G, given before taking the test, he has to reach t as soon as possible without consuming additional fuel. </p>

<p>Note that he has to control the speed of the car considering the road condition to comply with the rule 2. So, the amount of fuel consumed to pass each segment could be different. Also note that he has to find a fastest route among several possible routes along which he can drive using as much fuel as G. </p>

<p>Fig. 1 shows a 4 × 6 grid-shaped road network, which has 4 horizontal streets and 6 vertical streets. Numbers shown for each segment of the grid denote the required amount of fuel to pass it.</p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images2/driving2(1).png" style="height:223px; width:591px"></p>

<p>Suppose a road network as shown in Fig. 1 and G = 19 and L = 10 are given as input. Fig. 2 shows two possible routes. The route shown in the left figure consumes fuel as much as 17 and it takes driving time 83 since it passes 8 grid segments and changes direction 3 times. On the other hand, the route shown in the right figure consumes a bit less fuel but it takes driving time 85. Note that there are some other routes along which he can drive with fuel 19 within time 83. However, there is no route along which he can drive faster with fuel 19. </p>

<p>You are to make a program which helps to find a route to pass the driving test in Grid city. You can assume that given a grid, the starting point locates at upper-left corner and the ending point at lower-right corner and that no fuel is consumed for turning direction. </p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with 4 integers: M, N, L, and G, where M and N (2 ≤ M, N ≤ 100) denote the dimension of the grid, L (1 ≤ L ≤ 10) the driving time to pass each grid segment, and G (1 ≤ G ≤ 1, 000, 000) the amount of fuel given before testing. Each of the following M lines contains N - 1 integers, each of which denotes the amount of fuel consumed to pass the corresponding horizontal segment of the grid. Another M - 1 lines follow. Each of the following M - 1 lines contains N integers, each of which denotes the amount of fuel consumed to pass the corresponding vertical segment of the grid. Each integer used for the amount of fuel to pass each correspoing segment of the grid is within 1 and 1,000 inclusive. </p>

<p>All the integers shown in a same line are separated by a blank.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should show the total elapsed time along the fastest route. If it is impossible to drive from s to t along any route with given amount of fuel G, print -1. </p>

