# [Silver II] 키로거 - 5397 

[문제 링크](https://www.acmicpc.net/problem/5397) 

### 성능 요약

메모리: 6488 KB, 시간: 60 ms

### 분류

자료 구조, 연결 리스트, 스택

### 제출 일자

2024년 11월 10일 23:41:45

### 문제 설명

<p>As a malicious hacker you are trying to steal your mother’s password, and therefore you have installed a keylogger on her PC (or Mac, so you like). You have a log from your mother typing the password, but unfortunately the password is not directly visible because she used the left and right arrows to change the position of the cursor, and the backspace to delete some characters. Write a program that can decode the password from the given keylog.</p>

### 입력 

 <p>The ﬁrst line of the input contains a single number: the number of test cases to follow. Each test case has the following format:</p>

<ul>
	<li>One line with a string L, satisfying 1 ≤ Length(L) ≤ 1,000,000, consisting of:
	<ul>
		<li>’-’ representing backspace: the character directly before the cursor position is deleted, if there is any.</li>
		<li>’<’ (and ’>’) representing the left (right) arrow: the cursor is moved 1 character to the left (right), if possible.</li>
		<li>alphanumeric characters, which are part of the password, unless deleted later. We assume ‘insert mode’: if the cursor is not at the end of the line, and you type an alphanumeric character, then all characters after the cursor move one position to the right.</li>
	</ul>
	</li>
</ul>

<p>Every decoded password will be of length > 0.</p>

### 출력 

 <p>For every test case in the input, the output should contain a single string, on a single line: the decoded password.</p>

