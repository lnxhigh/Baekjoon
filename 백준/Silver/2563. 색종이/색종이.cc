#include <bits/stdc++.h>
using namespace std;

int N;
int paper[100][100] = {0,};

void color(int paper[100][100], int x, int y) {
    for (int i = x; i < x + 10; i++) {
        for (int j = y; j < y + 10; j++) {
            paper[i][j]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        color(paper, x, y);
    }
    
    int answer = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (paper[i][j]) answer++;
        }
    }

    cout << answer << '\n';
    
    return 0;
}