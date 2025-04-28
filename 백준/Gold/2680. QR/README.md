# [Gold II] QR - 2680 

[문제 링크](https://www.acmicpc.net/problem/2680) 

### 성능 요약

메모리: 2080 KB, 시간: 0 ms

### 분류

구현

### 제출 일자

2025년 4월 29일 08:53:35

### 문제 설명

<p>QR Codes (the smallest, which is 21 pixels by 21 pixels, is shown below) are square arrays of blackor white pixels (modules) which include Position Detection Patterns (the square bull‘s-eye patterns),Timing Patterns (the alternating black and white lines), Alignment Patterns in larger QR Codes,Format Information (the stippled pixels), Version information in larger QR Codes and Data and ErrorCorrection Codewords (gray 8 pixel blocks).</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/qr.png" style="height:323px; width:329px"></p>

<p>The 21-by-21 QR Code has 26 data and error correction codewords. At the lowest error correctionlevel for this code, 19 are data codewords and 7 are error correction codewords. Data may beencoded as numeric at 3 numbers per 10 bits, as alphanumeric at 2 characters per 11 bits, as 8 bitbytes or as Kanji at 13 bits per character. Data is encoded in groups of (mode, character count,character data bits). The mode can change within the data stream. The mode is specified by a 4 bitcode and the character count by a varying number of bits depending on the mode and QR Code size.For the 21-by-21 code, the character count bits are:</p>

<table class="table table-bordered" style="width:50%">
	<thead>
		<tr>
			<th>Mode Name</th>
			<th>Mode Bits</th>
			<th>Count Bits</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>Numeric</td>
			<td>0001</td>
			<td>10</td>
		</tr>
		<tr>
			<td>Alphanumeric</td>
			<td>0010</td>
			<td>9</td>
		</tr>
		<tr>
			<td>8 bit byte</td>
			<td>0100</td>
			<td>8</td>
		</tr>
		<tr>
			<td>Kanji</td>
			<td>1000</td>
			<td>8</td>
		</tr>
		<tr>
			<td>Termination</td>
			<td>0000</td>
			<td>0</td>
		</tr>
	</tbody>
</table>

<p>The entire data stream ends in the termination code which may be truncated if there is not enoughroom. Any partially filled codeword after the termination code is filled with 0 bits. Any remainingcodewords are set to 11101100 followed by 00010001 alternating.</p>

<p>Numeric strings are encoded 3 digits at a time. If there are remaining digits, 2 digits are encoded in 7bits or 1 digit in 4 bits. For example:</p>

<pre>12345678 → 123 456 78 → 0001111011 0111001000 1001110</pre>

<p>Prefix with mode (0001) and count (8 ڀ 0000001000) is (4 + 10 + 10 + 10 + 7) bits:</p>

<pre>0001 0000001000 0001111011 0111001000 1001110</pre>

<p>Alphanumeric strings encode the characters (<SP> represents the space character):</p>

<pre>0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ<SP>$%*+-./:</pre>

<p>as numbers from 0 to 44, then two characters are encoded in 11 bits:</p>

<pre><first char code> * 45 + <second char code></pre>

<p>if the number of characters is odd, the last character is encoded in 6 bits. For example:</p>

<pre>AC-42 → (10, 12, 41, 4, 2) → 10*45 + 12 = 462, 41*45 + 4 = 1849, 2 → 00111001110 11100111001 000010</pre>

<p>Prefix with mode and count is (4 + 9 + 11 + 11+ 6) bits:</p>

<pre>0010 000000101 00111001110 11100111001 000010</pre>

<p>The 8 bit binary and Kanji modes will be straightforward for the purposes of this problem. Kanji codeswill just be opaque 13 bit codes; you need not decode the characters they represent, just thehexadecimal values. For example:</p>

<pre>8 bit 0x45 0x92 0xa3 → 01000101 10010010 10100011</pre>

<p>Prefix with mode and count is (4 + 8 + 8 + 8 + 8) bits:</p>

<pre>0100 00000011 01000101 10010010 10100011</pre>

<pre>Kanji 0x1ABC 0x0345 → 1101010111100 0001101000101</pre>

<p>Prefix with mode and count is (4 + 8 + 13 + 13) bits:</p>

<pre>1000 00000010 1101010111100 0001101000101</pre>

<p>To illustrate forming the 19 codeword content of a QR Code, combine the first 3 sequences above (for numeric, alphanumeric and bytes). Concatenate the bits, split into 8 bit code words add the termination codeword, any fill bits and fill bytes(41 + 41 + 36 data bits + 4 bit termination code = 122 → 6 fill bits are needed to get 16 bytes, and to fill out the 19 bytes, 3 fill bytes are needed):</p>

<pre>0001 0000001000 0001111011 0111001000 1001110
0010 000000101 00111001110 11100111001 000010
0100 00000011 01000101 10010010 10100011
0000 000000 11101100 00010001 11101100</pre>

<p>split into 8 bit codewords:</p>

<pre>00010000 00100000 01111011 01110010 00100111 00010000 00010100 11100111
01110011 10010000 10010000 00001101 00010110 01001010 10001100 00000000
11101100 00010001 11101100 → HEX 10207B72271014E77390900D164A8C00EC11EC</pre>

<p>Write a program to read 19 codewords and print the corresponding data.</p>

### 입력 

 <p>The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data setsthat follow. Each data set is a single line of input consisting of the data set number, N, followed by asingle space and 38 hexadecimal digits giving the 19 bytes of QR Code data. The valid hexadecimal digits are 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E and F.</p>

### 출력 

 <p>For each data set there is one line of output. It contains the data set number (N) followed by a singlespace, the number of QR decoded characters in the result, a single space and the character stringcorresponding to the QR Code data. In the output string, printable ASCII characters (in the range0x20 to 0x7e) are printed as the ASCII character EXCEPT that backslash (\) is printed as <span>\</span> andpound sign (#) is printed as \#. Non-printable 8 bit data is output as \xx, where x is a hexadecimaldigit (e.g. \AE). Non-printable 8 bit data is any value that is less than the ASCII value of a space(0x20) or greater than 0x76. 13 bit Kanji values are printed as #bxxx, where b is 0 or 1 and x is ahexadecimal digit (e.g. #13AC).</p>

