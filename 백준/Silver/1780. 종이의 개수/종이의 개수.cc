#include <bits/stdc++.h>
#define N_MAX 2187
using namespace std;

int N;
int paper[N_MAX][N_MAX];
int minusOne = 0, zero = 0, plusOne = 0;

bool check(int x, int y, int N) {
    int first = paper[x][y];

    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (first != paper[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void f(int x, int y, int N) {
    if (check(x, y, N)) {
        int num = paper[x][y];
        if (num == -1) minusOne++;
        else if (num == 0) zero++;
        else if (num == 1) plusOne++;
        else cerr << "Unexpected Number" << '\n';

        return;
    }

    int M = N / 3;

    for (int i : {x, x + M, x + 2*M}) {
        for (int j : {y, y + M, y + 2*M}) {
            f(i, j, M);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    f(0, 0, N);
    cout << minusOne << '\n';
    cout << zero << '\n';
    cout << plusOne << '\n';

    return 0;
}
