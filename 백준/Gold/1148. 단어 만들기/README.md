# [Gold V] 단어 만들기 - 1148 

[문제 링크](https://www.acmicpc.net/problem/1148) 

### 성능 요약

메모리: 8280 KB, 시간: 240 ms

### 분류

구현, 문자열

### 제출 일자

2025년 3월 25일 00:29:58

### 문제 설명

<p>Target is a common newspaper word puzzle in which you are given a grid containing nine letters and must find as many words as possible using those letters. For example, the letters in the following grid can be used to form the words ‘LINT’, ‘TILL’, and ‘BRILLIANT’, among others:</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/1148/1.png" style="height:111px; width:111px"></p>

<p>Words must be at least four letters in length, and may use each letter in the grid at most once. (Thus they can be no longer than nine letters.) Furthermore, they must contain the grid’s central letter, in this case ‘I’.</p>

<p>Once the puzzle-maker has chosen the letters to put in the grid, the choice of which is to be the central letter makes a great difference to the number of words that can be made, and hence the difficulty of the puzzle.</p>

<p>You are the puzzle-maker’s assistant. You have been given the puzzle-maker’s dictionary of valid words, and must analyse potential grids to see how many words from the dictionary can be formed from them. On each grid, the puzzle-maker has not yet decided which letter to put in the central position, and would like to know which choices would permit the smallest and largest numbers of words to be formed.</p>

<p>Given a potential grid, you must find out which letter or letters, when placed in the central position, permit the fewest words from the dictionary to be formed according to the rules. And you must find out just how many words that is. And similarly you must find out which letter or letters placed centrally permit the most dictionary words to be formed.</p>

### 입력 

 <p>The input file consists of a dictionary of up to 200,000 words followed by any number of grids to be analysed against that dictionary.</p>

<p>The dictionary consists of words with between four and nine uppercase letters, one per line, given in alphabetical order. A single ‘-’ on a line by itself indicates the end of the dictionary.</p>

<p>Subsequent lines each contain one grid to be analysed. Each of these lines consists of exactly nine uppercase letters. A single ‘#’ on a line by itself indicates the end of input.</p>

### 출력 

 <p>For each input grid, output one line containing the central letter(s) that produce the smallest number of words and that number itself, and the central letter(s) that produce the greatest number of words and that number itself. Where there is more than one letter that produces the minimum or maximum, output all the appropriate letters in alphabetical order (without duplicates, even if a letter appears in the grid more than once—such as I or L in the grid pictured). Separate each number and group of letters with a single space.</p>

