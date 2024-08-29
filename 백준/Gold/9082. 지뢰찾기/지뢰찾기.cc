#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

const int MAX = 1 << 7;

bool f(int A[MAX], char B[MAX], int N) {
    for (int i = 0; i < N-1; i++) {
        int mine = 0, safe = 0, unknown = 0;
        for (int d : { -1, 0, +1 }) {
            int k = i + d;
            if (k < 0) continue;
            
            if (B[k] == '*') mine++;
            else if (B[k] == ' ') safe++;
            else if (B[k] == '#') unknown++;
        }

        if (unknown == 0) continue;
        
        char what = A[i] > mine ? '*' : ' ';
        B[i+1] = what;
    }

    for (int i = 0; i < N; i++) {
        int mine = 0, safe = 0, unknown = 0;
        for (int d : { -1, 0, +1 }) {
            int k = i + d;
            if (k < 0 || k >= N) continue;
            
            if (B[k] == '*') mine++;
            else if (B[k] == ' ') safe++;
            else if (B[k] == '#') unknown++;
        }
        
        if (unknown > 0) cout << "?" << '\n';
        if (A[i] != mine) return false;
    }

    return true;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int A[MAX];
        char B[MAX], X[MAX], Y[MAX];

        for (int i = 0; i < N; i++) { char x; cin >> x; A[i] = x - '0'; }
        for (int i = 0; i < N; i++) { cin >> B[i]; }
        for (int i = 0; i < N; i++) { X[i] = Y[i] = B[i]; }
        if (B[0] == '#') { X[0] = '*'; Y[0] = ' '; }

        bool first  = f(A, X, N);
        bool second = f(A, Y, N);

        if (!first && !second) cout << '?' << '\n';

        int resX = 0, resY = 0;
        for (int i = 0; i < N; i++) {
            if (first  && X[i] == '*') resX++;
            if (second && Y[i] == '*') resY++;
        }

        int res = max(resX, resY);
        cout << res << '\n';
    }

    return 0;
}
