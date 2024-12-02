# [Platinum V] 배열에서 이동 - 1981 

[문제 링크](https://www.acmicpc.net/problem/1981) 

### 성능 요약

메모리: 2088 KB, 시간: 28 ms

### 분류

너비 우선 탐색, 이분 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 12월 2일 22:51:24

### 문제 설명

<p>Emma is on a hiking trip with Eric, her freshly-married husband, for their honeymoon. They are hiking from one cabin to the next every day. Unfortunately, Eric is not as ﬁt as Emma and is slowly getting tired. Since Emma does not want to start their newly-formed marriage with a serious conﬂict (and needs somebody to keep her warm in the nights), she decides to plan the next day trips so that they are not so strenuous for Eric.</p>

<p>In the past days, Emma has discovered a surprising fact about her husband. He is not so much tired by the length of their daily trip or the total amount of meters they had to climb. Instead, Eric is tired the more, the bigger the difference between the highest and the lowest point of today’s route becomes. Emma assumes this is due to psychological factors. It just sounds a lot more difﬁcult to climb once from 500 meter to 1,500 meters than to climb from 200 to 400 meters ten times, although you climbed twice as much in the latter case.</p>

<p>Given an altitude map of the terrain, you should help Emma in ﬁnding a path that minimizes the difference between its highest and its lowest elevation, so that Eric does not feel as tired. The cabin they start at is located at the top-left corner and their destination is the bottom-right corner of the map. They can move along any of the four major directions but not on a diagonal.</p>

### 입력 

 <p>The ﬁrst line contains the number of scenarios. Each scenario starts with a number n (2 ≤ n ≤ 100), the size of the area. The elevations of the terrain are given as a n × n integer matrix (h<sub>i,j</sub>) (0 ≤ h<sub>i,j</sub> ≤ 200) on n lines, where each line contains n space-separated elevations.</p>

### 출력 

 <p>The output for every scenario begins with a line containing “Scenario #i:”, where i is the number of the scenario starting at 1. Then, print a single line containing the difference between the highest and the lowest elevation on the optimal path. Terminate the output for the scenario with a blank line.</p>

