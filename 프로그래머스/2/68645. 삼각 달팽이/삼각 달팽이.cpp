#include <bits/stdc++.h>
#define N_MAX 1001

using namespace std;

int snail[N_MAX][N_MAX];

void f(int s, int x, int y, int N) {
    if (N <= 0) return;
    for (int r = 0; r < N; r++) {
        snail[x + r][y] = s++;
    }
    for (int c = 1; c < N; c++) {
        snail[x + N - 1][y + c] = s++;
    }
    for (int i = 1; i < N - 1; i++) {
        snail[x + N - 1 - i][y + N - 1 - i] = s++;
    }
    
    f(s, x+2, y+1, N-3);
}

vector<int> solution(int N) {
    vector<int> answer;
    
    f(1, 1, 1, N);
    
    
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= r; c++) {
            answer.push_back(snail[r][c]);
        }
    }
    
    return answer;
}