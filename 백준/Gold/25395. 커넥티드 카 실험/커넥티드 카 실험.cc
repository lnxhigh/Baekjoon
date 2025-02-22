#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 20;

int N, S;
int X[MAX], H[MAX];
bool D[MAX];

int main() {
    FastIO
    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> X[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    D[S] = true;
    int l = S, r = S;
    int lf = H[S], mf = H[S], rf = H[S];

    while (l > 1 || r < N) {
        bool update = false;

        if (l > 1) {
            if (X[l] - lf <= X[l - 1] || X[S] - mf <= X[l - 1]) {
                lf = max(lf - (X[l] - X[l - 1]), H[l - 1]);
                mf = max(mf, lf - (X[S] - X[l - 1]));

                D[--l] = true;
                update = true;
            }
        }

        if (r < N) {
            if (X[r] + rf >= X[r + 1] || X[S] + mf >= X[r + 1]) {
                rf = max(rf - (X[r + 1] - X[r]), H[r + 1]);
                mf = max(mf, rf - (X[r + 1] - X[S]));
                
                D[++r] = true;
                update = true;
            }
        }

        if (!update) break;
    }

    for (int i = 1; i <= N; i++) {
        if (D[i]) cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
