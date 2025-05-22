# [Gold I] YouTube - 3117 

[문제 링크](https://www.acmicpc.net/problem/3117) 

### 성능 요약

메모리: 14128 KB, 시간: 60 ms

### 분류

자료 구조, 희소 배열

### 제출 일자

2025년 5월 23일 00:44:31

### 문제 설명

<p>N students are bored in computer class so they watch funny video clips on YouTube. </p>

<p>The site contains K popular clips, numbered 1 through N. When a video clip is watched, a list of similar video clips is displayed on the side. </p>

<p>Every student picks a video clip from the main page and starts watching it. After exactly one minute every student gets bored of his or her video clip, so he opens the first video clip from the list of similar clips on the side (even if he already watched that clip). </p>

<p>Write a program that determines for each student which video clip he will be watching during the M-th minute of the class. </p>

### 입력 

 <p>The first line contains three integers N, K and M (1 ≤ N, K ≤ 100 000) (1 < M ≤ 1 000 000 000), the numbers of students, video clips and minutes. </p>

<p>The second line contains N integers, each between 1 and K, the indices of video clips the students start watching. </p>

<p>The third line contains K integers, each between 1 and K, the index of the first similar clip for each video clip. </p>

### 출력 

 <p>Output N integers, the indices of video clips that students will be watching during the M-th minute.</p>

<p> </p>

