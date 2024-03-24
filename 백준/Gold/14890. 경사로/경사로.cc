#include <bits/stdc++.h>
#define N_MAX 100
using namespace std;

int N, L;
int Map[N_MAX][N_MAX];
int answer = 0;

bool checkRow(int r) {
    int start = Map[r][0];
    int ramp[N_MAX] = {0,};
    
    for (int c = 0; c < N; c++) {
        int value = Map[r][c];        
        if (start == value) continue;
        
        if (start > value) {
            if (start - 1 != value) return false;

            for (int i = c; i < c+L; i++) {
                if (i >= N) return false;
                ramp[i]++;
            }
        }
        else if (start < value) {
            if (start + 1 != value) return false;

            for (int i = c-1; i > c-L-1; i--) {
                if (i < 0) return false;
                ramp[i]++;
            }
        }
        
        start = value;
    }

    for (int i = 0; i < N; i++) {
        if (ramp[i] > 1) return false;
    }
    
    return true;
}

bool checkCol(int c) {
    int start = Map[0][c];
    int ramp[N_MAX] = {0,};
    
    for (int r = 0; r < N; r++) {
        int value = Map[r][c];
        if (start == value) continue;
        
        if (start > value) {
            if (start - 1 != value) return false;

            for (int i = r; i < r+L; i++) {
                if (i >= N) return false;
                ramp[i]++;
            }
        }
        else if (start < value) {
            if (start + 1 != value) return false;

            for (int i = r-1; i > r-L-1; i--) {
                if (i < 0) return false;
                ramp[i]++;
            }
        }
        
        start = value;
    }

    for (int i = 0; i < N; i++) {
        if (ramp[i] > 1) return false;
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> L;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> Map[r][c];
        }
    }

    for (int r = 0; r < N; r++) {
        if (checkRow(r)) answer++;
    }
    for (int c = 0; c < N; c++) {
        if (checkCol(c)) answer++;
    }
    cout << answer << '\n';
    
    return 0;
}