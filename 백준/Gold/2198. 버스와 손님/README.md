# [Gold I] 버스와 손님 - 2198 

[문제 링크](https://www.acmicpc.net/problem/2198) 

### 성능 요약

메모리: 3112 KB, 시간: 16 ms

### 분류

자료 구조, 그리디 알고리즘, 집합과 맵, 트리를 사용한 집합과 맵

### 제출 일자

2026년 04월 25일 11:59:38

### 문제 설명

<p>Figuring that they cannot do worse than the humans have, Farmer John's cows have decided to start an airline. Being cows, they decide to cater to the heretofore-untapped market of cows as passengers. They plan to serve the cows who live along the western coast of Lake Michigan. Each morning, they will fly from the northern-most point of the coast southward towards Chicowgo, making many stops along the way. Each evening, they will fly back north to the northern-most point.</p>

<p>They need your help to decide which passengers to carry each day. Each of N (1 <= N <= 10,000) farms numbered 1..N along the coast contains an airport (Farm 1 is northern-most; farm N is southern-most). On this day, K (1 <= K <= 50,000) groups of cows wish to travel.Each group of cows wants to fly from a particular farm to another particular farm. The airline, if it wishes, is allowed to stop and pick up only part of a group. Cows that start a flight, however,must stay on the plane until they reach their destination.</p>

<p>Given the capacity C (1 <= C <= 100) of the airplane and the groups of cows that want to travel, determine the maximum number of cows that the airline can fly to their destination.</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: K, N, and C</li>
	<li>Lines 2..K+1: Each line contains three space-separated integers S, E, and M that specify a group of cows that wishes to travel. The M (1 <= M <= C) cows are currently at farm S and want to travel to farm E (S != E).</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The maximum number of cows that can be flown to their destination. This is the sum of the number of cows flown to their destination on the flight southward in the morning plus the number of cows flown to their destination on the flight northward in the evening.</li>
</ul>

