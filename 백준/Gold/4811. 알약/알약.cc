#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
const int N_MAX = 31;
ll D[N_MAX][N_MAX<<1];

ll solve(int F, int H) {
    if (D[F][H] != -1) return D[F][H];

    ll res = 0;
    if (H == 0) res = solve(F-1, H+1);
    else if (F == 0) res = solve(F, H-1);
    else res = solve(F-1, H+1) + solve(F, H-1);

    return D[F][H] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        memset(D, -1, sizeof(D));
        D[0][0] = 1;
        ll res = solve(N, 0);
        cout << res << '\n';
    }

    return 0;
}
