# [Platinum V] 주식왕 동호 - 1231 

[문제 링크](https://www.acmicpc.net/problem/1231) 

### 성능 요약

메모리: 3972 KB, 시간: 140 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2025년 5월 7일 15:35:50

### 문제 설명

<p>Despite their innate prudence, the cows took a beating in the home mortgage market and now are trying their hand at stocks. Happily, Bessie is prescient and knows not only today's S (2 <= S <= 50) stock prices but also the future stock prices for a total of D days (2 <= D <= 10).</p>

<p>Given the matrix of current and future stock prices on various days (1 <= PR_sd <= 1,000) and an initial M (1 <= M <= 200,000) units of money, determine an optimal buying and selling strategy in order to maximize the gain realized by selling stock on the final day. Shares must be purchased in integer multiples, and you need not spend all the money (or any money). It is guaranteed that you will not be able to earn a profit of more than 500,000 units of money.</p>

<p>Consider the example below of a bull (i.e., improving) market, the kind Bessie likes most. In this case, S=2 stocks and D=3 days. The cows have 10 units of money to invest.</p>

<pre>                   Today's price
                   |   Tomorrow's price
                   |   |  Two days hence
             Stock |   |  | 
              1    10 15 15
              2    13 11 20
</pre>

<p>If money is to be made, the cows must purchase stock 1 on day 1. Selling stock 1 on day 2 and quickly buying stock 2 yields 4 money in the bank and one share of 2. Selling stock 2 on the final day brings in 20 money for a total of 24 money when the 20 is added to the bank.</p>

### 입력 

 <p>* Line 1: Three space-separated integers: S, D, and M</p>

<p>* Lines 2..S+1: Line s+1 contains the D prices for stock s on days 1..D: PR_sd</p>

### 출력 

 <p>* Line 1: The maximum amount of money possible to have after selling on day D.</p>

