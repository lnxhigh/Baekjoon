# [Silver V] 팰린드롬 - 8892 

[문제 링크](https://www.acmicpc.net/problem/8892) 

### 성능 요약

메모리: 2156 KB, 시간: 20 ms

### 분류

브루트포스 알고리즘, 문자열

### 제출 일자

2024년 8월 31일 08:16:16

### 문제 설명

<p>A palindrome is a word which can be read the same way in either direction. For example, the following words are palindromes: civic, radar, rotor, and madam. <br>
 <br>
You have found a note that contains k words. Later you found out that the note contains a clue to the password for accessing the most secret server where ICPC problems are stored. Unfortunately, the password is not written as it is. It is the concatenation of two different strings out of the k words, and it is a palindrome. For example, you can find the palindrome abababa from the five words aaba, ba, ababa, bbaa, and baaba by concatenating ababa and ba. <br>
 <br>
Write a program to find the password from k given words. </p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing one integer k (1 ≤ k ≤ 100), where k is the number of words in the note. In the next k lines of each test case, each line contains a word in ASCII characters between a and z. The sum of lengths of strings for each case is equal to or smaller than 10,000. </p>

### 출력 

 <p>Your program is to write to standard output. For each test case, if there is no palindrome obtained by concatenating two strings, print a single line containing 0. Otherwise, print the palindrome. If there are two or more palindromes, just print one of them. </p>

