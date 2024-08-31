# [Silver II] ABCD - 3199 

[문제 링크](https://www.acmicpc.net/problem/3199) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

기하학, 수학

### 제출 일자

2024년 8월 31일 13:01:41

### 문제 설명

<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/3199/1.png" style="float:left; height:189px; width:186px">A reconnaissance unit reports about an appliance found in the desert: the horrible weapon ABCD (Atomic Beryllium-Cesium Destroyer), fallen into terrorists’ hands. Its four components had been aligned there and in front and behind each of them a carrier rail spread “beyond infinity”, according to the report. Each attempt to destroy something and even to remove one of the parts from its rail would lead to global disaster. Terrorists know that and don’t even make the effort to safeguard: they only wait for word of command to set the appliance going. The parts are not heavy, even a child could move them back and forth along their rails, which is harmless, but, alas, doesn’t change their destructive power. Impasse!</p>

<p>And yet! You have got some secret information from the developers of ABCD, which the terrorists do not know: if its four parts form a perfect rectangle at the moment of switching the weapon on, a self-destruction begins with the only consequence of high radiation in the frames of this rectangle. In comparison with the global catastrophe this may look like an insignificant damage, but it’s a good idea to minimize it, too.</p>

<p>And so, save the mankind! Write a program abcd to determine whether it is possible to rearrange the four parts along the rails in a way to form a perfect rectangle. If the answer is positive, calculate the minimal area possible which will inevitably be exposed to radiation by the process of self-destruction of ABCD. The necessary information is comprised in the report: the distances AB, BC and CD between the parallel rails (see the satellite snapshot above).</p>

### 입력 

 <p>One line is read from the standard input, containing three space separated positive real numbers: p=AB, q=BC and r=CD.</p>

### 출력 

 <p>Write one line to the standard output, containing:</p>

<ul>
	<li>0, if no matter how A, B, C and D are moved each along its own rail, it is not possible to place them in a way to form an exactly perfect rectangle;</li>
	<li>one real number, formatted and rounded to the fourth decimal place: the area of the minimal rectangle, which can be obtained by moving the four parts, each along its own rail.</li>
</ul>

