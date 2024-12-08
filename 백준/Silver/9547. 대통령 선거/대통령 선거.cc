#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

pair<int,int> solve() {
    int C, V; cin >> C >> V;
    vector<vector<int>> P(V, vector<int>(C));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < C; j++) {
            int x; cin >> x;
            P[i][j] = --x;
        }
    }

    // 1회차
    vector<int> X(C);
    for (int i = 0; i < V; i++) {
        int k = P[i][0];
        X[k]++;
    }

    for (int i = 0; i < C; i++) {
        if (X[i] * 2 > V) return { i, 1 };
    }

    // 2회차
    int first = max_element(X.begin(), X.end()) - X.begin();
    X[first] = -1;
    
    int second = max_element(X.begin(), X.end()) - X.begin();
    X[second] = -1;

    vector<int> Y(C);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < C; j++) {
            int k = P[i][j];
            if (k == first || k == second) {
                Y[k]++;
                break;
            }
        }
    }

    int x = Y[first] > Y[second] ? first : second;
    return { x, 2 };
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        auto [x, i] = solve();
        cout << ++x << ' ' << i << '\n';
    }
    return 0;
}
