#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10000000;

string S;
bool P[MAX];

void sieve() {
    fill(P, P + MAX, true);
    P[0] = P[1] = false;

    for (long long i = 1; i < MAX; i++) {
        if (!P[i]) continue;
        
        for (long long j = i * i; j < MAX; j += i) {
            P[j] = false;
        }
    }
}

int solve(string S) {
    unordered_set<int> res;

    sort(S.begin(), S.end());
    do {
        int x = 0, mul = 1;

        for (char c : S) {
            x += (c - '0') * mul;
            mul *= 10;
            if (P[x]) res.insert(x);
        }
    } while (next_permutation(S.begin(), S.end()));

    return res.size();
}

int main() {
    FastIO
    sieve();

    int T; cin >> T;
    while (T--) {
        cin >> S;
        int ans = solve(S);
        cout << ans << '\n';
    }

    return 0;
}
