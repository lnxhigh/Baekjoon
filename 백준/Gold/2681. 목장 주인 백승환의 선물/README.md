# [Gold I] 목장 주인 백승환의 선물 - 2681 

[문제 링크](https://www.acmicpc.net/problem/2681) 

### 성능 요약

메모리: 2036 KB, 시간: 0 ms

### 분류

구현, 기하학, 선분 교차 판정

### 제출 일자

2025년 6월 8일 18:53:24

### 문제 설명

<p>Rancher Joel has a tract of land in the shape of a convex quadrilateral that he wants to divide among his sons Al, Bob, Chas and Dave, who wish to continue ranching on their portions, and his daughter Emily, who wishes to grow vegetables on her portion.</p>

<p>The center of the tract is most suitable for vegetable farming so Joel decides to divide the land by drawing lines from each corner (A, B, C, D in counter clockwise order) to the center of an opposing side (respectively A', B', C' and D' ). Each son would receive one of the triangular sections and Emily would receive the central quadrilateral section. As shown in the figure, Al's tract is to be bounded by the line from A to B, the line from A to the midpoint of BC and the line from B to the midpoint of CD; Bob's tract is to be bounded by the line from B to C, the line from B to the midpoint of CD and the line from C to the midpoint of DA, and so on.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/rgift.png" style="height:317px; width:468px"></p>

<p>Your job is to write a program that will help Rancher Joel determine the area of each child's tract and the length of the fence he will have to put around Emily's parcel to keep her brothers' cows out of her crops.</p>

<p>For this problem, A will always be at (0, 0) and B will always be at (x, 0). Coordinates will be in rods (a rod is 16.5 feet). The returned areas should be in acres to 3 decimal places (an acre is 160 square rods) and the length of the fence should be in feet, rounded up to the next foot.</p>

### 입력 

 <p>The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set is a single line that contains of a decimal integer followed by five (5) space separated floating-point values. The first (integer) value is the data set number, N. The floating-point values are B.x, C.x, C.y, D.x and D.y in that order (where V.x indicates the x coordinate of V and V.y indicates the y coordinate of V). Recall that the y coordinate of B is always zero (0).</p>

<p>The supplied coordinates will always specify a valid convex quadrilateral.</p>

### 출력 

 <p>For each data set there is a single line of output. It contains the data set number, N, followed by a single space followed by five (5) space separated Itoating point values to three (3) decimal place accuracy, followed by a single space and a decimal integer. The floating-point values are the areas in acres of the properties of Al, Bob, Chas, Dave, and Emily respectively. The final integer is the length of fence in feet required to fence in Emily's property (rounded up to the next foot).</p>

