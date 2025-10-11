# [Gold II] 축구 - 4822 

[문제 링크](https://www.acmicpc.net/problem/4822) 

### 성능 요약

메모리: 2036 KB, 시간: 676 ms

### 분류

백트래킹, 브루트포스 알고리즘, 자료 구조, 해시를 사용한 집합과 맵, 구현, 정렬, 문자열, 집합과 맵

### 제출 일자

2025년 10월 12일 08:49:24

### 문제 설명

<p>In soccer, there are many different rewards (and punishments) depending on how you rank in the league at the end of a season. For example, in the British Premier League, the top 4 teams are eligible to play in the Champions League, the next team is eligible to play in the Europa League, and the bottom three teams are relegated to the lower division. It is now near the end of the soccer season, and there are still a number of games to be played. For any given team, we wish to know what is the highest and lowest rank it can have at the end of the season.</p>

<p>For each game played, a team wins if it scores more goals than its opponent. A team loses a game if it scores fewer goals. When both teams score the same number of goals, we call it a draw. A team earns 3 points for each win, 1 point for each draw and 0 point for each loss. Teams are ranked according to the number of points earned (more points result in a higher ranking). Teams that are tied are given the same rank. For example, if two teams are tied and have the next highest point total after the 3rd place team, then they are both ranked 4th (and the next team is ranked 6th). In real life, factors such as goal differences and goals scored are used to break ties, but we will not consider these for this problem.</p>

<p>You are given a list of soccer teams and a list of matches in a season. You may assume that every team will play the same number of games at the end. Some of the matches have been played and the results are known.</p>

### 입력 

 <p>The input consists of a number of cases. The ﬁrst line in each case speciﬁes two integers n and m (2 ≤ n ≤ 20, 1 ≤ m ≤ 1000) indicating the number of teams in the league and the number of matches in the season. The next n lines contain the name of each team in its own line. The team names contain only alphabetic characters and have lengths at most 30 characters. This is followed by m lines each of the form</p>

<p>team1 vs team2: x y</p>

<p>with team1 and team2 being the names of two different teams, and x and y are non-negative integers (or both are -1), indicating that in the game between team1 and team2, team1 scores x goals and team2 scores y goals. If both x and y are -1, then the game has not yet been played. At most 12 games will not have been played yet.</p>

<p>The input is terminated with n = m = 0.</p>

### 출력 

 <p>For each team in the same order as the team list in the input, print one line of the following form:</p>

<p>Team XXX can finish as high as nth place and as low as mth place.</p>

<p>Use st, nd, and rd instead of th for ﬁrst, second, and third place, respectively. Print a blank line between cases.</p>

