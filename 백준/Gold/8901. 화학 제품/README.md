# [Gold V] 화학 제품 - 8901 

[문제 링크](https://www.acmicpc.net/problem/8901) 

### 성능 요약

메모리: 2020 KB, 시간: 288 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2025년 1월 3일 22:21:32

### 문제 설명

<p>We are given three chemicals A, B, and C contained in separated bottles. If we mix any two chemicals in equal units, we get a valuable chemical product. We call AB the mixture of A and B, BC the mixture of B and C, and CA the mixture of C and A (if we mix one unit of A and one unit of B, we get one unit of AB). Because the prices of AB, BC, and CA can be different, the profit obtained by making the products can vary depending on the way the products are made. Assume we can mix any two chemicals only in integer units. </p>

<p>For example, suppose there are 5 units of A, 3 units of B, and 7 units of C. The price of each product is shown in the next table. </p>

<table class="table table-bordered" style="width:40%">
	<thead>
		<tr>
			<th style="width:20%">Chemical Product</th>
			<th style="width:20%">Price(per one unit)</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>AB</td>
			<td><span>$</span>100</td>
		</tr>
		<tr>
			<td>BC</td>
			<td><span>$</span>30</td>
		</tr>
		<tr>
			<td>CA</td>
			<td><span>$</span>80</td>
		</tr>
	</tbody>
</table>

<p>If we mix one unit of A and one unit of B, we get <span>$</span>100 by making one unit of AB. Next, mixing 2 units of B and 2 units of C, we get <span>$</span>60. Finally, mixing 4 units of C and 4 units of A, we get <span>$</span>320. The total profit is <span>$</span>480, which is the maximum possible. Note that some portion of one chemical can remain unused: one unit of C is unused in this example. </p>

<p>For another example, suppose there are 3 units of A, 3 units of B, and 3 units of C. Each price of AB, BC, and CA is <span>$</span>100. If we mix 2 units of A and 2 units of B, we get <span>$</span>200. Next, mixing one unit of B and one unit of C, we get <span>$</span>100. Finally, mixing one unit of C and one unit of A, we get <span>$</span>100. The total profit is <span>$</span>400, which is the maximum possible. </p>

<p>Write a program which calculates the maximum profit when the quantities of A, B, C and the prices of AB, BC, CA are given. </p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case consists of two lines. The first line of each test case contains three integers. The three integers represent the quantities of chemicals A, B, and C. The second line of each test case contains three integers. The three integers represent the prices of chemical products AB, BC, and CA. All integers in the first and second lines are between 1 and 1,000, both inclusive. </p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain the maximum profit for the test case. </p>

