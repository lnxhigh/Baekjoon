#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;
const int INF = 1 << 20;

int N, H, D, K;
char A[MAX][MAX];

pair<int,int> S, E;
pair<int,int> U[16];

void input() {
    cin >> N >> H >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            A[i][j] = c;

            if (c == 'S') S = { i, j };
            else if (c == 'E') E = { i, j };
            else if (c == 'U') U[K++] = { i, j };
        }
    }

    U[K] = E;
}

int solve() {
    int ret = INF;

    for (int i = 0; i < (1 << K); i++) {
        vector<int> X; X.reserve(K + 1);
        for (int k = 0; k < K; k++) {
            if (i >> k & 1) X.push_back(k);
        }

        do {
            int cnt = 0;
            auto [x, y] = S;
            int curH = H, curD = 0;
            bool die = false;

            X.push_back(K);
            for (int k : X) {
                auto [nx, ny] = U[k];
                int dmg = abs(x - nx) + abs(y - ny) - 1;
                cnt += dmg + 1;

                int m = min(curD, dmg);
                curD -= m, dmg -= m;
                curH -= dmg;

                curD = D - 1;
                x = nx, y = ny;

                if (curH <= 0) { die = true; break; }
            }
            X.pop_back();

            if (!die) ret = min(ret, cnt);

        } while(next_permutation(X.begin(), X.end()));
    }

    return ret < INF ? ret : -1;
}

int main() {
    FastIO
    input();
    cout << solve() << '\n';
    return 0;
}
