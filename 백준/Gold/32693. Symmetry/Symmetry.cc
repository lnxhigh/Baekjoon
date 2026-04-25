#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

char A[500][500];
int64 ans = 0;

int main() {
    FastIO
    int64 R, C; cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> A[r][c];
        }
    }

    for (int64 p = 1; p <= C - 1; p++) {
        vector<int64> V(R, true);
        for (int64 len = 1; len <= min(p, C - p); len++) {
            int64 l = p - len;
            int64 r = p + (len - 1);

            for (int64 i = 0; i < R; i++) {
                V[i] &= (A[i][l] == A[i][r]);
            }

            vector<int64> X;
            
            stack<bool> st;
            for (int64 i = 0; i < R; i++) {
                if (!V[i]) {
                    int64 cnt = st.size();
                    if (cnt != 0) X.push_back(cnt);
                    while (!st.empty()) st.pop();
                }
                else {
                    st.push(V[i]);
                }
            }

            if (!st.empty()) {
                X.push_back((int64) st.size());
            }

            for (int64 i : X) {
                ans += i * (i + 1LL) / 2LL;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
