#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, L;
const int MAX = 10001;
pair<int,int> muds[MAX];

int main() {
    FastIO
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int S, E; cin >> S >> E;
        muds[i] = { S, E };
    }

    sort(muds, muds + N);

    int res = 0;
    int last = -1;

    for (int i = 0; i < N; i++) {
        const auto &p = muds[i];
        int S = p.first, E = p.second;
        if (E <= last) continue;

        S = max(last, S);
        int diff = E - S;
        int cnt = (diff + L - 1) / L;
        
        res += cnt;
        last = S + L * cnt;
    }

    cout << res << '\n';
    return 0;
}
