#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int64 lcm(const vector<int64> &v) {
    int64 x = 1;
    for (int64 k : v) x = lcm(x, k);
    return x;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int64 N; cin >> N;
        vector<vector<int64>> all = {
            { N, N - 1, N - 2 },
            { N, N - 1, N - 3 },
            { N, N - 1, N - 4 },
            { N, N - 2, N - 3 },
            { N - 1, N - 2, N - 3 },
        };

        int64 X = 0;
        for (const vector<int64> &xyz : all) {
            if (xyz.back() > 0) {
                X = max(X, lcm(xyz));
            }
        }

        cout << X << '\n';
    }
    
    return 0;
}
