#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int N; cin >> N;
    
    int cnt = 0;
    vector<int> S(N + 1);
    vector<set<int>> T(10);

    for (int i = 1; i <= N; i++) {
        cin >> S[i];
        S[i] += S[i-1];
        T[S[i] % 10].insert(i);
    }
    
    for (int i = 1; i <= N; i++) {
        set<int> &X = T[S[i-1] % 10];
        auto iter = X.lower_bound(i);

        int res = -1;
        if (iter != X.end()) res = *iter - i + 1;
        cout << res << ' ';
    }
    cout << '\n';
    
    return 0;
}
