# [Gold II] 용량 확보 - 9327 

[문제 링크](https://www.acmicpc.net/problem/9327) 

### 성능 요약

메모리: 2020 KB, 시간: 32 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2025년 4월 19일 15:10:25

### 문제 설명

<p>After a PR mishap with a former employee, the NSA might need to increase storage in one of their datacenters: the Russian and Spanish translators have a backlog, and the captured phone conversations need to be stored in the meantime. Up to 1 exabyte of data needs to be stored. Unfortunately, there is currently no extra storage available at all.</p>

<p>Due to budget limitations, it is not possible to immediately buy new disks, and the system administrator (you) wants to solve this by reducing the data redundancy. For performance and reliability, all data is currently on large RAID-1 sets of four disks in each server. More data can be stored by converting some of these sets to the slower RAID-5 technique.</p>

<p>Speciﬁcally, there are currently n RAID-1 sets. Each set i is built using disks of size S<sub>i</sub>, and this set can hold S<sub>i</sub> GB of data. If you convert one set to RAID-5, it can hold three times as much data: 3 · S<sub>i</sub> GB. You want to convert as few GBs of storage as possible.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/raid.png" style="height:111px; width:463px"></p>

<p>Disks with size S = 4, capacity respectively 4 GB (D0 ... D3) and 3 · 4 = 12 GB (D0 ... D11).</p>

### 입력 

 <p>On the ﬁrst line one positive number: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with two space-separated integers n and e (1 ≤ n ≤ 100 and 0 ≤ e ≤ 10<sup>9</sup>): the number of RAID-1 sets, and the amount of extra space in GB required, respectively.</li>
	<li>one line with n space-separated integers S<sub>1</sub> ... S<sub>n</sub> (1 ≤ S<sub>i</sub> ≤ 2 000): the sizes of all raid sets in GB.</li>
</ul>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with an integer: the number of GB you need to convert, or the string “<code>FULL</code>” if not enough diskspace can be freed.</li>
</ul>

