#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 4;

int N;
int mp, mf, ms, mv;
tuple<int,int,int,int,int> Data[MAX];

bool compare(vector<int> &x, vector<int> &y) {
    int m = min(x.size(), y.size());
    for (size_t i = 0; i < m; i++) {
        if (x[i] != y[i]) return x[i] < y[i];
    }
    return x.size() < y.size();
}

int main() {
    FastIO
    cin >> N;
    cin >> mp >> mf >> ms >> mv;

    for (int i = 0; i < N; i++) {
        int p, f, s, v, c; cin >> p >> f >> s >> v >> c;
        Data[i] = { p, f, s, v, c };
    }

    vector<int> ans;
    int minCost = 1 << 30;

    for (int i = 1; i < (1 << N); i++) {
        int cp = 0, cf = 0, cs = 0, cv = 0, cc = 0;
        for (int k = 0; k < N; k++) {
            if ((i >> k & 1) == 0) continue;
            auto [p, f, s, v, c] = Data[k];
            cp += p, cf += f, cs += s, cv += v, cc += c;
        }

        if (cp < mp || cf < mf || cs < ms || cv < mv) continue;
        
        vector<int> tmp;
        for (int k = 0; k < N; k++) {
            if (i >> k & 1) tmp.push_back(k);
        }

        if (cc < minCost || (cc == minCost && compare(tmp, ans))) {
            ans = tmp, minCost = cc;
        }
    }

    if (ans.empty()) {
        cout << -1 << '\n';
    }
    else {
        cout << minCost << '\n';
        for (int x : ans) cout << x + 1 << ' ';
        cout << '\n';
    }

    return 0;
}
