#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
int Data[50][9];

// 시간 초과 가능성 높음
int main() {
    FastIO
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> Data[i][j];
        }
    }

    int ans = 0;
    vector<int> order(9);
    iota(order.begin(), order.end(), 0);

    do {
        if (order[3] != 0) continue;
        int score = 0;
        int turn = 0;

        for (int inning = 0; inning < N; inning++) {
            int out = 0;
            vector<bool> base(5);
            base[0] = true;
            
            while (out < 3) {
                int batter = order[turn];
                int cnt = Data[inning][batter];
                if (cnt == 0) out++;

                for (int x = 3; x >= 0; x--) {
                    if (!base[x]) continue;

                    int nxt = x + cnt;
                    if (x != 0) base[x] = false;
                    
                    if (nxt >= 4) score++;
                    else base[nxt] = true;
                }

                turn = (turn + 1) % 9;
            }
            
        }

        ans = max(ans, score);

    } while (next_permutation(order.begin(), order.end()));

    cout << ans << '\n';
    return 0;
}
