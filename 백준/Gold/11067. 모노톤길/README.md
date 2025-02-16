# [Gold V] 모노톤길 - 11067 

[문제 링크](https://www.acmicpc.net/problem/11067) 

### 성능 요약

메모리: 6900 KB, 시간: 2028 ms

### 분류

자료 구조, 구현, 정렬

### 제출 일자

2025년 2월 16일 22:56:28

### 문제 설명

<p>There is a famous walkway which is a Jeju Olle trail course. The entrance is one of the westernmost positions of this walkway. Since the walkway is a simple path which consists of horizontal sections and vertical sections, a walker should turn 90 degree left or right at every corner of the path. Also, a walker can move from the entrance to the exit without moving from east to west, i.e., without decreasing the x-coordinate of one's current position. So, this path is called a monotone walkway. Figure 1 shows an example of a monotone walkway</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11067/1.png" style="height:188px; line-height:20.8px; text-align:center; width:321px"></p>

<p style="text-align: center;">Figure 1. An example of a monotone walkway</p>

<p>There are n cafés along the walkway here and there. Specifically, there exist cafés on the entrance, the exit, and all corners of the path. Mr. Kim, a manager of Jeju Olle trail courses, has the location coordinates of all cafés. The coordinate of the entrance is always the origin (0,0). He is going to number all cafés from 1 to n. The café located on the entrance is assigned the number 1. The remaining cafés are assigned the numbers according to the order they are visited. Traversing the walkway from the entrance to the exit, a café A which is visited before another café B is assigned the smaller number than the café B. In the walkway of Figure 1, the cafés located on the coordinates (3,1) and (9,0) are assigned the number 5 and 14, respectively, and the café on the exit is assigned the number 17. He wants to do his work without having to walk the path. To help him, you are to write a program which carries out the work of numbering the cafés.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing an integer, n (2 ≤ n ≤ 100,000), where n is the number of cafés. In the following n lines, each coordinate of the n cafés is given line by line. Each coordinate is represented by two numbers x and y, which are the x-coordinate and the y-coordinate of the café, respectively (0 ≤ x ≤ 100,000 and -100,000 ≤ y ≤ 100,000). The coordinate of the entrance is always (0,0). Note that there are no two cafés which have a same coordinate. The last line of the input has an integer m (1 ≤ m ≤ 10) and m additional integers between 1 and n, inclusively, which are the café numbers.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each of m integers given as café numbers in each test case. The line should contain two integers x and y representing the coordinate of the café whose number is k for a given integer k.</p>

