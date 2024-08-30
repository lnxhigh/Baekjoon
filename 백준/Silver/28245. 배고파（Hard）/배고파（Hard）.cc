#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

pair<int,int> solve(ll m) {
    int first = -1, second = -1, third = -1;
    for (int i = 60; i >= 0; i--) {
        if ((m & (1LL << i)) == 0) continue;

        if (first == -1) first = i;
        else if (second == -1) second = i;
        else if (third == -1) third = i;
    }
    
    if (first == 0) return { 0, 0 };
    else if (second == -1) return { first-1, first-1 };
    else if (third == -1) return { second, first };

    ll x = (1LL << first) + (1LL << second);
    ll y = (1LL << first) + (1LL << (second+1));
    
    if (abs(m - x) <= abs(m - y)) {
        return { second, first };
    }

    return { second + 1, first };
}

int main() {
    FastIO
    int N; cin >> N;
    while (N--) {
        ll M; cin >> M;
        auto p = solve(M);
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
