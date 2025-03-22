# [Platinum IV] 날카로운 눈 - 1637 

[문제 링크](https://www.acmicpc.net/problem/1637) 

### 성능 요약

메모리: 2484 KB, 시간: 8 ms

### 분류

이분 탐색, 매개 변수 탐색

### 제출 일자

2025년 3월 23일 01:12:09

### 문제 설명

<p>Data-mining huge data sets can be a painful and long lasting process if we are not aware of tiny patterns existing within those data sets. </p>

<p>One reputable company has recently discovered a tiny bug in their hardware video processing solution and they are trying to create software workaround. To achieve maximum performance they use their chips in pairs and all data objects in memory should have even number of references. Under certain circumstances this rule became violated and exactly one data object is referred by odd number of references. They are ready to launch product and this is the only showstopper they have. They need YOU to help them resolve this critical issue in most efficient way. </p>

<p>Can you help them? </p>

### 입력 

 <p>Input file consists from multiple data sets separated by one or more empty lines. </p>

<p>Each data set represents a sequence of 32-bit (positive) integers (references) which are stored in compressed way. </p>

<p>Each line of input set consists from three single space separated 32-bit (positive) integers X Y Z and they represent following sequence of references: X, X+Z, X+2*Z, X+3*Z, …, X+K*Z, …(while (X+K*Z)<=Y). </p>

<p>Your task is to data-mine input data and for each set determine weather data were corrupted, which reference is occurring odd number of times, and count that reference.</p>

### 출력 

 <p>For each input data set you should print to standard output new line of text with either “NOTHING” (upper case) or two integers separated by single space (first one is reference that occurs odd number of times and second one is count of that reference). </p>

